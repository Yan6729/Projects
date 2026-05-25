##
## EPITECH PROJECT, 2026
## G-AIA-401-COT-4-1-starttrek-21
## File description:
## ablation
##

import sys
import os
import csv
import copy
import argparse
import numpy as np
import gymnasium as gym
import yaml

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from src.agents.dqn_agent import DQNAgent
from logs.logger import init_logger, log_episode
from src.utils.termination import get_termination_reason

ABLATIONS = {
    "buffer_10k": {
        "description": "Buffer size = 10 000",
        "agent_overrides": {"buffer_size": 10000},
    },
    "buffer_100k": {
        "description": "Buffer size = 100 000 (baseline)",
        "agent_overrides": {"buffer_size": 100000},
    },
    "buffer_500k": {
        "description": "Buffer size = 500 000",
        "agent_overrides": {"buffer_size": 500000},
    },
    "target_soft": {
        "description": "Soft target update t=0.001 (baseline)",
        "agent_overrides": {"target_update": "soft", "tau": 0.001},
    },
    "target_hard": {
        "description": "Hard target update every 100 steps",
        "agent_overrides": {"target_update": "hard", "update_freq": 100},
    },
    "obs_no_norm": {
        "description": "No observation normalisation (baseline)",
        "agent_overrides": {"normalize_obs": False},
    },
    "obs_norm": {
        "description": "Online observation normalisation (running mean/var)",
        "agent_overrides": {"normalize_obs": True},
    },
}

SEEDS = [0, 1, 2, 3, 4]

def merge(base: dict, override: dict):
    """Shallow-merge overrides into a copy of base."""
    merged = copy.deepcopy(base)
    merged.update(override)
    return merged
    
def normalise(obs, mean, var, count):
    """Update running stats and return normalised observation."""
    count += 1
    delta = obs - mean
    mean = mean + delta / count
    delta2 = obs - mean
    var = var + delta * delta2
    std = np.sqrt(var / count)
    norm = np.clip((obs - mean) / (std + 1e-8), -5.0, 5.0)
    return norm, mean, var, count

def run_ablation(ablation_name: str, agent_cfg: dict, env_cfg: dict, run_cfg: dict, seed: int):
    """
    Train one DQN variant for one seed.
    Returns a list of per-episode dicts (episode, total_return, …).
    """
    env = gym.make(env_cfg["name"], render_mode=env_cfg.get("render_mode", "rgb_array"))
    state_size = env.observation_space.shape[0]
    action_size = env.action_space.n
 
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
        obs_mean = np.zeros(state_size, dtype=np.float32)
        obs_var = 0
        obs_count = 1e-4
 
    n_episodes = run_cfg["n_episodes"]
    records = []
 
    for episode in range(n_episodes):
        obs, _ = env.reset(seed=seed + episode)
        total_return = 0.0
        length = 0
        ep_loss = 0.0
        loss_count = 0
 
        while True:
            if normalize:
                norm_obs, obs_mean, obs_var, obs_count = normalise(obs, obs_mean, obs_var, obs_count)
            else:
                norm_obs = obs
 
            action = agent.act(norm_obs)
            next_obs, reward, terminated, truncated, _ = env.step(action)
            done = terminated or truncated 
            if normalize:
                next_norm, obs_mean, obs_var, obs_count = normalise(next_obs, obs_mean, obs_var, obs_count)
            else:
                next_norm = next_obs
 
            loss = agent.step(norm_obs, action, reward, next_norm, done)
            if loss is not None:
                ep_loss += loss
                loss_count += 1
 
            obs = next_obs
            total_return += reward
            length += 1
 
            if done:
                reason = get_termination_reason(obs, terminated, truncated)
                avg_loss = ep_loss / max(loss_count, 1)
                records.append({
                    "ablation": ablation_name,
                    "seed": seed,
                    "episode": episode,
                    "total_return": round(total_return, 3),
                    "episode_length": length,
                    "termination_reason": reason,
                    "loss": round(avg_loss, 6),
                    "epsilon": round(agent.epsilon, 4),
                })
                print(f"  [ablation={ablation_name} seed={seed}] ep={episode:03d} | return={total_return:7.2f} | {reason} | eps={agent.epsilon:.3f}")
                break
        agent.decay_epsilon()

    env.close()
    return records

