# Documentation — Module `renderer`

**Projet :** RayTracer — Epitech 2026  
**Namespace :** `RayTracer`  
**Fichiers couverts :** `include/renderer/` et `src/renderer/`

---

## Vue d'ensemble

Le module `renderer` gère tout le pipeline de rendu : du lancer de rayons à l'affichage ou l'export du résultat final. Il repose sur une interface `IOutput` pour abstraire les sorties, une `FrameBuffer` comme tampon de pixels, et deux modes d'exécution distincts — un rendu interactif via SFML et un rendu en ligne de commande via `Renderer`.

```
Renderer (mode CLI)          SfmlOutput (mode GUI)
    └── FrameBuffer               └── FrameBuffer
    └── IOutput                   └── PpmOutput (export)
            └── PpmOutput         └── ModifiedWindow (SFML)

OutputFactorie               LoadFiles
IOutput  (interface)         FrameBuffer
```

---

## `IOutput` — Interface de sortie

**Fichier :** `include/renderer/IOutput.hpp`

Interface pure que toute sortie de rendu doit implémenter.

### Méthode virtuelle

```cpp
virtual void render(const FrameBuffer& _buffer) = 0;
```

| Paramètre | Type | Description |
|-----------|------|-------------|
| `_buffer` | `const FrameBuffer&` | Tampon de pixels à exporter ou afficher |

Chaque implémentation décide comment consommer le `FrameBuffer` (écrire un fichier, mettre à jour une texture SFML, etc.).

---

## `FrameBuffer` — Tampon de pixels

**Fichiers :** `include/renderer/FrameBuffer.hpp` / `src/renderer/FrameBuffer.cpp`

Conteneur 2D de couleurs représentant l'image rendue. Chaque pixel est une `Color` stockée en lignes (accès par `_pixels[y][x]`).

### Structure `Dimensions`

```cpp
struct Dimensions {
    int width;
    int height;
};
```

### Constructeurs

```cpp
FrameBuffer();                              // 800×800 par défaut, noir
FrameBuffer(const Dimensions& _dim);        // Dimensions personnalisées
```

### Méthodes publiques

```cpp
void setPixel(int x, int y, const Color& _color);
```
Écrit la couleur au pixel `(x, y)`. Lève une `RayTracerError` si les coordonnées sont hors limites.

```cpp
const Color& getPixel(int x, int y) const;
```
Lit la couleur au pixel `(x, y)`. Lève une `RayTracerError` si les coordonnées sont hors limites.

```cpp
const Dimensions& getDimensions(void) const;
```
Retourne les dimensions du buffer.

```cpp
void reset(void);
```
Réinitialise tous les pixels à noir (`Color{0, 0, 0}`). Fixe la taille à 800×800 quelle que soit la dimension d'origine (comportement actuel — voir note ci-dessous).

> **Note :** `reset()` réassigne toujours 800×800, indépendamment de `_dimensions`. Si le buffer a été créé avec des dimensions personnalisées, `reset()` ne les respecte pas.

---

## `PpmOutput` — Export fichier PPM

**Fichiers :** `include/renderer/PpmOutput.hpp` / `src/renderer/PpmOutput.cpp`

Implémente `IOutput`. Exporte le contenu du `FrameBuffer` vers un fichier PPM (format image texte P3).

### Méthode `render`

```cpp
void render(const FrameBuffer& buffer) override;
```

**Comportement :**

1. Génère un nom de fichier horodaté : `results/output_<timestamp>.ppm`
2. Écrit l'en-tête PPM (`P3`, `800 800`, `255`)
3. Parcourt tous les pixels ligne par ligne et les écrit
4. Affiche une confirmation dans la console

> **Note :** La résolution est codée en dur à 800×800 dans le fichier PPM, indépendamment des dimensions réelles du `FrameBuffer`. Le dossier `results/` doit exister au préalable.

**Format de sortie :**
```
P3
800 800
255
r g b  r g b  r g b ...
...
```

---

## `OutputFactorie` — Fabrique de sorties

**Fichiers :** `include/renderer/OutputFactorie.hpp` / `src/renderer/OutputFactorie.cpp`

Crée une instance de `IOutput` selon une option numérique.

### Méthode

```cpp
std::unique_ptr<IOutput> createOutput(std::size_t option);
```

