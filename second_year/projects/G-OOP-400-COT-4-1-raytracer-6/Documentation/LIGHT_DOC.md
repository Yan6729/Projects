# Documentation — Module `lights`

**Projet :** RayTracer — Epitech 2026  
**Namespace :** `RayTracer`  
**Fichiers couverts :** `include/lights/` et `src/lights/`

---

## Vue d'ensemble

Le module `lights` gère tout ce qui concerne l'éclairage dans le ray tracer. Il repose sur une interface commune `ILight`, implémentée par trois types de lumières : ambiante, directionnelle et ponctuelle. La classe `Color` représente les couleurs manipulées dans les calculs, et la fonction `computeLighting` orchestre l'accumulation de toutes les sources de lumière d'une scène.

```
ILight  (interface)
├── AmbientLight
├── DirectionalLight
└── PointLight

Color               (type de données couleur)
computeLighting()   (fonction d'orchestration)
```

---

## `ILight` — Interface de base

**Fichier :** `include/lights/ILights.hpp`

Interface pure que toute source de lumière doit implémenter.

### Méthode virtuelle

```cpp
virtual Color illuminate(const HitRecord& hit, const Color& surfaceColor) const = 0;
```

| Paramètre | Type | Description |
|-----------|------|-------------|
| `hit` | `const HitRecord&` | Données du point d'intersection (position, normale, etc.) |
| `surfaceColor` | `const Color&` | Couleur de la surface touchée |

**Retour :** `Color` — contribution lumineuse de cette source au point d'intersection.

Chaque implémentation doit calculer sa propre contribution en fonction de ses propriétés (direction, intensité, position…).

---

## `Color` — Classe couleur

**Fichiers :** `include/lights/Color.hpp` / `src/lights/Color.cpp`

Représente une couleur RGB en virgule flottante (canaux normalisés entre 0.0 et 1.0).

### Attributs publics

| Attribut | Type | Description |
|----------|------|-------------|
| `r` | `double` | Canal rouge |
| `g` | `double` | Canal vert |
| `b` | `double` | Canal bleu |

### Constructeurs

```cpp
Color(double r, double g, double b);   // Construit depuis des valeurs normalisées [0.0, 1.0]
Color();                               // Constructeur par défaut
```

### Méthode statique

```cpp
static Color fromRGB255(int r, int g, int b);
```

Crée une `Color` depuis des valeurs entières classiques (0–255). Divise chaque canal par 255.

**Exemple :**
```cpp
Color red = Color::fromRGB255(255, 0, 0);  // → Color(1.0, 0.0, 0.0)
```

### Opérateurs

| Opérateur | Signature | Description |
|-----------|-----------|-------------|
| `+` | `Color operator+(const Color& rhs) const` | Addition composante par composante |
| `+=` | `Color& operator+=(const Color& rhs)` | Addition en place |
| `*` (scalaire) | `Color operator*(double s) const` | Multiplication par un scalaire |
| `*` (couleur) | `Color operator*(const Color& rhs) const` | Multiplication composante par composante |

### Méthodes utilitaires

```cpp
Color clamped01() const;
```
Retourne une copie dont chaque canal est limité à `[0.0, 1.0]`. Utilisé en fin de calcul pour éviter les débordements.

```cpp
std::uint8_t toByte(double v) const;
```
Convertit une valeur normalisée `[0.0, 1.0]` en entier `[0, 255]` (avec arrondi à `+ 0.5`). Utilisé pour l'export PPM/pixel.

---

## `AmbientLight` — Lumière ambiante

**Fichiers :** `include/lights/AmbientLight.hpp` / `src/lights/AmbientLight.cpp`

Simule un éclairage uniforme sans direction. Tous les points de la scène reçoivent la même contribution, indépendamment de leur orientation.

### Constructeur

```cpp
explicit AmbientLight(double intensity);
```

| Paramètre | Type | Description |
|-----------|------|-------------|
| `intensity` | `double` | Facteur multiplicatif appliqué à la couleur de surface (ex : `0.1` pour un éclairage faible) |

### Méthode `illuminate`

```cpp
Color illuminate(const HitRecord& hit, const Color& surfaceColor) const override;
```

**Calcul :**
```
résultat = surfaceColor × intensity
```

Le `HitRecord` est ignoré (la lumière ambiante ne dépend pas de la géométrie).

**Exemple d'usage :**
```cpp
AmbientLight ambient(0.15);
// Éclaire légèrement toutes les surfaces de la scène
```

---

## `DirectionalLight` — Lumière directionnelle

**Fichiers :** `include/lights/DirectionalLight.hpp` / `src/lights/DirectionalLight.cpp`

Simule une source de lumière infiniment lointaine (comme le soleil). La lumière arrive toujours dans la même direction, sans atténuation avec la distance.

### Constructeur

```cpp
DirectionalLight(const Vec3& direction, double diffuse);
```