def write_summary(all_records: list[dict], path: str):
    """
    Aggregate per-episode records into a per-ablation summary:
    mean ± std of the last-100-episode returns across seeds.
    """
    from collections import defaultdict
    grouped = defaultdict(list)
    seed_means = defaultdict(list)
    for rec in all_records:
        key = (rec["ablation"], rec["seed"])
        seed_means[key].append(rec["total_return"])
 
    for (ablation, seed), returns in seed_means.items():
        last100 = returns[-100:]
        grouped[ablation].append(np.mean(last100))
 
    os.makedirs(os.path.dirname(path) or ".", exist_ok=True)
    with open(path, "w", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=[
            "ablation", "description",
            "mean_last100", "std_last100", "ci95_last100",
            "n_seeds",
        ])
        writer.writeheader()
        for ablation_name, means in sorted(grouped.items()):
            arr = np.array(means)
            n = len(arr)
            ci95 = 1.96 * arr.std() / np.sqrt(n) if n > 1 else 0.0
            writer.writerow({
                "ablation": ablation_name,
                "description": ABLATIONS[ablation_name]["description"],
                "mean_last100": round(arr.mean(), 3),
                "std_last100": round(arr.std(), 3),
                "ci95_last100": round(ci95, 3),
                "n_seeds": n,
            })
    print(f"\n[summary] Written to {path}")

def main():
    parser = argparse.ArgumentParser(
        description="Run all the ablation studies for the startTrek project / LunarLender-v3"
    )
    parser.add_argument("--config", default="configs/dqn_ablation.yaml", help="Base YAML config (env + agent hyperparameters)")
    parser.add_argument("--seed", nargs="+", type=int, default=SEEDS, help="List of seeds to use (0, 1, 2, 3, 4)")
    parser.add_argument("--out-dir", default="logs/ablations", help="Directory where per-run CSV files are saved")
    parser.add_argument("--ablations", nargs="+", default=None, help="Run only the named ablations (default: all)")
    args = parser.parse_args()

    with open(args.config) as f:
        base_cfg = yaml.safe_load(f)

    ablations_names = args.ablations if args.ablations else list(ABLATIONS.keys())
    os.makedirs(args.out_dir, exist_ok=True)

    all_records: list[dict] = []
    for name in ablations_names:
        if name not in ABLATIONS:
            print(f"Unknow ablations {name}")
            continue
        print(f"\n{'-'*42}")
        print(f"Abblation {name} - {ABLATIONS[name]['description']}")
        print(f"{'-'*42}")
        agent_cfg = merge(base_cfg["agent"], ABLATIONS[name]["agent_overrides"])
        run_records: list[dict] = []
        for seed in args.seed:
            print(f"\n--- seed={seed} ---")
            records = run_ablation(name, agent_cfg, base_cfg["env"], base_cfg["run"], seed)
            run_records.extend(records)
        per_ablation_path = os.path.join(args.out_dir, f"{name}.csv")
        fieldnames = ["ablation", "seed", "episode", "total_return", "episode_length", "termination_reason", "loss", "epsilon"]
        with open(per_ablation_path, "w", newline="") as f:
            writer = csv.DictWriter(f, fieldnames=fieldnames)
            writer.writeheader()
            writer.writerows(run_records)
        print(f"[saved] {per_ablation_path}") 
        all_records.extend(run_records)
    write_summary(all_records, os.path.join(args.out_dir, "summary.csv"))
    print("\nAll ablations done.")

if __name__ == "__main__":
    main()