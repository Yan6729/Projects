# RayTracer — Documentation Technique de l’Architecture

## Introduction

Cette documentation présente les différentes parties architecturales implémentées dans le projet **RayTracer**.

Les éléments principaux réalisés sont :

- Le système de plugins dynamiques avec `.so`
- La Factory générique des primitives et lumières
- Le système de scène (`Scene`)
- Le parsing des fichiers `.cfg`
- Le `SceneBuilder`
- Les transformations des primitives
- La primitive avancée `MobiusStrip`
- Les design patterns utilisés

L’objectif principal de cette architecture est de rendre le moteur :

- Modulaire
- Extensible
- Dynamique
- Facilement maintenable
- Optimisable

---

# 1. Système de Plugins

## Objectif

Le système de plugins permet de charger dynamiquement des primitives et lumières sans modifier le cœur du moteur.

Ainsi, une nouvelle primitive peut être ajoutée simplement en compilant un nouveau fichier `.so`.

### Exemple

```bash
plugins/raytracer_sphere.so
plugins/raytracer_plane.so
plugins/raytracer_mobius.so
```

Le moteur charge ensuite automatiquement ces librairies.

---

# 1.1 PluginLoader

## Rôle

La classe `PluginLoader` est responsable du chargement des librairies dynamiques.

Elle encapsule l’utilisation de :

- `dlopen`
- `dlsym`
- `dlclose`

Cela évite que le reste du moteur manipule directement l’API POSIX.

---

## Fonctionnement

### Chargement de la librairie

```cpp
handle_ = dlopen(library_path.c_str(), RTLD_LAZY);
```

`dlopen` charge le fichier `.so` en mémoire.

Le handle retourné représente la librairie ouverte.

---

### Chargement des symboles

```cpp
void* func_ptr = dlsym(handle_, sym_name.c_str());
```

`dlsym` recherche une fonction exportée dans le plugin.

Exemple :

```cpp
create()
getType()
```

---

### Fermeture de la librairie

```cpp
dlclose(handle_);
```

Permet de libérer la librairie lorsque le programme se termine.

---

# 1.2 Export des Plugins

Chaque plugin exporte deux fonctions :

```cpp
extern "C" {
    IPrimitive* create();
    const char* getType();
}
```

---

## `create()`

Cette fonction crée dynamiquement la primitive.

### Exemple

```cpp
IPrimitive* create() {
    return new Sphere();
}
```

---

## `getType()`

Cette fonction retourne le nom de la primitive.

### Exemple

```cpp
const char* getType() {
    return "sphere";
}
```

Ce nom est utilisé par la Factory.

---

## Pourquoi `extern "C"` ?

Le C++ applique du *name mangling*.

Sans `extern "C"`, les noms des fonctions deviennent :

```text
_Z6createv
```

et `dlsym` ne pourrait pas retrouver correctement les symboles.

---

# 2. PluginFactory

## Objectif

La Factory permet de créer des objets dynamiquement sans connaître leur type concret.

Le moteur travaille uniquement avec les interfaces :

```cpp
IPrimitive
ILight
```

et jamais directement avec :

```cpp
Sphere
Plane
Cone
MobiusStrip
```

---

# 2.1 Design Pattern : Factory

Le projet utilise le **Factory Pattern**.

Le but de ce pattern est de :

- Encapsuler la création des objets
- Cacher les types concrets
- Découpler les modules
- Faciliter l’extension du moteur

---

## Fonctionnement

La Factory associe :

```text
"sphere" -> fonction create()
```

Ainsi :

```cpp
factory.create("sphere")
```

retourne automatiquement une `Sphere`.

---

# 2.2 Template Générique

La Factory utilise un template :

```cpp
template<typename T>
```

Cela permet d’utiliser la même logique pour :

```cpp
PluginFactory<IPrimitive>
PluginFactory<ILight>
```

---

## Avantage

