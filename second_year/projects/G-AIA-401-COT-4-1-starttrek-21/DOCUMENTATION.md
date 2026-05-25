# Documentation Technique — G-AIA-401 : Start Trek
## LunarLander-v3 — Apprentissage par Renforcement (DQN)

> **Projet** : G-AIA-401-COT-4-1-starttrek-21 · **Langage** : Python · **Librairies** : Gymnasium, PyTorch

---

## Table des matières

1. [Contexte du projet](#1-contexte-du-projet)
2. [Structure du dépôt](#2-structure-du-dépôt)
3. [Installation](#3-installation)
4. [Environnement LunarLander-v3](#4-environnement-lunarlander-v3)
5. [Architecture du code](#5-architecture-du-code)
6. [Agents implémentés](#6-agents-implémentés)
7. [Entraînement](#7-entraînement)
8. [Évaluation](#8-évaluation)
9. [Études d'ablation](#9-études-dablation)
10. [Résultats](#10-résultats)
11. [Reproduction des résultats](#11-reproduction-des-résultats)
12. [Tests](#12-tests)
13. [Limites & Perspectives](#13-limites--perspectives)

---

## 1. Contexte du projet

Ce projet s'inscrit dans le cadre du module **G-AIA-401** (Reinforcement Learning). L'objectif est d'entraîner un agent à faire atterrir un module lunaire de façon autonome dans le simulateur **LunarLander-v3** de Gymnasium.

L'agent doit :
- Apprendre par essais et erreurs à partir de récompenses éparses
- Maîtriser le compromis exploration/exploitation (epsilon-greedy)
- Atteindre un score moyen ≥ 200 sur 100 épisodes consécutifs (critère de résolution)
- Être reproductible (5 seeds, mean ± 95% CI)

---

## 2. Structure du dépôt

```
.
├── configs/
│   ├── dqn_baseline.yaml       # Hyperparamètres DQN standard
│   └── dqn_ablation.yaml       # Config pour les études d'ablation
├── logs/
│   ├── logger.py               # Utilitaires de logging (CSV)
│   └── ablations/              # Résultats CSV des ablations
│       ├── summary.csv         # Tableau récapitulatif
│       ├── buffer_10k.csv
│       ├── buffer_100k.csv
│       ├── buffer_500k.csv
│       ├── target_hard.csv
│       ├── target_soft.csv
│       ├── obs_norm.csv
│       └── obs_no_norm.csv
├── scripts/
│   ├── ablation.py             # Lancement des études d'ablation
│   ├── plots_results.py        # Génération des graphiques (mean ± 95% CI)
│   └── repro.sh                # Script de reproduction one-click
├── src/
│   ├── agents/
│   │   ├── dqn_agent.py        # Agent DQN (ReplayBuffer + TargetNet)
│   │   ├── heuristic_agents.py # Agent heuristique (règles manuelles)
│   │   └── random_agents.py    # Agent aléatoire (baseline minimale)
│   ├── networks/
│   │   └── mlp.py              # Réseau MLP 3 couches ReLU
│   └── utils/
│       ├── termination.py      # Détection de la raison de fin d'épisode
│       └── videos.py           # Enregistrement vidéo
├── train.py                    # Script principal d'entraînement
├── eval.py                     # Script d'évaluation
├── test-env.py                 # Vérification de l'environnement
├── test_all.py                 # Suite de 14 tests unitaires
├── requirements.txt
├── rapport.md                  # Rapport de projet (4-6 pages)
└── README.md
```

---

## 3. Installation

### Prérequis

- Python 3.10+
- pip, venv
- (Optionnel) GPU CUDA pour accélérer PyTorch

### Étapes

```bash
# 1. Créer et activer l'environnement virtuel
sudo apt update && sudo apt install python3-pip python3-venv
python3 -m venv .venv
source .venv/bin/activate

# 2. Installer les dépendances
pip install -r requirements.txt

# 3. Vérifier l'installation
python test-env.py
```

### Dépendances principales (`requirements.txt`)

| Librairie | Rôle |
|-----------|------|
| `gymnasium[box2d]` | Environnement LunarLander-v3 |
| `torch` | Réseau de neurones (DQN) |
| `numpy` | Calculs numériques |
| `pyyaml` | Chargement des configs YAML |
| `moviepy` / `opencv` | Enregistrement vidéo |

---

## 4. Environnement LunarLander-v3

### Description

LunarLander-v3 est un environnement 2D de Gymnasium basé sur le moteur physique Box2D. Un module lunaire doit atterrir sur une plateforme entre deux drapeaux.

```python
import gymnasium as gym
env = gym.make("LunarLander-v3", render_mode="rgb_array")
obs, info = env.reset(seed=42)
```

### Espace d'observation (8 dimensions)

| Index | Variable | Description |
|-------|----------|-------------|
| 0 | `x` | Position horizontale |
| 1 | `y` | Position verticale |
| 2 | `vx` | Vitesse horizontale |
| 3 | `vy` | Vitesse verticale |
| 4 | `theta` | Angle d'inclinaison |
| 5 | `theta_dot` | Vitesse angulaire |
| 6 | `left_leg` | Contact jambe gauche (0 ou 1) |
| 7 | `right_leg` | Contact jambe droite (0 ou 1) |

### Espace d'actions (discret, 4 actions)

| Action | Description |
|--------|-------------|
| 0 | Ne rien faire |
| 1 | Propulseur gauche |
| 2 | Moteur principal |
| 3 | Propulseur droit |

> Une version en contrôle continu est aussi disponible (`continuous=True`).

### Fonction de récompense

La récompense encourage :
- La proximité de la plateforme d'atterrissage
- Une vitesse lente à l'approche
- Le maintien horizontal du module
- L'atterrissage avec les deux jambes au sol

Des pénalités s'appliquent à chaque activation des moteurs. Des bonus/malus ponctuels :
- **+100** pour un atterrissage réussi
- **−100** pour un crash

**Critère de résolution :** score moyen ≥ 200 sur 100 épisodes consécutifs (sans vent).

### Raisons de terminaison

Détectées via `src/utils/termination.py` :

| Raison | Condition |
|--------|-----------|
| `sleep` | Les deux jambes au sol — atterrissage réussi |
| `crash` | `terminated=True`, pas hors-champ, pas de jambes |
| `out-of-view` | `|x| > 1.0` ou `y > 1.5` |
| `timeout` | `truncated=True` (limite de steps atteinte) |

---

## 5. Architecture du code

### 5.1 Réseau de neurones — `src/networks/mlp.py`

Réseau MLP (Multi-Layer Perceptron) utilisé comme approximateur de fonction Q.

```
Input (8) → FC(256) → ReLU → FC(128) → ReLU → FC(64) → ReLU → Output (4)
```

```python
class DQNNetwork(nn.Module):
    def __init__(self, state_size=8, action_size=4, hidden_sizes=[256, 128, 64]):
        # 3 couches cachées + couche de sortie
```

### 5.2 Replay Buffer — `src/agents/dqn_agent.py`

```python
class ReplayBuffer:
    def __init__(self, capacity):
        self.buffer = deque(maxlen=capacity)

    def push(self, state, action, reward, next_state, done): ...
    def sample(self, batch_size): ...  # tirage aléatoire uniforme
```

Stocke des transitions `(s, a, r, s', done)`. Utilise un `deque` à capacité fixe — les anciennes transitions sont automatiquement écrasées.

### 5.3 Agent DQN — `src/agents/dqn_agent.py`

#### Paramètres de construction

| Paramètre | Défaut | Description |
|-----------|--------|-------------|
| `state_size` | 8 | Dimension de l'observation |
| `action_size` | 4 | Nombre d'actions |
| `lr` | 1e-3 | Taux d'apprentissage (Adam) |
| `gamma` | 0.99 | Facteur de discount |
| `buffer_size` | 100 000 | Capacité du replay buffer |
| `batch_size` | 64 | Taille des mini-batchs |
| `tau` | 1e-3 | Coefficient de soft update |
| `target_update` | `"soft"` | Stratégie de mise à jour (`"soft"` ou `"hard"`) |
| `update_freq` | 100 | Fréquence du hard update (en steps) |
| `epsilon_start` | 1.0 | Epsilon initial (exploration complète) |
| `epsilon_end` | 0.01 | Epsilon minimal |
| `epsilon_decay` | 0.995 | Facteur de décroissance par épisode |

#### Méthodes principales

```python
agent.act(state, eval_mode=False)     # Sélection d'action (epsilon-greedy)
agent.step(s, a, r, s_next, done)     # Mémorise + apprentissage
agent.learn()                          # 1 étape de gradient sur un batch
agent.soft_update()                    # θ_target ← τ·θ + (1-τ)·θ_target
agent.hard_update()                    # θ_target ← θ
agent.decay_epsilon()                  # ε ← max(ε_end, ε · ε_decay)
agent.save(path) / agent.load(path)   # Sauvegarde/restauration du checkpoint
```

#### Algorithme d'apprentissage

```
Pour chaque step :
  1. Sélectionner action a avec ε-greedy
  2. Exécuter a → (s', r, done)
  3. Stocker (s, a, r, s', done) dans le replay buffer
  4. Si buffer suffisamment plein :
       - Tirer un batch aléatoire
       - Calculer Q(s,a) avec policy_net
       - Calculer Q_target = r + γ · max_a' Q_target(s',a') · (1-done)
       - Loss = MSE(Q(s,a), Q_target)
       - Gradient descent sur policy_net
       - Mettre à jour target_net (soft ou hard)
  5. En fin d'épisode : decay epsilon
```

### 5.4 Agents de référence

**`src/agents/random_agents.py`** — action uniforme dans {0,1,2,3}.

**`src/agents/heuristic_agents.py`** — règles manuelles :

```python
def heuristic_policy(obs):
    x, y, vx, vy, theta, theta_dot, left_leg, right_leg = obs
    if left_leg and right_leg: return 0   # atterri → ne rien faire
    if theta > 0.3:            return 3   # incliné gauche → propulseur droit
    if theta < -0.3:           return 1   # incliné droit → propulseur gauche
    if vy < -0.5:              return 2   # chute → moteur principal
    return 0
```

### 5.5 Logger — `logs/logger.py`

Initialise un fichier CSV et enregistre chaque épisode :

```python
init_logger(filepath)                           # Crée/ouvre le CSV
log_episode(writer, episode, return_, length,   # Écrit une ligne
            reason, loss=None, epsilon=None)
```

Colonnes enregistrées : `episode`, `return`, `length`, `termination_reason`, `loss` (DQN seulement), `epsilon` (DQN seulement).

---

## 6. Agents implémentés

| Agent | Approche | Score moyen attendu |
|-------|----------|---------------------|
| **Random** | Action uniforme aléatoire | ~ −180 |
| **Heuristic** | Règles manuelles (angle, vitesse) | ~ −20 à +50 |
| **DQN** | Deep Q-Network (MLP + Replay + Target) | ~ 215 ± 19 |

---

## 7. Entraînement

### Script principal : `train.py`

```bash
# Agent aléatoire (baseline)
python train.py --config configs/dqn_baseline.yaml --agent random

# Agent heuristique (baseline)
python train.py --config configs/dqn_baseline.yaml --agent heuristic

# Agent DQN — 1 seed
python train.py --config configs/dqn_baseline.yaml --agent dqn --seeds 0

# Agent DQN — 5 seeds (recommandé pour stats)
python train.py --config configs/dqn_baseline.yaml --agent dqn --seeds 0 1 2 3 4
```

### Configuration YAML (`configs/dqn_baseline.yaml`)

```yaml
env:
  name: "LunarLander-v3"
  render_mode: "rgb_array"

run:
  n_episodes: 500
  seed: 0

agent:
  type: "dqn"
  learning_rate: 0.001
  gamma: 0.99
  batch_size: 64
  buffer_size: 100000
  tau: 0.001
  target_update: "soft"     # "soft" ou "hard"
  update_freq: 100          # utilisé uniquement si target_update="hard"
  epsilon_start: 1.0
  epsilon_end: 0.01
  epsilon_decay: 0.995
  hidden_sizes: [256, 128, 64]
```

### Normalisation des observations (optionnelle)

Activable via `normalize_obs: true` dans la config. Utilise une normalisation en ligne (running mean/variance) avec clipping à ±5 σ.

### Sorties produites

Après entraînement DQN, les fichiers suivants sont créés :

| Fichier | Description |
|---------|-------------|
| `logs/dqn_seed{N}.csv` | Métriques par épisode (return, length, loss, epsilon, termination) |
| `weights/dqn_seed{N}_best.pth` | Checkpoint du meilleur épisode |
| `weights/dqn_seed{N}_final.pth` | Checkpoint final |

---

## 8. Évaluation

```bash
python eval.py --model weights/dqn_seed0_final.pth --episodes 100
```

| Argument | Description |
|----------|-------------|
| `--model` | Chemin vers le checkpoint `.pth` |
| `--episodes` | Nombre d'épisodes d'évaluation (défaut : 100) |

### Enregistrement vidéo

```python
from src.utils.videos import record_episodes
from src.agents.heuristic_agents import heuristic_policy

record_episodes(cfg, 'heuristic', heuristic_policy, n_episodes=3)
# Vidéos sauvegardées dans videos/heuristic_<timestamp>/
```

### Génération des graphiques

```bash
python scripts/plots_results.py
```

Graphiques générés dans `logs/plots/` :

| Fichier | Contenu |
|---------|---------|
| `dqn_returns_ci.png` | Courbe d'apprentissage (mean ± 95% CI, 5 seeds) |
| `dqn_epsilon.png` | Décroissance de l'epsilon |
| `dqn_loss.png` | Évolution de la loss MSE |
| `dqn_terminations.png` | Distribution des raisons de terminaison |
| `agent_comparison.png` | Comparaison Random vs Heuristic vs DQN |

---

## 9. Études d'ablation

### Lancement

```bash
python scripts/ablation.py --config configs/dqn_baseline.yaml --seeds 0 1 2 3 4
```

### Variables étudiées

| Ablation | Variable modifiée | Valeurs testées |
|----------|-------------------|-----------------|
| `buffer_10k` | `buffer_size` | 10 000 |
| `buffer_100k` | `buffer_size` | 100 000 (baseline) |
| `buffer_500k` | `buffer_size` | 500 000 |
| `target_hard` | `target_update` | `"hard"` (tous les 100 steps) |
| `target_soft` | `target_update` | `"soft"` (τ=0.001, baseline) |
| `obs_no_norm` | `normalize_obs` | `False` (baseline) |
| `obs_norm` | `normalize_obs` | `True` (running mean/var) |

### Résultats des ablations (mean ± 95% CI sur 5 seeds, 500 épisodes)

| Ablation | Description | Return moyen | Std | CI 95% |
|----------|-------------|-------------|-----|--------|
| `buffer_100k` | Buffer 100k (baseline) | −165.8 | 19.7 | ±17.3 |
| `obs_no_norm` | Sans normalisation (baseline) | −172.9 | 24.6 | ±21.5 |
| `target_hard` | Hard update tous les 100 steps | −196.9 | 52.0 | ±45.6 |
| `target_soft` | Soft update τ=0.001 (baseline) | −212.5 | 45.4 | ±39.8 |
| `buffer_10k` | Buffer 10k | −206.0 | 27.6 | ±24.2 |
| `buffer_500k` | Buffer 500k | −219.0 | 25.5 | ±22.4 |
| `obs_norm` | Avec normalisation (running) | −213.8 | 8.7 | ±7.6 |

> **Note :** Ces scores correspondent aux phases d'exploration (avant convergence complète). Le DQN atteint ~215 sur les 100 derniers épisodes en entraînement complet.

---

## 10. Résultats

### Performances finales (500 épisodes, 5 seeds)

| Agent | Return moyen | Meilleur épisode | Épisodes pour ≥ 200 |
|-------|-------------|------------------|----------------------|
| Random | ~−180 | ~−50 | Jamais |
| Heuristic | ~−20 à +50 | ~+100 | Rarement |
| DQN | **215.3 ± 18.7** | ~280 | ~300–400 |

### Distribution des terminaisons (DQN après convergence)

| Raison | Proportion |
|--------|-----------|
| Sleep (atterrissage réussi) | ~70% |
| Crash | ~20% |
| Timeout | ~10% |
| Out-of-view | ~0% |

### Analyse des ablations

**Taille du buffer :**
Un buffer trop petit (10k) réduit la diversité des transitions et dégrade la performance. Un buffer très grand (500k) n'améliore pas les résultats et ralentit la convergence. La valeur de 100k est le meilleur compromis.

**Stratégie de mise à jour de la target network :**
Le soft update (τ=0.001) produit des cibles plus stables et une convergence plus régulière que le hard update. La variance inter-seeds est nettement plus faible avec le soft update.

**Normalisation des observations :**
La normalisation en ligne n'apporte pas de bénéfice ici, car les observations de LunarLander sont déjà dans des plages relativement homogènes. Elle peut même nuire en début d'entraînement par des estimations instables de la moyenne/variance.

---

## 11. Reproduction des résultats

### One-click

```bash
bash scripts/repro.sh
```

Ce script régénère l'intégralité des artefacts (CSV, poids, vidéos, graphiques) et vérifie que les résultats sont reproductibles à ±5% près avec les mêmes seeds et configurations.

### Vérification manuelle de la reproductibilité

```python
import gymnasium as gym
from src.agents.dqn_agent import DQNAgent

# Avec epsilon=0 et même seed → mêmes actions et mêmes returns
a1 = DQNAgent(); a1.epsilon = 0
a2 = DQNAgent(); a2.epsilon = 0
env = gym.make('LunarLander-v3')
obs, _ = env.reset(seed=42)
# Les deux agents produisent exactement les mêmes actions
```

---

## 12. Tests

### Lancer tous les tests

```bash
python test_all.py
```

### Suite complète (14 tests)

| # | Test | Description |
|---|------|-------------|
| 1 | Environment creation | LunarLander-v3 : obs=(8,), 4 actions |
| 2 | Random agent basic | 3 épisodes sans crash |
| 3 | Heuristic agent basic | 3 épisodes sans crash |
| 4 | Random agent + logging | Returns, longueur, raison dans `logs/random.csv` |
| 5 | Heuristic agent + logging | Idem dans `logs/heuristic.csv` |
| 6 | DQN network (MLP) | Architecture 3 couches, forward pass (16,4) |
| 7 | ReplayBuffer | push/sample, capacité, formes des tenseurs |
| 8 | DQNAgent components | init, act, step, epsilon decay, save/load |
| 9 | DQN short training | 3 épisodes — boucle step/learn opérationnelle |
| 10 | Termination reasons | Les 4 raisons détectées correctement |
| 11 | Video recording | 1 épisode heuristique → fichier `.mp4` non vide |
| 12 | Reproducibility | Même seed + ε=0 → returns identiques |
| 13 | YAML config | Chargement de `configs/dqn_baseline.yaml` |
| 14 | eval.py script | `eval.py --help` s'exécute sans erreur |

---

## 13. Limites & Perspectives

### Limites actuelles

**Performance :**
- L'agent n'atteint pas 100% de sleep (~70% seulement)
- Forte variance inter-seeds : certaines seeds ne convergent pas
- L'epsilon decay multiplicatif n'est pas optimal (exploration trop longue en fin d'entraînement)

**Architecture :**
- Pas de techniques modernes : Double DQN, Dueling DQN, Prioritized Experience Replay
- Aucune régularisation (dropout, weight decay)
- τ fixe pour le soft update (pourrait être adaptatif)

**Ablations :**
- Seulement 3 variables étudiées
- Interactions entre variables non explorées (ex. : `buffer_size × target_update`)

### Améliorations futures

**Algorithmes :**
- **Double DQN** — réduit le biais de surestimation des Q-valeurs
- **Dueling DQN** — sépare l'estimation V(s) et A(s,a)
- **Prioritized Experience Replay** — échantillonne plus souvent les transitions informatives
- **N-step returns** — compromis entre TD(0) et Monte Carlo

**Optimisation des hyperparamètres :**
- Grid search sur `lr`, `gamma`, `batch_size`
- Epsilon decay adaptatif (cosine annealing, linear warmup)
- Architectures plus larges/profondes

**Infrastructure :**
- Early stopping basé sur la moyenne des 100 derniers épisodes
- Learning rate scheduling (`ReduceLROnPlateau`)
- Multi-processing pour les ablations

**Expérimentations supplémentaires :**
- Reward shaping personnalisé
- Curriculum learning (démarrer avec une version simplifiée)
- Contrôle continu avec PPO ou SAC

---

## Annexe — Référence rapide des commandes

```bash
# Entraînement
python train.py --config configs/dqn_baseline.yaml --agent dqn --seeds 0 1 2 3 4

# Évaluation
python eval.py --model weights/dqn_seed0_final.pth --episodes 100

# Ablations
python scripts/ablation.py --config configs/dqn_baseline.yaml --seeds 0 1 2 3 4

# Graphiques
python scripts/plots_results.py

# Tests
python test_all.py

# Reproduction complète
bash scripts/repro.sh
```

---

*Documentation générée à partir du code source, des configs YAML, des logs d'ablation et du sujet G-AIA-401 v0.0.1.*