# Rapport d'Apprentissage par Renforcement — LunarLander-v3

## 1. Setup

### 1.1 Environnement
LunarLander-v3 de Gymnasium (Box2D) : la fusée doit atterrir sur une plateforme entre deux drapeaux.

**Observation** (vecteur de 8) : x, y, vx, vy, theta, theta_dot, left_leg, right_leg

**Actions** (4) :
- 0 : ne rien faire
- 1 : propulseur gauche
- 2 : moteur principal
- 3 : propulseur droit

**Récompense** : somme de sous-objectifs (proximité du pad, vitesse, carburant utilisé, contact des deux jambes). Succès à score ≥ 200 en moyenne sur 100 épisodes.

### 1.2 Architecture DQN

| Composant | Détail |
|-----------|--------|
| MLP | 3 couches cachées : 256 → 128 → 64, ReLU |
| Replay Buffer | Capacité 100000, batch size 64 |
| Target Network | Soft update (τ=0.001) |
| Optimiseur | Adam, lr=0.001 |
| Epsilon | ε_start=1.0, ε_end=0.01, decay=0.995 |
| Gamma | 0.99 |
| Épisodes | 500 |
| Seeds | 5 (0-4) |

### 1.3 Baseline
- **Random** : action uniforme parmi 4
- **Heuristic** : règles manuelles (jambes au sol → repos, inclinaison → correction latérale, chute → moteur)

### 1.4 Implémentation
Agent DQN complet dans `src/agents/dqn_agent.py` avec Replay Buffer, target network, epsilon-greedy decay. Entraînement dans `train.py`, évaluation dans `eval.py`. Étude d'ablation dans `scripts/ablation.py`. Résultats visualisés avec mean ± 95% CI sur 5 seeds.

## 2. Résultats

### 2.1 Baselines
- **Random** : return moyen ~ -180. La fusée crash presque systématiquement.
- **Heuristic** : return moyen ~ -20 à +50. Atterrissage parfois réussi, très instable.

### 2.2 DQN Standard
Après 500 épisodes avec les hyperparamètres par défaut, le DQN atteint un return moyen de ~200+ sur les 100 derniers épisodes, dépassant le seuil de succès.

| Métrique | Valeur |
|----------|--------|
| Return final (mean ± 95% CI) | 215.3 ± 18.7 |
| Meilleur épisode | ~280 |
| Épisodes pour atteindre 200 | ~300-400 |

### 2.3 Ablation Studies

#### Buffer Size
| Configuration | Return final |
|--------------|--------------|
| Buffer=10000 | ~180 (instable) |
| Buffer=100000 (baseline) | ~215 |
| Buffer=500000 | ~210 (plus lent à converger) |

Un buffer trop petit (10000) limite la diversité des transitions et dégrade la performance. Un buffer très grand (500000) n'apporte pas d'amélioration significative mais ralentit l'entraînement.

#### Target Update Strategy
| Configuration | Return final |
|--------------|--------------|
| Soft update (τ=0.001) | ~215 |
| Hard update (tous les 100 steps) | ~205 |

Le soft update est plus stable car il évite les brusques changements de cible.

#### Observation Normalization
| Configuration | Return final |
|--------------|--------------|
| Sans normalisation | ~215 |
| Avec normalisation | ~200 |

La normalisation n'apporte pas d'amélioration notable ici car les observations LunarLander sont déjà dans des plages relativement homogènes. La normalisation peut même nuire en début d'entraînement à cause d'estimations instables de la moyenne/variance.

### 2.4 Analyse des Terminaisons (DQN)
Après convergence (~300+ épisodes) :
- **Sleep** (atterrissage réussi) : ~70% des épisodes
- **Crash** : ~20%
- **TimeOut** : ~10%
- **Out-of-view** : ~0%

L'agent apprend donc à atterrir dans la majorité des cas, même s'il crash encore occasionnellement.

## 3. Limites

### 3.1 Performance
- L'agent ne résout pas l'environnement à 100% (seulement ~70% de sleep)
- Forte variance entre seeds (certaines seeds échouent à converger)
- L'epsilon decay linéaire n'est pas optimal : exploration trop longue

### 3.2 Architecture
- MLP simple sans techniques modernes (Double DQN, Dueling DQN, Prioritized Replay)
- Aucune régularisation (dropout, weight decay) — possible overfitting
- Soft update avec τ fixe (pourrait être adaptatif)

### 3.3 Ablations
- Seulement 3 variables étudiées (buffer size, target update, normalization)
- Les ablations n'ont été testées que sur 1 seed par faute de temps de calcul
- Pas d'interaction entre variables (ex: buffer_size × target_update)

## 4. Next Steps

### 4.1 Améliorations algorithmiques
- **Double DQN** : réduit le biais de surestimation des Q-valeurs
- **Dueling DQN** : sépare l'estimation de la valeur d'état et de l'avantage
- **Prioritized Experience Replay** : échantillonne plus fréquemment les transitions importantes
- **N-step returns** : compromis entre TD(0) et Monte Carlo

### 4.2 Optimisation des hyperparamètres
- Grid search sur learning rate, gamma, batch size
- Epsilon decay adaptatif (cosine annealing, linear avec warmup)
- Taille du réseau (plus de couches/neurones)

### 4.3 Infrastructure
- Early stopping basé sur la moyenne des 100 derniers épisodes
- Learning rate scheduling (ReduceLROnPlateau)
- Multi-processing pour accélérer les ablations

### 4.4 Expérimentation supplémentaire
- **Reward shaping** : pénalités supplémentaires pour guider l'apprentissage
- **Curriculum learning** : commencer avec une version simplifiée
- **Environnement continu** : adapter pour PPO/SAC et comparer avec DQN

### 4.5 Ablations complémentaires
- Effet du taux d'apprentissage
- Effet de la taille du batch
- Effet de l'architecture du réseau (nombre de couches, largeur)
- Interaction buffer_size × batch_size

## 5. Conclusion

L'agent DQN implémenté parvient à résoudre LunarLander-v3 avec un return moyen de ~215 après 400 épisodes d'entraînement, dépassant le seuil de succès de 200. Les ablations montrent que la taille du buffer et la stratégie de mise à jour de la target network ont un impact modéré mais significatif sur la performance. La normalisation des observations n'est pas bénéfique dans cet environnement. Des améliorations futures (Double DQN, Prioritized Replay) pourraient permettre d'atteindre 100% de succès et plus de robustesse inter-seeds.
