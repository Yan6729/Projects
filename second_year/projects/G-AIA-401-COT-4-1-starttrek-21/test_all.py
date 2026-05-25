import gymnasium as gym
import numpy as np
import os
import shutil
import sys
import torch
import csv
import yaml
import subprocess

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from src.agents.random_agents import random_policy
from src.agents.heuristic_agents import heuristic_policy
from src.agents.dqn_agent import DQNAgent, ReplayBuffer
from src.networks.mlp import DQNNetwork
from src.utils.termination import get_termination_reason
from src.utils.videos import record_episodes
from train import run_baseline, run_dqn

N_TEST_EPISODES = 3
ENV_NAME = "LunarLander-v3"
SEED = 42
BASE_CONFIG = "configs/dqn_baseline.yaml"


def test_environment():
    print("[TEST] Environment creation ... ", end="")
    env = gym.make(ENV_NAME)
    obs, info = env.reset(seed=SEED)
    assert obs.shape == (8,), f"Expected obs shape (8,), got {obs.shape}"
    assert env.action_space.n == 4, f"Expected 4 actions, got {env.action_space.n}"
    env.close()
    print("OK")


def test_random_agent():
    print("[TEST] Random agent (3 episodes) ... ", end="")
    env = gym.make(ENV_NAME)
    for ep in range(N_TEST_EPISODES):
        obs, _ = env.reset(seed=SEED + ep)
        total = 0.0
        done = False
        while not done:
            action = random_policy(obs, env)
            assert 0 <= action < 4, f"Invalid action {action}"
            obs, reward, terminated, truncated, _ = env.step(action)
            total += reward
            done = terminated or truncated
    env.close()
    print("OK")


def test_heuristic_agent():
    print("[TEST] Heuristic agent (3 episodes) ... ", end="")
    env = gym.make(ENV_NAME)
    for ep in range(N_TEST_EPISODES):
        obs, _ = env.reset(seed=SEED + ep)
        total = 0.0
        done = False
        while not done:
            action = heuristic_policy(obs)
            assert 0 <= action < 4, f"Invalid action {action}"
            obs, reward, terminated, truncated, _ = env.step(action)
            total += reward
            done = terminated or truncated
    env.close()
    print("OK")


def test_random_agent_logging():
    print("[TEST] Random agent with logging (returns, length, termination) ... ", end="")
    log_path = "logs/random.csv"
    with open(BASE_CONFIG) as f:
        cfg = yaml.safe_load(f)
    cfg["run"]["n_episodes"] = 5
    tmp_cfg = "/tmp/test_random_config.yaml"
    with open(tmp_cfg, "w") as f:
        yaml.dump(cfg, f)
    if os.path.exists(log_path):
        os.remove(log_path)
    run_baseline(tmp_cfg, agent_type="random")
    assert os.path.exists(log_path), f"Log not found at {log_path}"
    with open(log_path) as f:
        reader = csv.DictReader(f)
        rows = list(reader)
    assert len(rows) == 5, f"Expected 5 log rows, got {len(rows)}"
    expected_fields = {"episode", "total_return", "episode_length", "termination_reason"}
    assert expected_fields.issubset(rows[0].keys()), f"Missing fields in log: {rows[0].keys()}"
    for row in rows:
        assert row["termination_reason"] in ("crash", "out-of-view", "sleep", "timeout"), \
            f"Unknown reason: {row['termination_reason']}"
        assert float(row["total_return"]) >= -1000
        assert int(row["episode_length"]) > 0
    os.remove(log_path)
    os.remove(tmp_cfg)
    print(f"OK ({len(rows)} episodes logged)")


def test_heuristic_agent_logging():
    print("[TEST] Heuristic agent with logging (returns, length, termination) ... ", end="")
    log_path = "logs/heuristic.csv"
    with open(BASE_CONFIG) as f:
        cfg = yaml.safe_load(f)
    cfg["run"]["n_episodes"] = 5
    tmp_cfg = "/tmp/test_heuristic_config.yaml"
    with open(tmp_cfg, "w") as f:
        yaml.dump(cfg, f)
    if os.path.exists(log_path):
        os.remove(log_path)
    run_baseline(tmp_cfg, agent_type="heuristic")
    assert os.path.exists(log_path), f"Log not found at {log_path}"
    with open(log_path) as f:
        reader = csv.DictReader(f)
        rows = list(reader)
    assert len(rows) == 5, f"Expected 5 log rows, got {len(rows)}"
    for row in rows:
        assert row["termination_reason"] in ("crash", "out-of-view", "sleep", "timeout")
    os.remove(log_path)
    os.remove(tmp_cfg)
    print(f"OK ({len(rows)} episodes logged)")


