# Star Trek - LunarLander RL Project

Projet d'apprentissage par renforcement implémentant des agents pour résoudre l'environnement **LunarLander-v3** de Gymnasium.

## Structure du Projet

```
.
├── configs/
│   ├── dqn_baseline.yaml       # Configuration DQN standard
│   └── dqn_ablation.yaml       # Configurations pour les ablations
├── logs/
│   └── logger.py               # Utilitaires de logging
├── scripts/
│   ├── ablation.py             # Script d'étude d'ablation
│   ├── plots_results.py        # Visualisation avec mean ± 95% CI
│   └── repro.sh                # Script de reproduction one-click
├── src/
│   ├── agents/
│   │   ├── dqn_agent.py        # Agent DQN (Replay Buffer + Target Net)
│   │   ├── heuristic_agents.py # Agent heuristique
│   │   └── random_agents.py    # Agent aléatoire
│   ├── networks/
│   │   └── mlp.py              # MLP (3 couches ReLU: 256→128→64)
│   └── utils/
│       ├── termination.py      # Analyse raisons de fin
│       └── videos.py           # Enregistrement vidéo
├── train.py                    # Script d'entraînement
├── eval.py                     # Script d'évaluation
├── test-env.py                 # Test environnement
├── requirements.txt
├── rapport.md                  # Rapport de 4-6 pages
└── README.md
```

## Installation

### 1. Créer et activer l'environnement virtuel

```bash
sudo apt update
sudo apt install python3-pip python3-venv
python3 -m venv .venv
source .venv/bin/activate
```

### 2. Installer les dépendances

```bash
pip install -r requirements.txt
```

### 3. Vérifier l'installation

```bash
python test-env.py
```

## Tests

Le projet inclut une suite de tests complète couvrant tous les composants
du cahier des charges (baselines, agent DQN, logging, vidéos, reproductibilité).

### Suite complète (14 tests)

```bash
python test_all.py
```

Ce script exécute les tests suivants (conformément au sujet) :

| # | Test | Description |
|---|------|-------------|
| 1 | Environment creation | Vérifie que `LunarLander-v3` se crée avec obs=(8,) et 4 actions |
| 2 | Random agent basic | 3 episodes avec l'agent aléatoire, pas de crash |
| 3 | Heuristic agent basic | 3 episodes avec l'agent heuristique, pas de crash |
| 4 | Random agent + logging | Vérifie que returns, episode length et **termination reason** (crash/out-of-view/sleep/timeout) sont loggés dans `logs/random.csv` |
| 5 | Heuristic agent + logging | Idem pour `logs/heuristic.csv` |
| 6 | DQN network (MLP) | MLP 3 couches ReLU [256, 128, 64] → forward pass (16,4) |
| 7 | ReplayBuffer | push/sample, capacité, formes des tenseurs |
| 8 | DQNAgent components | init, act, step, epsilon decay, save/load |
| 9 | DQN short training | 3 episodes pour vérifier la boucle step/learn |
| 10 | Termination reasons | Vérifie les 4 raisons : sleep, crash, out-of-view, timeout |
| 11 | Video recording | Enregistrement vidéo (1 épisode heuristique) + vérifie fichier .mp4 non vide |
| 12 | Reproducibility | Même seed → mêmes returns (déterministe, epsilon=0) |
| 13 | YAML config | Vérifie le chargement de `configs/dqn_baseline.yaml` |
| 14 | eval.py script | Vérifie que `eval.py --help` fonctionne |

### Tester un agent spécifique

```bash
# Agent aléatoire (500 episodes)
python train.py --config configs/dqn_baseline.yaml --agent random

# Agent heuristique (500 episodes)
python train.py --config configs/dqn_baseline.yaml --agent heuristic

# Agent DQN (1 seed, 500 episodes)
python train.py --config configs/dqn_baseline.yaml --agent dqn --seeds 0

# Agent DQN (5 seeds pour reproductibilité)
python train.py --config configs/dqn_baseline.yaml --agent dqn --seeds 0 1 2 3 4
```

### Tester l'enregistrement vidéo

