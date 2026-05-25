#!/bin/bash
# One-click reproduction script
# Regenerates all CSV logs, figures, and evaluation results

# set -e

# echo "=== Installing dependencies ==="
# pip install -r ../requirements.txt

# echo "=== Cleaning old artifacts ==="
# rm -rf logs/ videos/ weights/

# echo "=== Baseline: Random agent ==="
# python train.py --config configs/dqn_baseline.yaml --agent random

# echo "=== Baseline: Heuristic agent ==="
# python ../train.py --config configs/dqn_baseline.yaml --agent heuristic

# echo "=== DQN training over 5 seeds ==="
# python train.py --config configs/dqn_baseline.yaml --agent dqn --seeds 0 1 2 3 4

# echo "=== Ablation studies ==="
# python scripts/ablation.py --config configs/dqn_baseline.yaml --seeds 0 1 2 3 4

# echo "=== Generating plots ==="
# python scripts/plots_results.py

# echo "=== Evaluation ==="
# python eval.py --model weights/dqn_seed0_final.pth --episodes 100

# echo "=== Done ==="
# echo "Results in: logs/ logs/plots/ weights/ videos/"

#!/bin/bash

# Arrête le script en cas d'erreur
set -e

# Se place à la racine du projet peu importe d'où le script est lancé
cd "$(dirname "$0")/.."

echo "--- Installing dependencies ---"
pip install -r requirements.txt

echo "--- Cleaning old artifacts ---"
rm -f logs/*.csv 2>/dev/null || true
rm -rf logs/plots/ videos/ weights/

echo "--- Baseline: Random agent ---"
python3 train.py --config configs/dqn_baseline.yaml --agent random

echo "--- Baseline: Heuristic agent ---"
python3 train.py --config configs/dqn_baseline.yaml --agent heuristic

echo "--- DQN training over 5 seeds ---"
for seed in 0 1 2 3 4; do
    echo "Training seed $seed..."
    python3 train.py --config configs/dqn_baseline.yaml --agent dqn --seeds "$seed"
done

echo "--- Video recording test (heuristic) ---"
python3 -c "
import yaml
from src.utils.videos import record_episodes
from src.agents.heuristic_agents import heuristic_policy
with open('configs/dqn_baseline.yaml') as f:
    cfg = yaml.safe_load(f)
record_episodes(cfg, 'heuristic', heuristic_policy, n_episodes=2)
"

echo "--- Video recording test (random) ---"
python3 -c "
import yaml
from src.utils.videos import record_episodes
with open('configs/dqn_baseline.yaml') as f:
    cfg = yaml.safe_load(f)
record_episodes(cfg, 'random', None, n_episodes=2)
"

# echo "--- Ablation studies ---"
# python3 scripts/ablation.py --config configs/dqn_baseline.yaml --seeds 0 1 2 3 4
#
# echo "--- Generating plots ---"
# python3 scripts/plots_results.py
#
# echo "--- Evaluation ---"
# python3 eval.py --model weights/dqn_seed0_final.pth --episodes 100

echo "--- Done ---"
echo "Results in: logs/, videos/"