def test_dqn_network():
    print("[TEST] DQNNetwork forward pass (3-layer ReLU MLP) ... ", end="")
    net = DQNNetwork(state_size=8, action_size=4)
    params = list(net.parameters())
    assert len(params) > 0, "No parameters in network"
    batch = torch.randn(16, 8)
    out = net(batch)
    assert out.shape == (16, 4), f"Expected (16,4), got {out.shape}"
    assert net.fc1.out_features == 256
    assert net.fc2.out_features == 128
    assert net.fc3.out_features == 64
    print("OK")


def test_replay_buffer():
    print("[TEST] ReplayBuffer (push, sample, capacity) ... ", end="")
    buf = ReplayBuffer(capacity=100)
    for i in range(50):
        buf.push(
            np.zeros(8, dtype=np.float32), i % 4, float(i),
            np.ones(8, dtype=np.float32), False,
        )
    assert len(buf) == 50, f"Expected 50, got {len(buf)}"
    states, actions, rewards, next_states, dones = buf.sample(16)
    assert states.shape == (16, 8), f"states shape: {states.shape}"
    assert actions.shape == (16,), f"actions shape: {actions.shape}"
    assert rewards.shape == (16,), f"rewards shape: {rewards.shape}"
    assert next_states.shape == (16, 8), f"next_states shape: {next_states.shape}"
    assert dones.shape == (16,), f"dones shape: {dones.shape}"
    print("OK")


def test_dqn_agent_components():
    print("[TEST] DQNAgent (init, act, step, epsilon decay, save/load) ... ", end="")
    agent = DQNAgent(state_size=8, action_size=4)
    assert agent.action_size == 4
    assert agent.state_size == 8
    assert agent.epsilon == 1.0
    assert agent.target_update == "soft"
    assert agent.tau == 1e-3
    state = np.random.randn(8).astype(np.float32)
    action = agent.act(state)
    assert 0 <= action < 4, f"Invalid action {action}"
    next_state = np.random.randn(8).astype(np.float32)
    loss = agent.step(state, action, 1.0, next_state, False)
    agent.decay_epsilon()
    assert agent.epsilon < 1.0, "Epsilon did not decay"
    tmp_path = "/tmp/test_dqn_agent.pth"
    agent.save(tmp_path)
    assert os.path.exists(tmp_path), "Save file not found"
    agent2 = DQNAgent(state_size=8, action_size=4)
    agent2.load(tmp_path)
    assert agent2.epsilon == agent.epsilon, "Epsilon not restored"
    os.remove(tmp_path)
    print("OK")


def test_dqn_training_short():
    print("[TEST] DQN short training (3 episodes, verifies step/learn loop) ... ", end="")
    env = gym.make(ENV_NAME)
    agent = DQNAgent(state_size=8, action_size=4)
    for ep in range(N_TEST_EPISODES):
        obs, _ = env.reset(seed=SEED + ep)
        total = 0.0
        done = False
        while not done:
            action = agent.act(obs)
            next_obs, reward, terminated, truncated, _ = env.step(action)
            done = terminated or truncated
            agent.step(obs, action, reward, next_obs, done)
            obs = next_obs
            total += reward
        agent.decay_epsilon()
    env.close()
    print("OK")


def test_termination_reasons():
    print("[TEST] Termination reasons (sleep, crash, out-of-view, timeout) ... ", end="")
    assert get_termination_reason(None, False, True) == "timeout"
    assert get_termination_reason(None, False, False) == "running"
    obs_sleep = np.array([0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0])
    assert get_termination_reason(obs_sleep, True, False) == "sleep"
    obs_crash = np.array([0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0])
    assert get_termination_reason(obs_crash, True, False) == "crash"
    obs_oov = np.array([2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0])
    assert get_termination_reason(obs_oov, True, False) == "out-of-view"
    print("OK")