Une seule implémentation peut gérer plusieurs types d’objets.

Cela réduit énormément la duplication de code.

---

# 2.3 Structure PluginData

```cpp
struct PluginData {
    std::unique_ptr<PluginLoader> loader;
    CreateFunc create;
};
```

---

## Pourquoi stocker `loader` ?

Le `PluginLoader` garde la librairie `.so` ouverte.

Si le loader est détruit :

```cpp
dlclose(handle_)
```

est appelé.

Les pointeurs de fonctions deviennent alors invalides.

---

## Pourquoi stocker `create` ?

Cela évite d’appeler `dlsym` à chaque création.

Le symbole est résolu une seule fois.

Cela améliore les performances.

---

# 2.4 `unordered_map`

La Factory utilise :

```cpp
std::unordered_map<std::string, PluginData>
```

---

## Pourquoi une map ?

Cela permet un accès rapide aux plugins.

### Exemple

```text
"sphere" -> plugin sphere
"plane" -> plugin plane
```

La recherche est pratiquement en temps constant :

```text
O(1)
```

---

# 3. Scene

## Objectif

La classe `Scene` représente le monde 3D final utilisé par le renderer.

Elle contient toutes les primitives et lumières.

---

## Contenu

```cpp
std::unordered_map<std::string, PrimitiveList> primitives_;
std::unordered_map<std::string, LightList> lights_;
```

---

## Pourquoi regrouper par type ?

Cela permet :

- Une meilleure organisation
- Une recherche plus simple
- Des optimisations futures
- Un traitement spécialisé par type

---

## Méthodes principales

### `addPrimitive()`

Ajoute une primitive dans la scène.

---

### `addLight()`

Ajoute une lumière dans la scène.

---

### `getPrimitives()`

Retourne toutes les primitives d’un type donné.

---

# 4. SceneParser

## Objectif

Le `SceneParser` lit les fichiers `.cfg`.

Il transforme les données textuelles en structures C++.

---

## Exemple de fichier

```cfg
spheres = (
{
    x = 0;
    y = 0;
    z = 0;
    r = 50;
}
);
```

---

# 4.1 Utilisation de libconfig

Le parsing repose sur la bibliothèque `libconfig`.

---

## Lecture du fichier

```cpp
Config cfg;
cfg.readFile(filepath.c_str());
```

---

## Accès aux données

```cpp
const Setting& sphere = prim["spheres"];
```

---

## Extraction sécurisée

```cpp
sphere.lookupValue("x", data.x);
```

Cette méthode évite les erreurs de type.

---

# 4.2 Structures de Données

Le parser remplit des structures temporaires :

```cpp
SphereData
PlaneData
ConeData
CylinderData
```

Ces structures contiennent uniquement les données du fichier.

---

## Séparation Importante

Le parser ne crée **PAS** directement les objets runtime.

Il produit seulement des données.

Cette séparation rend l’architecture plus propre.

---

# 4.3 Parsing des Transformations

Le parser supporte :

- Translation
- Rotation

---

## Exemple

```cfg
translation = {
    x = 10;
    y = 0;
    z = 5;
};
```

---

# 5. SceneBuilder

## Objectif

Le `SceneBuilder` transforme les données parser en vrais objets runtime.

Il relie :

```text
Parser -> Factory -> Scene
```

---

# 5.1 Design Pattern : Builder

Le projet utilise le **Builder Pattern**.

Le but est de construire progressivement une scène complexe.

---

## Avantages

- Séparation parsing/runtime
- Construction progressive
- Code plus modulaire
- Meilleure extensibilité

---

# 5.2 Construction des Primitives

### Exemple

```cpp
auto primitive = primitive_factory_.create("sphere");
```

Puis :

```cpp
primitive->configure({...});
```

---

## Pourquoi `configure()` ?

La Factory crée une primitive vide.

Le Builder injecte ensuite les données du parser.

Cela découple :