| Option | Type retourné |
|--------|--------------|
| `0` | `PpmOutput` |
| autre | Lève `RayTracerError` |

> **Note :** Seul le mode PPM est actuellement disponible via cette fabrique. `SfmlOutput` est instancié directement et ne passe pas par `OutputFactorie`.

---

## `LoadFiles` — Chargement de répertoire

**Fichiers :** `include/renderer/LoadFiles.hpp` / `src/renderer/LoadFiles.cpp`

Utilitaire qui liste les fichiers réguliers d'un répertoire.

### Constructeur

```cpp
LoadFiles(const std::string& dirname);
```

Ouvre le répertoire `dirname`. Lève une `RayTracerError` si le répertoire est inaccessible.

### Méthode

```cpp
std::vector<std::string> getfiles(void);
```

Retourne la liste des noms de fichiers réguliers (`DT_REG`) du répertoire. Ferme automatiquement le descripteur après lecture.

**Usage typique :**
```cpp
LoadFiles loader("plugins");
std::vector<std::string> files = loader.getfiles();
// files = {"sphere.so", "cone.so", ...}
```

---

## `Renderer` — Rendu en ligne de commande

**Fichiers :** `include/renderer/Renderer.hpp` / `src/renderer/Renderer.cpp`

Orchestrateur principal du rendu en mode CLI (sans fenêtre). Charge une scène, calcule tous les pixels et délègue l'export à un `IOutput`.

### Constructeurs

```cpp
Renderer();                                 // 800×800 par défaut
Renderer(const Dimensions& dimensions);     // Dimensions personnalisées
```

### Méthodes publiques

```cpp
void loader(const std::string& _filepath);
```
Charge une scène complète depuis un fichier de configuration `.cfg` :
- Parse la scène (`SceneParser`)
- Charge les plugins `.so` du dossier `plugins/`
- Construit la scène (`SceneBuilder`)
- Configure la caméra

```cpp
void addOutput(std::unique_ptr<IOutput> _output);
```
Ajoute une sortie de rendu. Plusieurs peuvent être enregistrées, mais seul `_outputs[0]` est utilisé lors du rendu.

```cpp
void configCamera(CameraData _data);
```
Configure la caméra à partir de données de position et de rotation. Calcule le vecteur `forward` depuis les angles `pitch` et `yaw`, construit les vecteurs `right` et `up` par produit vectoriel, puis positionne l'écran virtuel via un `Rectangle3D`. Gère le cas dégénéré où `forward` est parallèle à l'axe Y (évite un vecteur `right` nul).

```cpp
void render(void);
```
Lance le rendu complet de la scène. Voir la section [Pipeline de rendu](#pipeline-de-rendu) ci-dessous.

### Attributs privés

| Attribut | Type | Description |
|----------|------|-------------|
| `_outputs` | `vector<unique_ptr<IOutput>>` | Liste des sorties enregistrées |
| `_maxX`, `_maxY` | `int` | Dimensions de l'image |
| `_prim` | `PluginFactory<IPrimitive>` | Fabrique de primitives via plugins |
| `_light` | `PluginFactory<ILight>` | Fabrique de lumières via plugins |
| `_scene` | `Scene` | Scène chargée |
| `_cam` | `Camera` | Caméra configurée |

---

## `SfmlOutput` — Rendu interactif (SFML)

**Fichiers :** `include/renderer/SfmlOutput.hpp` / `src/renderer/SfmlOutput.cpp`

Interface graphique complète du ray tracer. Gère une fenêtre SFML 1600×800 avec un panneau de sélection de scènes à gauche (400px), une zone de rendu au centre (800×800px) et un panneau d'actions à droite (400px).

### Enum `STATE`

```cpp
enum STATE { INTRO, MENU, RENDERER };
```

| État | Description |
|------|-------------|
| `INTRO` | Animation d'intro (séquence d'images PNG) |
| `MENU` | Menu principal avec boutons Start / About Us / Quit |
| `RENDERER` | Vue de rendu avec sélection de scènes |

### Constructeur

```cpp
SfmlOutput();
```
Crée une fenêtre 1600×800, initialise une image noire 800×800, charge la police `asset/LibraSerifModern-Regular.otf`. Lève `RayTracerError` si la police ou la texture sont introuvables.

### Méthodes publiques

