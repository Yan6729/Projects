# Arcade — Plateforme de jeux rétro

> Projet OOP Epitech — Plateforme de jeux en C++ avec bibliothèques graphiques et de jeux chargeables à la volée.

---

## Description

Arcade est un programme qui permet à l'utilisateur de choisir un jeu et une bibliothèque graphique à la volée, sans redémarrage. Les bibliothèques de jeux et d'affichage sont des plugins chargés dynamiquement à l'exécution.

Le programme principal (le core) ne connaît aucune bibliothèque graphique ni aucun jeu à la compilation : tout est découvert et chargé à l'exécution depuis le dossier `./lib/`. Cela impose de concevoir des interfaces communes rigoureuses et de respecter un contrat strict entre le core et chaque plugin.

### Fonctionnalités principales

- Changement de bibliothèque graphique en cours de partie, sans quitter le programme.
- Changement de jeu en cours de session depuis le menu ou via raccourci clavier.
- Affichage du menu avec listes des jeux, des rendus disponibles, des scores et saisie du pseudo (limité à 10 caractères).
- Persistance des scores entre les parties.
- Gestion des erreurs : mauvais argument, bibliothèque incompatible, fichier introuvable — exit 84.
- Partage d'interface avec un autre groupe pour interopérabilité totale.

### Architecture

| Composant | Rôle |
|-----------|------|
| Core | Gère le menu, le chargeur de bibliothèques, les scores et la boucle principale. Ne référence jamais une bibliothèque graphique ou un jeu directement. |
| `IGraphics` | Interface commune à toutes les bibliothèques graphiques (dans `IGraphics.hpp`). |
| `IGame` | Interface commune à tous les jeux (dans `IGame.hpp`). |
| `./lib/` | Dossier unique contenant tous les `.so` — graphiques et jeux. Scanné au démarrage pour peupler le menu. |

### Contraintes techniques

- Utilisation obligatoire de `dlopen`, `dlsym`, `dlclose`, `dlerror` pour le chargement des bibliothèques.
- Flag `-fno-gnu-unique` pour garantir le déchargement correct des bibliothèques (évite les conflits de symboles statiques).
- `ldd ./arcade` ne doit révéler aucune dépendance vers les `.so` du projet.
- Les bibliothèques graphiques n'influencent jamais la logique de jeu, et vice-versa.

---

## Équipe

| Rôle | Nom | Email |
|------|-----|-------|
| Responsable des Lib graphics | Brayane FANOU | `branyane.fanou@epitech.eu` |
| Responsable du Core | Naofal TOGBE | `naofal.togbe@epitech.eu` |
| Git master & responsable des games | Yan DOSSOU-LOKO | `yan.dossou-loko@epitech.eu` |

**Email du responsable du groupe partenaire (partage d'interface) :** `karyl.soumaila@epitech.eu`

---

## Compilation

### Makefile

```bash
make            # tout compiler (core + graphiques + jeux)
make core       # uniquement le binaire principal
make graphicals # uniquement les bibliothèques graphiques
make games      # uniquement les bibliothèques de jeux
make re         # recompilation complète
make clean      # supprimer les fichiers objets
make fclean     # supprimer les fichiers objets + binaires
```

### CMake

```bash
mv bonus/CMakeLists.txt ./
mkdir build
cd build
cmake ..
make

ou

mv bonus/CMakeLists.txt ./
chmod +x build.sh
./build.sh
```

Les deux méthodes produisent :
- `./arcade` — le binaire principal
- `./lib/*.so` — toutes les bibliothèques graphiques et de jeux

---

## Utilisation

```bash
./arcade ./lib/arcade_ncurses.so
```

L'argument doit obligatoirement être une **bibliothèque graphique**. Passer une bibliothèque de jeu affichera une erreur et quittera avec le code `84`.

### Touches (en jeu)

| Touche | Action |
|--------|--------|
| `Flèches` | Se déplacer (Haut, Bas, Gauche, Droite) |
| `Espace` | Action spéciale (Saut, Tir, etc.) |
| `Échap` | Retour au menu principal |
| `F1` | Passer à la bibliothèque graphique suivante |
| `F2` | Passer au jeu suivant |
| `F3` | Mettre le jeu en Pause / Reprendre |
| `F4` | Ouvrir le menu interne du jeu |
| `F5` | Redémarrer la partie en cours |
| `F10` | Quitter l'application |

---

## Structure du projet

```
arcade/
├── src/
│   ├── core/           # Programme principal
│   ├── games/          # Sources des jeux (Snake, Pacman, Nibbler, SolarFox, etc.)
│   └── graphics/       # Sources des libs graphiques (SFML, SDL2, Ncurses, Allegro5, Libcaca)
├── include/
│   ├── graphics/       # IGraphics.hpp
│   └── games/          # IGame.hpp
├── lib/                # Dossier de sortie des .so compilés
├── doc/
│   ├── Documentation_Arcade.md         # Documentation technique
│   ├── Guide_Complet_Developpeur.pdf   # Guide d'extension (Shared Libs)
│   └── arcade_uml.png                # Diagramme UML
bonus
|  └── CMakeLists.txt
├── Makefile
└── README.md
```

---

## Bibliothèques disponibles

### Graphismes
- **SFML** (`arcade_sfml.so`)
- **SDL2** (`arcade_sdl2.so`)
- **Ncurses** (`arcade_ncurses.so`)
- **Allegro 5** (`arcade_allegro5.so`)
- **Libcaca** (`arcade_libcaca.so`)

### Jeux
- **Snake** : Le classique.
- **Pacman** : Labyrinthe et fantômes.
- **Nibbler** : Snake avec obstacles.
- **SolarFox** : Shoot 'em up spatial.
- **Centipede** : Defense contre insectes.
- **Qix** : Capture de zones.
- **Minesweeper** : Démineur.

---

## Ajouter une nouvelle bibliothèque

Pour ajouter un nouveau module, veuillez vous référer au [Guide Complet du Développeur](doc/Guide_Complet_Developpeur.md).

---

## Notes techniques

- Toutes les bibliothèques sont chargées à l'exécution via `dlopen` / `dlsym`.
- Le flag `-fno-gnu-unique` garantit le bon déchargement des bibliothèques.
- Messages d'erreur sur `stderr` ; sortie code `84` en cas d'erreur.

---

## Licence

Ce projet a été réalisé dans le cadre du cursus Epitech.
Projet Epitech 2026.