```bash
python -c "
from src.utils.videos import record_episodes
from src.agents.heuristic_agents import heuristic_policy
record_episodes({'env': {'name': 'LunarLander-v3'}, 'run': {'seed': 0}}, 'heuristic', heuristic_policy, n_episodes=3)
"
```

Les vidéos sont sauvegardées dans `videos/heuristic_<timestamp>/`.

### Tester les raisons de terminaison

Les 4 raisons (crash, out-of-view, sleep, timeout) sont loggées automatiquement
dans les fichiers CSV (`logs/random.csv`, `logs/heuristic.csv`, `logs/dqn_seed*.csv`)
via la colonne `termination_reason`.

### Tester la reproductibilité

```bash
# Avec le même seed et epsilon=0, les returns sont identiques
python -c "
import gymnasium as gym
from src.agents.dqn_agent import DQNAgent
a1 = DQNAgent(); a2 = DQNAgent()
a1.epsilon = 0; a2.epsilon = 0
env = gym.make('LunarLander-v3')
for _ in range(3):
    obs, _ = env.reset(seed=0)
    print([a1.act(obs, eval_mode=True) for _ in range(10)])
    env.close()
"
```

### One-click repro (intégration)

```bash
bash scripts/repro.sh
```

Ce script régénère **tous les artefacts** (logs CSV, poids, vidéos, graphiques)
et vérifie que les résultats sont reproductibles à ±5% près avec les mêmes seeds.<｜end▁of▁thinking｜>

## Utilisation

### Entraînement

```bash
# Agent aléatoire (baseline)
python train.py --config configs/dqn_baseline.yaml --agent random

# Agent heuristique (baseline)
python train.py --config configs/dqn_baseline.yaml --agent heuristic

# Agent DQN (1 seed)
python train.py --config configs/dqn_baseline.yaml --agent dqn --seeds 0

# Agent DQN (5 seeds pour stats)
python train.py --config configs/dqn_baseline.yaml --agent dqn --seeds 0 1 2 3 4
```

### Évaluation

```bash
python eval.py --model weights/dqn_seed0_final.pth --episodes 100
```

### Ablation Studies

```bash
python scripts/ablation.py --config configs/dqn_baseline.yaml --seeds 0 1 2 3 4
```

Ablations disponibles :
- `buffer_size_small` : Buffer de 10000 au lieu de 100000
- `buffer_size_large` : Buffer de 500000 au lieu de 100000
- `target_hard` : Mise à jour hard (tous les 100 steps) au lieu de soft
- `target_soft` : Mise à jour soft explicite (tau=0.001)
- `obs_norm` : Normalisation des observations

### Génération des graphiques

```bash
python scripts/plots_results.py
```

Graphiques générés dans `logs/plots/` :
- `dqn_returns_ci.png` : Courbe d'apprentissage mean ± 95% CI
- `dqn_epsilon.png` : Décroissance d'epsilon
- `dqn_loss.png` : Évolution de la loss
- `dqn_terminations.png` : Statistiques de terminaison
- `agent_comparison.png` : Comparaison Random vs Heuristic vs DQN

### Reproduction complète

```bash
bash scripts/repro.sh
```

## Agents

### Random Agent
- Actions aléatoires (baseline minimale)

### Heuristic Agent
- Règles manuelles : jambes au sol → repos, inclinaison → correction, chute → moteur

### DQN Agent
- MLP 3 couches [256, 128, 64] avec ReLU
- Replay Buffer (taille configurable)
- Target Network (soft/hard update)
- Epsilon-greedy avec decay
- 5 seeds, résultats avec mean ± 95% CI

## Ablation Studies

| Ablation | Variable | Variation |
|----------|----------|-----------|
| Buffer size | `buffer_size` | 10000 vs 100000 vs 500000 |
| Target update | `target_update` | soft (tau=0.001) vs hard (every 100 steps) |
| Observation norm | `normalize_obs` | Running mean/std normalization |

## Résultats Attendus

- Random : ~-100 à -200 (ne réussit jamais)
- Heuristic : ~-50 à 100 (atterrit parfois)
- DQN : ~200+ après 300-500 episodes (atterrissage réussi)

## Rapport

Voir `rapport.md` pour le rapport complet (4-6 pages) incluant setup, résultats, limites et prochaines étapes.