```cpp
void render(void);
```
Point d'entrée principal. Lance `loader()`, initialise l'état `INTRO`, puis entre dans la boucle d'événements SFML. Orchestre les appels à `update()` et aux méthodes d'affichage selon l'état courant.

```cpp
void loader(void);
```
Initialise l'interface :
- Scanne `scenes/` pour lister les fichiers `.cfg` valides (qui contiennent une section `camera`)
- Charge les plugins `.so` depuis `plugins/`
- Crée les boutons du panneau gauche (scènes) et droit (actions + menu)

```cpp
void configCamera(CameraData _data);
```
Identique à `Renderer::configCamera`. Configure la caméra pour le rendu SFML (même algorithme yaw/pitch/Rectangle3D).

```cpp
void update(const STATE& state);
```
Gère les événements selon l'état courant :
- `MENU` : clics sur Start, About Us, Quit
- `RENDERER` : scroll de la liste de scènes, clics sur scènes (chargement), boutons clear / export PPM / retour menu
- `INTRO` : touche Espace ou Backspace pour passer directement au menu

```cpp
void showTheRendering(void);
```
Calcule et affiche **une ligne** de l'image par appel (rendu progressif ligne par ligne). Lance les rayons, trouve l'intersection la plus proche, calcule l'éclairage via `computeLighting()`, puis met à jour l'image SFML et le `FrameBuffer`. La variable `_currentLine` progresse à chaque appel jusqu'à `_maxY`.

```cpp
void menu_displaying(void);
```
Affiche l'écran de menu (fond + boutons Start / About Us / Quit).

```cpp
void drawSceneButtons(void);
```
Affiche les boutons de scènes dans le panneau gauche, en tenant compte du `_scrollOffset` pour gérer le défilement vertical.

### Actions disponibles dans le panneau droit

| Bouton | Action |
|--------|--------|
| `clear` | Réinitialise le buffer, la scène et l'image |
| `Export scenes (ppm)` | Appelle `_ppm.render(_buf)` pour sauvegarder en PPM |
| `↩ Menu` | Retourne à l'état `MENU` |

---

## `Rectangle3D` — Écran virtuel

**Fichiers :** `include/camera/Rectangle3D.hpp` / `src/camera/Rectangle3D.cpp`

Représente le plan de projection de la caméra (l'écran virtuel dans l'espace 3D). Défini par une origine et deux vecteurs directeurs.

### Attributs publics

| Attribut | Type | Description |
|----------|------|-------------|
| `_O` | `Vec3` | Coin inférieur gauche de l'écran |
| `_I` | `Vec3` | Vecteur horizontal (axe U), de longueur = largeur de l'écran |
| `_J` | `Vec3` | Vecteur vertical (axe V), de longueur = hauteur de l'écran |

### Constructeurs

```cpp
Rectangle3D();                              // Écran par défaut : origine (0,0,0), I=(1,0,0), J=(0,1,0)
Rectangle3D(Vec3 o, Vec3 i, Vec3 j);        // Coin + vecteurs personnalisés
```

### Méthode

```cpp
Vec3 convertTo3D(double u, double v) const;
```

Convertit des coordonnées normalisées `(u, v)` en point 3D sur le plan de l'écran :

```
point = _O + (_I × u) + (_J × v)
```

Avec `u, v ∈ [0.0, 1.0]`, balaie l'intégralité de la surface de l'écran virtuel.

---

## `Camera` — Caméra

**Fichiers :** `include/camera/Camera.hpp` / `src/camera/Camera.cpp`

Représente la caméra du ray tracer. Définit le point de vue et génère les rayons projetés vers la scène.

### Attributs publics

| Attribut | Type | Description |
|----------|------|-------------|
| `origin` | `Vec3` | Position de la caméra dans l'espace 3D |
| `screen` | `Rectangle3D` | Écran virtuel sur lequel les rayons sont projetés |

### Méthode

```cpp
Ray thorwRay(double u, double v);
```

Génère un rayon partant de `origin` et passant par le point `(u, v)` de l'écran virtuel :

```
pointAt = screen.convertTo3D(u, v)
rayon   = Ray(origin, pointAt − origin)
```

`u` et `v` sont des coordonnées normalisées `[0.0, 1.0]` correspondant respectivement à la position horizontale et verticale du pixel dans l'image.

