# Documentation Technique - Projet Arcade

## 1. Introduction

### Présentation générale
Le projet **Arcade** est une plateforme de jeux rétro développée en C++. L'objectif est de créer un écosystème capable de charger dynamiquement différentes bibliothèques de jeux et d'affichage graphique au moment de l'exécution, sans nécessiter de recompilation du noyau (Core).

### Architecture globale
L'architecture est divisée en trois modules distincts :
- **Core** : Le cerveau de l'application, gérant la logique de haut niveau et le passage entre les modules.
- **Bibliothèques Graphiques (Shared Libs)** : Des modules interchangeables gérant l'affichage et les entrées utilisateur (SFML, SDL2, Ncurses, etc.).
- **Jeux (Shared Libs)** : Des modules contenant la logique propre à chaque jeu (Snake, Pacman, etc.).

### Chargement dynamique
Le projet utilise la bibliothèque système `<dlfcn.h>` pour charger les fichiers `.so` (Shared Objects) via `dlopen`. Ce mécanisme permet au Core de découvrir les fonctions exportées par les bibliothèques et d'instancier des objets implémentant une interface commune (`IGraphics` ou `IGame`).

---
## 2. Module Core

Le binaire `arcade` est le point d'entrée du programme. Il initialise le système et maintient la boucle principale de rendu et de mise à jour.

### Core
**Rôle** : Coordonne les interactions entre l'utilisateur, le jeu en cours et la bibliothèque graphique active.
**Attributs principaux** :
- `_state` : État actuel de l'application (MENU, PLAYING, GAME_OVER, EXIT).
- `_libs` : Instance de `LibManager`.
- `_graphics` : Pointeur intelligent vers la bibliothèque graphique active.
- `_game` : Pointeur intelligent vers le jeu chargé.
**Méthodes clés** :
- `run()` : Lance la boucle principale.
- `loadGraphics(path)` / `loadGame(path)` : Charge dynamiquement un nouveau module.
- `handleMenuInput()` / `handleGameInput()` : Gère les entrées selon le contexte.
**Relations** : Agrège `LibManager` et `ScoreManager`. Utilise les interfaces `IGame` et `IGraphics`.

### LibManager
**Rôle** : Explore le dossier `./lib` et instancie les modules demandés par le Core.
**Attributs principaux** :
- `_graphicLibs` / `_gameLibs` : Listes des chemins vers les fichiers `.so` trouvés.
- `_loaders` : Vecteur de `shared_ptr<DLLoader>` pour maintenir les poignées ouvertes.
**Méthodes clés** :
- `scanLibs()` : Recherche les bibliothèques disponibles.
- `loadGraphics()` / `loadGame()` : Retourne une instance de module via `DLLoader`.

### ScoreManager
**Rôle** : Gère la persistance des meilleurs scores dans un fichier texte.
**Attributs principaux** :
- `_scores` : Map associant le nom d'un jeu à une liste de `ScoreEntry`.
**Méthodes clés** :
- `load()` / `save()` : Lecture/Écriture sur disque.
- `addScore()` : Ajoute une performance à la base locale.

### DLLoader
**Rôle** : Wrapper RAII pour les fonctions `dlopen`, `dlsym` et `dlclose`. C'est une classe template permettant d'instancier n'importe quel type de classe exportée.
**Méthodes clés** :
- `getSymbol(name)` : Récupère l'adresse d'un symbole dans la bibliothèque partagée.

---

## 3. Module Graphique

### Interface IGraphics
Toutes les bibliothèques graphiques doivent hériter de cette interface abstraite pour être compatibles.
**Méthodes clés** :
- `init()` / `close()` : Initialisation et nettoyage de la fenêtre/contexte.
- `getInput()` : Récupère l'entrée utilisateur mappée sur l'énumération `Arcade::Input`.
- `drawEntity(entity)` : Affiche un élément de jeu (sprite ou caractère).
- `drawText(text)` : Affiche du texte à l'écran.

### Bibliothèques supportées
- **arcade_sfml** : Utilise la SFML pour un rendu 2D moderne et fluide.
- **arcade_sdl2** : Implémentation basée sur la SDL2, robuste et multiplateforme.
- **arcade_ncurses** : Rendu en mode texte dans le terminal (idéal pour le SSH).
- **arcade_allegro5** : Utilise la bibliothèque Allegro 5 pour le multimédia.
- **arcade_libcaca** : Rendu en ASCII-art coloré utilisant la bibliothèque Libcaca.

---

## 4. Module Jeux

### Interface IGame
Définit le contrat que chaque jeu doit respecter pour être piloté par le Core.
**Méthodes clés** :
- `update()` : Met à jour la logique interne (déplacement, collisions).
- `handleEvent(input)` : Réagit aux actions du joueur.
- `getEntities()` : Retourne la liste des éléments à afficher.
- `getScore()` / `isGameOver()` : État de la partie.

### Jeux disponibles
- **arcade_snake** : Le classique jeu du serpent avec gestion de la queue et de la nourriture.
- **arcade_pacman** : Labyrinthe avec fantômes intelligents, gommes et bonus.
- **arcade_nibbler** : Variante du Snake où le serpent doit naviguer dans un labyrinthe complexe.

### Fichiers partagés et utilitaires
- `utilities.cpp` : Contient des fonctions d'aide (génération aléatoire, gestion des directions).
- `mazeGenerator.cpp` : Implémente un algorithme de génération de labyrinthe aléatoire utilisé par Pacman et Nibbler.
- `pacmanGhost.cpp` : Logique spécifique pour les mouvements et l'IA des fantômes.

---

## 5. Relations et interactions

### Flux d'exécution
1. Le **Core** démarre et demande à **LibManager** de scanner le dossier `./lib`.
2. L'utilisateur saisit son nom sur l'écran d'accueil.
3. L'utilisateur sélectionne un jeu via une interface gérée par la bibliothèque graphique sélectionnée au démarrage.
4. À chaque frame :
    a. Le **Core** interroge **IGraphics** pour les entrées.
    b. Les entrées sont transmises à **IGame**.
    c. **IGame** met à jour son état interne.
    d. **IGame** renvoie une liste de `GameEntity` au **Core**.
    e. Le **Core** transmet ces entités à **IGraphics** pour affichage.
5. Si un changement de bibliothèque est demandé (touche TAB), le **Core** décharge la bibliothèque actuelle et charge la suivante de manière transparente.

---

## 6. Glossaire

- **RAII (Resource Acquisition Is Initialization)** : Technique de programmation où la gestion des ressources (comme les handles de fichiers `.so`) est liée à la durée de vie de l'objet.
- **Shared Object (.so)** : Fichier contenant du code compilé qui peut être partagé et chargé dynamiquement par d'autres programmes.
- **Symbole** : Nom d'une fonction ou d'une variable globale exportée dans une bibliothèque partagée.
- **Interface Abstraite** : Classe ne contenant que des fonctions virtuelles pures, définissant un "contrat" pour les classes dérivées.
- **Frame** : Une itération complète de la boucle de rendu (visant généralement 60 par seconde).