| Paramètre | Type | Description |
|-----------|------|-------------|
| `direction` | `const Vec3&` | Direction d'où provient la lumière (normalisée en interne) |
| `diffuse` | `double` | Intensité du coefficient diffus |

### Méthode `illuminate`

```cpp
Color illuminate(const HitRecord& hit, const Color& surfaceColor) const override;
```

**Calcul (modèle de Lambert) :**
```
lightDir = normalize(direction)
lambert  = max(0.0, normal · lightDir)
résultat = surfaceColor × (diffuse × lambert)
```

Le produit scalaire `normal · lightDir` mesure l'alignement entre la surface et la direction lumineuse. Un angle rasant donne une faible contribution ; un angle perpendiculaire donne le maximum.

**Exemple d'usage :**
```cpp
DirectionalLight sun(Vec3(1.0, -1.0, 0.0), 0.8);
// Lumière venant de la droite, légèrement vers le bas
```

---

## `PointLight` — Lumière ponctuelle

**Fichiers :** `include/lights/PointLight.hpp` / `src/lights/PointLight.cpp`

Simule une ampoule ou une flamme : source ponctuelle qui émet dans toutes les directions avec atténuation selon la distance.

### Constructeurs

```cpp
PointLight();                                            // Position (0,0,0), intensité 2.0 par défaut
PointLight(const Vec3& position, double intensity);      // Position et intensité personnalisées
```

| Paramètre | Type | Description |
|-----------|------|-------------|
| `position` | `const Vec3&` | Position de la lumière dans la scène |
| `intensity` | `double` | Intensité de base |

### Méthode `illuminate`

```cpp
Color illuminate(const HitRecord& hit, const Color& surfaceColor) const override;
```

**Calcul :**
```
toLight     = position − hit.point
dist        = |toLight|
lightDir    = toLight / dist
lambert     = max(0.0, normal · lightDir)
attenuation = 1.0 / (1.0 + 0.0001 × dist²)
résultat    = surfaceColor × (intensity × lambert × attenuation)
```

L'atténuation quadratique (`1 / (1 + k·d²)`) modélise le comportement physique réel de la lumière : plus le point est éloigné, plus la contribution diminue. La constante `0.0001` permet une atténuation douce adaptée aux dimensions typiques de la scène.

**Exemple d'usage :**
```cpp
PointLight lamp(Vec3(0.0, 5.0, 0.0), 3.0);
// Lampe au-dessus de la scène, intensité forte
```

---

## `computeLighting` — Fonction d'orchestration

**Fichiers :** `include/lights/Lighting.hpp` / `src/lights/Lighting.cpp`

Fonction libre qui accumule les contributions de toutes les sources de lumière d'une scène pour un point donné.

### Signature

```cpp
namespace RayTracer {
    Color computeLighting(
        const HitRecord& hit,
        const Color& surfaceColor,
        const Scene& scene);
}
```

| Paramètre | Type | Description |
|-----------|------|-------------|
| `hit` | `const HitRecord&` | Point d'intersection avec la géométrie |
| `surfaceColor` | `const Color&` | Couleur de base de la surface |
| `scene` | `const Scene&` | Scène contenant toutes les listes de lumières |

**Retour :** `Color` — couleur finale clampée à `[0.0, 1.0]`.

### Fonctionnement

La fonction interroge la scène via `scene.findLights(key)` pour chaque catégorie de lumière, puis accumule leurs contributions :

```
résultat = Color(0, 0, 0)
pour chaque lumière ambiante   → résultat += light.illuminate(hit, surfaceColor)
pour chaque lumière directionnelle → résultat += light.illuminate(hit, surfaceColor)
pour chaque lumière ponctuelle → résultat += light.illuminate(hit, surfaceColor)
retourner résultat.clamped01()
```

Le clamping final garantit que les canaux ne dépassent pas 1.0, même si plusieurs sources de lumière fortes se cumulent.

### Clés utilisées pour `scene.findLights`

| Clé | Type de lumière |
|-----|----------------|
| `"ambient"` | `AmbientLight` |
| `"directional"` | `DirectionalLight` |
| `"point"` | `PointLight` |

---

## Récapitulatif des dépendances

```
computeLighting
    └── Scene::findLights()
    └── ILight::illuminate()
            ├── AmbientLight::illuminate()   ← Color × intensity
            ├── DirectionalLight::illuminate() ← Lambert + diffuse
            └── PointLight::illuminate()      ← Lambert + attenuation quadratique

Color
    ├── opérateurs +, +=, * (scalaire), * (Color)
    ├── clamped01()
    └── toByte()
```

---

## Ajouter un nouveau type de lumière

1. Créer une classe héritant de `ILight` dans `include/lights/` et `src/lights/`.
2. Implémenter `illuminate(const HitRecord&, const Color&) const`.
3. Choisir une clé de type (ex. `"spot"`) et l'enregistrer dans la `Scene`.
4. Ajouter un bloc `findLights("spot")` dans `computeLighting()`.