**Exemple d'utilisation dans le renderer :**
```cpp
Ray ray = _cam.thorwRay(
    (double)w / (_maxX - 1),   // u : colonne normalisée
    (double)h / (_maxY - 1)    // v : ligne normalisée
);
```

---

## `configCamera` — Configuration de la caméra

Cette méthode est présente à la fois dans `Renderer` et `SfmlOutput`. Elle traduit les données brutes d'une scène (`CameraData`) en une caméra opérationnelle.

### Signature

```cpp
void configCamera(CameraData _data);
```

### Paramètres de `CameraData`

| Champ | Description |
|-------|-------------|
| `xp`, `yp`, `zp` | Position de la caméra dans la scène |
| `field_of_view` | Champ de vision en degrés |
| `xr` | Rotation verticale (pitch) en degrés |
| `yr` | Rotation horizontale (yaw) en degrés |

### Algorithme

```
1. origin = Vec3(xp, yp, zp)

2. fov    = field_of_view × π/180
   halfW  = tan(fov / 2)
   halfH  = halfW × (maxX / maxY)         ← correction d'aspect ratio

3. yaw   = yr × π/180
   pitch = xr × π/180
   forward = normalize(cos(pitch)×sin(yaw),  sin(pitch),  cos(pitch)×cos(yaw))

4. Si |forward · (0,1,0)| > 0.999  → worldUp = (0,0,1)   ← cas dégénéré (vue verticale)
   Sinon                            → worldUp = (0,1,0)

5. right = normalize(forward × worldUp)
   up    = normalize(right × forward)

6. center = origin + forward
   corner = center − right×halfW − up×halfH

7. screen = Rectangle3D(corner, right×(2×halfW), up×(2×halfH))
```

Le cas dégénéré (étape 4) survient quand la caméra regarde directement vers le haut ou le bas : `forward` devient parallèle à `(0,1,0)`, rendant `forward × worldUp` nul. On bascule alors sur `(0,0,1)` comme vecteur "haut" de référence.

---

## Pipeline de rendu

Le même algorithme est utilisé dans `Renderer::render()` et `SfmlOutput::showTheRendering()` :

```
Pour chaque pixel (w, h) :
│
├── Lancer un rayon via cam.thorwRay(w / (maxX-1), h / (maxY-1))
│
├── Pour chaque type de primitive dans la scène :
│       Pour chaque primitive de ce type :
│           hit = primitive.intersect(ray, tMin=1e-2, tMax)
│           Si hit && hit.t < tMin → mettre à jour _closest
│
├── Si _closest existe :
│       surfaceColor = Color(hit._color.x, hit._color.y, hit._color.z)
│       lit = computeLighting(hit, surfaceColor, scene)
│       buffer.setPixel(w, h, lit * 255)
│
└── (si pas d'intersection → pixel reste noir)
```

**Différence entre les deux modes :**

| | `Renderer` | `SfmlOutput` |
|---|---|---|
| Progression | Boucle complète en une passe | Une ligne par frame (progressif) |
| Sortie | `_outputs[0]->render(buf)` | Mise à jour texture SFML en temps réel + export PPM optionnel |
| Résolution | Configurable via `Dimensions` | Fixée à 800×800 |

---

## Récapitulatif des dépendances

```
Renderer / SfmlOutput
    ├── Camera::thorwRay()          → génère les rayons
    ├── IPrimitive::intersect()     → détecte les intersections
    ├── computeLighting()           → calcule l'éclairage (module lights)
    ├── FrameBuffer                 → stocke les pixels calculés
    ├── IOutput / PpmOutput         → exporte le résultat
    ├── LoadFiles                   → liste plugins et scènes
    ├── SceneParser + SceneBuilder  → charge la scène depuis .cfg
    └── PluginFactory               → charge les .so dynamiquement

OutputFactorie
    └── PpmOutput
```

---

## Ajouter un nouveau type de sortie

1. Créer une classe héritant de `IOutput` dans `include/renderer/` et `src/renderer/`.
2. Implémenter `void render(const FrameBuffer& buffer)`.
3. Ajouter un case dans `OutputFactorie::createOutput()` avec une nouvelle option numérique.

**Exemple :**
```cpp
case 1:
    return std::make_unique<PngOutput>();
```