- la création
- la configuration

---

# 5.3 Transformations

Le Builder construit également les matrices de transformation.

---

## Matrices utilisées

- Translation
- Rotation X
- Rotation Y
- Rotation Z

---

## Transformation finale

```cpp
Mat4 m = translation(...) * rotationX(...) * ...
```

---

## `TransformedPrimitive`

Les primitives transformées sont encapsulées dans :

```cpp
TransformedPrimitive
```

Cela permet d’ajouter des transformations sans modifier les primitives originales.

---

# 6. MobiusStrip

## Objectif

Le `MobiusStrip` implémente une surface paramétrique avancée.

Contrairement à une sphère :

- il n’existe pas de formule simple d’intersection
- l’intersection doit être approximée numériquement

---

# 6.1 Surface Paramétrique

Le ruban de Möbius est défini par :

```text
P(u,v)
```

avec :

- `u` : angle autour du ruban
- `v` : déplacement sur la largeur

---

## Équation

```text
P(u,v) = (
(R + v cos(u/2)) cos(u),
v sin(u/2),
(R + v cos(u/2)) sin(u)
)
```

---

# 6.2 Dérivées Partielles

Le Mobius utilise :

```cpp
dPdu()
dPdv()
```

Ces fonctions calculent les tangentes de la surface.

---

## Utilité

Les dérivées servent :

- au calcul des normales
- à Newton-Raphson
- à l’approximation des intersections

---

# 6.3 Normales

La normale est calculée avec :

```cpp
tu.cross(tv)
```

Le produit vectoriel des tangentes produit une normale perpendiculaire à la surface.

---

# 6.4 Newton-Raphson

## Problème

On cherche :

```text
ray(t) = surface(u,v)
```

mais cette équation ne peut pas être résolue analytiquement.

---

## Solution

Le projet utilise Newton-Raphson.

Cette méthode affine progressivement une solution approximative.

---

## Étapes

1. Estimation initiale
2. Calcul de l’erreur
3. Calcul du Jacobien
4. Correction de `u` et `v`
5. Répétition jusqu’à convergence

---

## Importance

Cette technique permet de rendre des surfaces complexes.

Elle ouvre la possibilité d’ajouter :

- Tore
- Bézier
- NURBS
- Surfaces implicites

---

# 7. Design Patterns Utilisés

# Factory Pattern

Utilisé dans :

```cpp
PluginFactory<T>
```

---

## Rôle

- Création dynamique
- Découplage
- Extensibilité

---

# Builder Pattern

Utilisé dans :

```cpp
SceneBuilder
```

---

## Rôle

- Construction progressive
- Séparation parsing/runtime
- Centralisation de la logique de création

---

# RAII

Utilisé avec :

```cpp
std::unique_ptr
```

---

## Rôle

- Gestion automatique mémoire
- Évite les memory leaks
- Ownership clair

---

# Polymorphisme

Utilisé via :

```cpp
IPrimitive
ILight
```

---

## Rôle

Le moteur peut manipuler tous les objets via une interface commune.

---

# 8. Optimisations Architecturales

## `unordered_map`

Recherche rapide des plugins.

---

## Chargement dynamique

Évite de recompiler le moteur pour ajouter des primitives.

---

## Réutilisation des symboles

Les fonctions `create()` sont résolues une seule fois.

---

## Découplage

Le moteur ne dépend pas des primitives concrètes.

---

# Conclusion

Cette architecture permet de construire un moteur de ray tracing :

- Modulaire
- Dynamique
- Extensible
- Maintenable
- Compatible plugins

L’utilisation des design patterns améliore fortement la qualité de l’architecture.

Le système de plugins permet d’ajouter de nouvelles primitives sans modifier le moteur principal.

Le parser et le builder séparent proprement les responsabilités.

Enfin, le `MobiusStrip` démontre l’intégration de mathématiques avancées et d’algorithmes numériques dans le moteur.