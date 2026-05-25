import gymnasium as gym
import yaml
import argparse
import os
import numpy as np
import torch
from src.agents.random_agents import random_policy
from src.agents.heuristic_agents import heuristic_policy
from src.agents.dqn_agent import DQNAgent
from logs.logger import init_logger, log_episode
from src.utils.termination import get_termination_reason


def run_baseline(config_path, agent_type="random"):
    with open(config_path) as f:
        cfg = yaml.safe_load(f)

    env = gym.make(cfg["env"]["name"], render_mode=cfg["env"].get("render_mode", "rgb_array"))
    log_file, writer = init_logger(f"logs/{agent_type}.csv")

    for episode in range(cfg["run"]["n_episodes"]):
        obs, info = env.reset(seed=cfg["run"]["seed"] + episode)
        total_return = 0.0
        length = 0
        reason = "running"

        while True:
            if agent_type == "random":
                action = random_policy(obs, env)
            else:
                action = heuristic_policy(obs)

            obs, reward, terminated, truncated, info = env.step(action)
            total_return += reward
            length += 1

            if terminated or truncated:
                reason = get_termination_reason(obs, terminated, truncated)
                log_episode(writer, episode, total_return, length, reason)
                print(f"[{agent_type}] ep={episode:03d} | return={total_return:7.2f} | len={length} | {reason}")
                break

    log_file.close()
    env.close()


def run_dqn(config_path, seed=0):
    with open(config_path) as f:
        cfg = yaml.safe_load(f)

    env = gym.make(cfg["env"]["name"], render_mode=cfg["env"].get("render_mode", "rgb_array"))
    state_size = env.observation_space.shape[0]
    action_size = env.action_space.n

    agent_cfg = cfg["agent"]
    agent = DQNAgent(
        state_size=state_size,
        action_size=action_size,
        lr=agent_cfg["learning_rate"],
        gamma=agent_cfg["gamma"],
        buffer_size=agent_cfg["buffer_size"],
        batch_size=agent_cfg["batch_size"],
        tau=agent_cfg.get("tau", 1e-3),
        target_update=agent_cfg.get("target_update", "soft"),
        update_freq=agent_cfg.get("update_freq", 100),
        epsilon_start=agent_cfg["epsilon_start"],
        epsilon_end=agent_cfg["epsilon_end"],
        epsilon_decay=agent_cfg["epsilon_decay"],
    )

    normalize = agent_cfg.get("normalize_obs", False)
    if normalize:
        obs_rms_mean = np.zeros(state_size, dtype=np.float32)
        obs_rms_var = np.ones(state_size, dtype=np.float32)
        obs_rms_count = 1e-4

    os.makedirs("weights", exist_ok=True)
    log_file, writer = init_logger(f"logs/dqn_seed{seed}.csv")
    n_episodes = cfg["run"]["n_episodes"]
    best_reward = -float("inf")

    for episode in range(n_episodes):
        obs, info = env.reset(seed=seed + episode)
        total_return = 0.0
        length = 0
        episode_loss = 0.0
        loss_count = 0

        while True:
            if normalize:
                obs_rms_count += 1
                delta = obs - obs_rms_mean
                obs_rms_mean += delta / obs_rms_count
                delta2 = obs - obs_rms_mean
                obs_rms_var += delta * delta2
                std = np.sqrt(obs_rms_var / obs_rms_count)
                norm_obs = np.clip((obs - obs_rms_mean) / (std + 1e-8), -5, 5)
            else:
                norm_obs = obs

            action = agent.act(norm_obs)
            next_obs, reward, terminated, truncated, info = env.step(action)
            done = terminated or truncated

            if normalize:
                next_norm = np.clip((next_obs - obs_rms_mean) / (np.sqrt(obs_rms_var / obs_rms_count) + 1e-8), -5, 5)
            else:
                next_norm = next_obs

            loss = agent.step(norm_obs, action, reward, next_norm, done)
            if loss is not None:
                episode_loss += loss
                loss_count += 1

            obs = next_obs
            total_return += reward
            length += 1

            if done:
                reason = get_termination_reason(obs, terminated, truncated)
                avg_loss = episode_loss / max(loss_count, 1)
                log_episode(writer, episode, total_return, length, reason,
                           loss=avg_loss, epsilon=agent.epsilon)
                print(f"[DQN] seed={seed} ep={episode:03d} | return={total_return:7.2f} "
                      f"| len={length} | loss={avg_loss:.4f} | eps={agent.epsilon:.3f} | {reason}")
                break

        agent.decay_epsilon()
        if total_return > best_reward:
            best_reward = total_return
            agent.save(f"weights/dqn_seed{seed}_best.pth")

    agent.save(f"weights/dqn_seed{seed}_final.pth")
    log_file.close()
    env.close()
    return best_reward


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--config", default="configs/dqn_baseline.yaml")
    parser.add_argument("--agent", default="dqn", choices=["random", "heuristic", "dqn"])
    parser.add_argument("--seeds", nargs="+", type=int, default=[0])
    args = parser.parse_args()

    if args.agent == "dqn":
        for seed in args.seeds:
            print(f"\n=== Training DQN with seed={seed} ===")
            run_dqn(args.config, seed=seed)
    else:
        run_baseline(args.config, args.agent)