def test_video_recording():
    print("[TEST] Video recording (heuristic agent, 1 episode) ... ", end="")
    config = {
        "env": {"name": ENV_NAME},
        "run": {"seed": SEED},
    }
    videos_dir = "videos"
    if os.path.exists(videos_dir):
        shutil.rmtree(videos_dir)
    record_episodes(config, "heuristic", heuristic_policy, n_episodes=1)
    dirs = [d for d in os.listdir(videos_dir) if d.startswith("heuristic_")]
    assert len(dirs) > 0, "No video directory created"
    video_dir = os.path.join(videos_dir, dirs[0])
    mp4_files = [f for f in os.listdir(video_dir) if f.endswith(".mp4")]
    assert len(mp4_files) > 0, f"No .mp4 files in {video_dir}"
    mp4_path = os.path.join(video_dir, mp4_files[0])
    assert os.path.getsize(mp4_path) > 1000, f"Video file too small: {os.path.getsize(mp4_path)} bytes"
    shutil.rmtree(videos_dir)
    print("OK")


def test_reproducibility():
    print("[TEST] Reproducibility (same seed → same deterministic returns) ... ", end="")
    import random as rnd
    rnd.seed(0)
    torch.manual_seed(0)
    env = gym.make(ENV_NAME)
    agent = DQNAgent(state_size=8, action_size=4)
    agent.epsilon = 0.0
    returns_1 = []
    for ep in range(3):
        obs, _ = env.reset(seed=0)
        total = 0.0
        done = False
        while not done:
            action = agent.act(obs, eval_mode=True)
            obs, reward, terminated, truncated, _ = env.step(action)
            total += reward
            done = terminated or truncated
        returns_1.append(total)
    env.close()
    rnd.seed(0)
    torch.manual_seed(0)
    env = gym.make(ENV_NAME)
    agent2 = DQNAgent(state_size=8, action_size=4)
    agent2.epsilon = 0.0
    returns_2 = []
    for ep in range(3):
        obs, _ = env.reset(seed=0)
        total = 0.0
        done = False
        while not done:
            action = agent2.act(obs, eval_mode=True)
            obs, reward, terminated, truncated, _ = env.step(action)
            total += reward
            done = terminated or truncated
        returns_2.append(total)
    env.close()
    for r1, r2 in zip(returns_1, returns_2):
        assert abs(r1 - r2) < 1e-6, f"Returns differ: {r1} vs {r2}"
    print("OK")


def test_yaml_config():
    print("[TEST] YAML config loading ... ", end="")
    with open(BASE_CONFIG) as f:
        cfg = yaml.safe_load(f)
    assert cfg["env"]["name"] == "LunarLander-v3"
    assert cfg["run"]["n_episodes"] == 500
    assert cfg["agent"]["type"] == "dqn"
    assert cfg["agent"]["learning_rate"] == 0.001
    assert cfg["agent"]["gamma"] == 0.99
    assert cfg["agent"]["buffer_size"] == 100000
    assert cfg["agent"]["epsilon_start"] == 1.0
    assert cfg["agent"]["epsilon_end"] == 0.01
    assert cfg["agent"]["epsilon_decay"] == 0.995
    print("OK")


def test_eval_script():
    print("[TEST] eval.py help (script runs without model) ... ", end="")
    result = subprocess.run(
        [sys.executable, "eval.py", "--help"],
        capture_output=True, text=True,
    )
    assert result.returncode == 0, f"eval.py --help failed: {result.stderr}"
    assert "--model" in result.stdout
    assert "--episodes" in result.stdout
    print("OK")


if __name__ == "__main__":
    tests = [
        ("Environment creation", test_environment),
        ("Random agent basic", test_random_agent),
        ("Heuristic agent basic", test_heuristic_agent),
        ("Random agent with logging", test_random_agent_logging),
        ("Heuristic agent with logging", test_heuristic_agent_logging),
        ("DQN 3-layer MLP network", test_dqn_network),
        ("ReplayBuffer", test_replay_buffer),
        ("DQNAgent components", test_dqn_agent_components),
        ("DQN short training loop", test_dqn_training_short),
        ("Termination reasons", test_termination_reasons),
        ("Video recording", test_video_recording),
        ("Reproducibility (seeds)", test_reproducibility),
        ("YAML config", test_yaml_config),
        ("eval.py script", test_eval_script),
    ]

    passed = 0
    failed = 0
    for name, func in tests:
        try:
            func()
            passed += 1
        except Exception as e:
            print(f"FAILED: {e}")
            failed += 1

    print(f"\n{'='*45}")
    print(f"Results: {passed}/{len(tests)} passed, {failed} failed")
    if failed > 0:
        sys.exit(1)
    else:
        print("All tests passed!")
