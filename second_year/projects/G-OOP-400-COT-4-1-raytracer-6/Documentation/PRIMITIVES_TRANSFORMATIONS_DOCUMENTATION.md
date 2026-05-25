# RayTracer - Primitives and Transformations Documentation

## Table of Contents
1. [Architecture Overview](#architecture-overview)
2. [Primitives System](#primitives-system)
3. [Transformations System](#transformations-system)
4. [Design Patterns](#design-patterns)
5. [Class Relationships](#class-relationships)
6. [Implementation Details](#implementation-details)
7. [Plugin System](#plugin-system)

---

## Architecture Overview

The primitives and transformations system is built using a layered architecture that promotes extensibility and maintainability:

```
┌─────────────────────────────────────────────────────────┐
│                    Application Layer                    │
│                  (Scene, Renderer, etc.)                │
└──────────────────────┬──────────────────────────────────┘
                       │
┌──────────────────────▼──────────────────────────────────┐
│                  Factory Layer                          │
│              (PrimitiveFactory)                         │
└──────────────────────┬──────────────────────────────────┘
                       │
┌──────────────────────▼──────────────────────────────────┐
│               Interface Layer                           │
│              (IPrimitive)                               │
└──────────────────────┬──────────────────────────────────┘
                       │
        ┌──────────────┼──────────────┐
        │              │              │
┌───────▼──────┐ ┌─────▼─────┐ ┌─────▼──────┐
│  Abstract    │ │Transformed│ │  Plugin    │
│  Primitive   │ │Primitive  │ │  System    │
└──────┬───────┘ └────┬──────┘ └────────────┘
       │              │
       └──────┬───────┘
              │
     ┌────────┼─────────────────────────────────────────────────────────────────────┐
     │        │        │         │        │        │           │          │         │
 ┌───▼───┐ ┌──▼──┐ ┌───▼────┐┌───▼───┐ ┌──▼──┐ ┌───▼────┐┌─────▼────┐ ┌───▼───┐ ┌───▼──┐
 │Sphere │ │Plane│ │Cylinder││ Cone  │ │Torus│ │Triangle││TangleCube│ │fractal│ │mobius│
 └───────┘ └─────┘ └────────┘└───────┘ └─────┘ └────────┘└──────────┘ └───────┘ └──────┘

```

---

## Primitives System

### Interface: IPrimitive

**Location:** `include/primitives/IPrimitive.hpp`

The base interface that all primitives must implement. Defines the contract for ray-primitive intersection.

```cpp
class IPrimitive {
    public:
        virtual ~IPrimitive() = default;
        virtual void configure(const std::map<std::string, double>& params) = 0;
        virtual std::optional<HitRecord> intersect(
            const Ray& ray,
            double tMin = 1e-4,
            double tMax = std::numeric_limits<double>::infinity()) const = 0;
};
```

**Key Methods:**
- `configure()`: Configures primitive parameters from a map (used for scene file parsing)
- `intersect()`: Computes ray-primitive intersection, returns optional HitRecord

### Abstract Base: AbstractPrimitive

**Location:** `include/primitives/AbstractPrimitive.hpp`

Provides common functionality for all primitives, implementing the Template Method pattern.

```cpp
class AbstractPrimitive : public IPrimitive {
    protected:
        Vec3 getNormalAtPoint(const Vec3& point) const;
        virtual Vec3 calculateNormal(const Vec3& point) const = 0;
        bool isValidIntersection(double t, double tMin, double tMax) const;
};
```

**Responsibilities:**
- Normal calculation delegation to subclasses
- Intersection validation (tMin/tMin bounds checking)
- Common primitive behavior

### Concrete Primitives

#### 1. Sphere

**Location:** `include/primitives/Sphere.hpp`, `src/primitives/sphere.cpp`

Implements ray-sphere intersection using quadratic equation solving.

**Mathematical Approach:**
- Solves: |O + tD - C|² = R²
- Quadratic: at² + bt + c = 0
  - a = D·D
  - b = 2(O-C)·D
  - c = |O-C|² - R²

**Key Features:**
- Returns closest valid intersection
- Normal calculation: (point - center) / radius
- Face normal determination for correct shading

#### 2. Plane

**Location:** `include/primitives/Plane.hpp`, `src/primitives/plane.cpp`

Implements infinite plane intersection using dot product.

**Mathematical Approach:**
- Solves: (P - C)·N = 0
- t = (C - O)·N / (D·N)
- Rejects if denominator near zero (parallel ray)

**Key Features:**
- Constant normal across surface
- Efficient single intersection test

#### 3. Cylinder

**Location:** `include/primitives/Cylinder.hpp`, `src/primitives/cylinder.cpp`

Implements finite cylinder (infinite along Y-axis, bounded in height).

**Mathematical Approach:**
- Projects ray to XZ plane
- Solves 2D circle intersection
- Validates Y bounds: |hit.y - center.y| ≤ height/2

**Key Features:**
- Height-limited cylinder
- Normal: horizontal component only (y = 0)

#### 4. Cone

**Location:** `include/primitives/Cone.hpp`, `src/primitives/cone.cpp`

Implements finite cone with apex at top.

**Mathematical Approach:**
- Uses cone equation with slope k = radius/height
- Quadratic with modified coefficients
- Validates Y bounds: center.y ≤ hit.y ≤ center.y + height

**Key Features:**
- Normal calculation includes slope
- Height-limited cone

#### 5. Torus

**Location:** `include/primitives/Torus.hpp`, `src/primitives/Torus.cpp`

Implements torus intersection using quartic equation solving.

**Mathematical Approach:**
- Solves quartic equation: At⁴ + Bt³ + Ct² + Dt + E = 0
- Uses Ferrari's method via cubic resolvent
- Selects smallest positive real root

**Key Features:**
- Complex quartic solver implementation
- Normal calculation using radial geometry
- Most computationally expensive primitive

#### 6. Triangle

**Location:** `include/primitives/Triangle.hpp`, `src/primitives/Triangle.cpp`

Implements triangle intersection using Möller-Trumbore algorithm.

**Mathematical Approach:**
- Barycentric coordinate test
- Edge vectors: E1 = V1-V0, E2 = V2-V0
- Solves for u, v (barycentric) and t
- Validates: 0 ≤ u ≤ 1, 0 ≤ v ≤ 1, u+v ≤ 1

**Key Features:**
- Fast intersection test
- Normal precomputed from vertices
- Backface culling support

### Decorator: TransformedPrimitive

**Location:** `include/primitives/TransformedPrimitive.hpp`, `src/primitives/TransformedPrimitives.cpp`

Wraps any primitive with transformation support using the Decorator pattern.

**Key Features:**
- Stores object-to-world and world-to-object matrices
- Transforms ray to local space before intersection
- Transforms hit point and normal back to world space
- Normal transformation uses inverse-transpose matrix

**Transformation Pipeline:**
1. Transform ray origin and direction to local space
2. Perform intersection in local space
3. Transform hit point to world space
4. Transform normal using inverse-transpose matrix
5. Recompute face normal

### HitRecord

**Location:** `include/primitives/HitRecord.hpp`, `src/primitives/HitRecord.cpp`

Struct containing intersection information.

```cpp
struct HitRecord {
    double t;          // Distance along ray
    Vec3 point;       // Intersection point
    Vec3 normal;      // Surface normal at intersection
    bool frontFace;   // Whether hit front or back face
    Vec3 _color;      // Color at intersection
};
```

**Helper Function:**
- `setFaceNormal()`: Determines front/back face and sets normal direction

---

## Transformations System

### Vec3 Class

**Location:** `include/math/Vec3.hpp`, `src/math/Vec3.cpp`, `src/math/Vec3Operators.cpp`, `src/math/Vec3Utils.cpp`

3D vector class with comprehensive operator overloading and utility functions.

**Core Operations:**
- Arithmetic: +, -, *, / (scalar and vector)
- Vector operations: dot, cross, length, normalize
- Component access: vec3Get(), vec3Ref()
- Comparison: ==, !=

**Utility Functions:**
- `nearZero()`: Epsilon comparison
- `reflect()`: Vector reflection (for mirrors)
- `refract()`: Vector refraction (for transparency)
- `lerp()`: Linear interpolation
- `abs()`, `min()`, `max()`: Component-wise operations

### Mat4 Class

**Location:** `include/math/Mat4.hpp`, `src/math/Mat4.cpp`

4x4 matrix class for 3D transformations.

**Storage:**
- Column-major order: `m[column][row]`
- std::array<std::array<double,4>, 4>

**Core Operations:**
- Matrix multiplication
- Transpose
- Inverse (Gaussian elimination with partial pivoting)

**Transformation Factories:**
- `identity()`: Identity matrix
- `translation()`: Translation matrices
- `rotationX/Y/Z()`: Axis-aligned rotations
- `rotation()`: Arbitrary axis rotation (Rodrigues' formula)
- `scale()`: Uniform and non-uniform scaling

### Transform Functions

**Location:** `src/math/Mat4Transform.cpp`

Functions for transforming different geometric entities.

**transformPoint():**
- Full 4x4 transformation including translation
- Handles homogeneous coordinates (w division)

**transformDirection():**
- 3x3 upper-left submatrix only (no translation)
- For vectors that represent directions

**transformNormal():**
- Uses inverse-transpose matrix
- Preserves orthogonality under non-uniform scaling
- Critical for correct shading

### Ray Structure

**Location:** `include/math/Ray.hpp`, `src/math/Ray.cpp`

Simple ray representation.

```cpp
struct Ray {
    Vec3 origin;
    Vec3 direction;
    
    Vec3 at(double t) const;  // Point at distance t
};
```

---

## Design Patterns

### 1. Factory Pattern

**Implementation:** `PrimitiveFactory` class

**Location:** `include/factories/PrimitiveFactory.hpp`

**Purpose:** Centralized primitive creation with type registration

**Key Features:**
- Singleton pattern (getInstance())
- Runtime type registration via template method
- Map of creator functions (std::function)
- Extensible without modifying factory code

**Usage:**
```cpp
// Registration (automatic for defaults)
factory.registerPrimitive<Sphere>("sphere");

// Creation
auto primitive = factory.createPrimitive("sphere");
```

**Benefits:**
- Decouples creation logic from usage
- Enables plugin system
- Easy to add new primitives

### 2. Interface/Abstract Class Pattern

**Implementation:** `IPrimitive` interface + `AbstractPrimitive` base class

**Purpose:** Defines common contract while allowing specialization

**Key Features:**
- Pure virtual interface (IPrimitive)
- Partial implementation (AbstractPrimitive)
- Template Method pattern for normal calculation
- Polymorphic behavior through virtual functions

**Benefits:**
- Type safety through interface
- Code reuse in base class
- Clear separation of interface and implementation

### 3. Decorator Pattern

**Implementation:** `TransformedPrimitive` class

**Purpose:** Adds transformation capability to any primitive without modification

**Key Features:**
- Wraps IPrimitive instance
- Implements same interface
- Delegates to inner primitive after transformation
- Transparent to client code

**Benefits:**
- Single responsibility (primitives don't handle transforms)
- Composable transformations
- No need to modify existing primitives
- Can chain multiple decorators

### 4. Template Method Pattern

**Implementation:** `AbstractPrimitive::calculateNormal()`

**Purpose:** Defines algorithm structure, lets subclasses implement specific steps

**Key Features:**
- Base class provides framework (getNormalAtPoint)
- Subclasses implement specific behavior (calculateNormal)
- Inversion of control

**Benefits:**
- Code reuse for common logic
- Enforces consistent interface
- Easy to add new primitives

### 5. Singleton Pattern

**Implementation:** `PrimitiveFactory::getInstance()`

**Purpose:** Ensure single instance of factory

**Key Features:**
- Static local variable (Meyers' singleton)
- Thread-safe in C++11+
- Lazy initialization

**Benefits:**
- Global access point
- Controlled instantiation
- Prevents multiple factory instances

---

## Class Relationships

### Inheritance Hierarchy

```
IPrimitive (interface)
    ├── AbstractPrimitive (abstract base)
    │       ├── Sphere
    │       ├── Plane
    │       ├── Cylinder
    │       ├── Cone
    │       ├── Torus
    │       └── Triangle
    └── TransformedPrimitive (decorator)
```

### Composition Relationships

```
TransformedPrimitive
    ├── std::shared_ptr<IPrimitive> _inner
    ├── Mat4 _objToWorld
    └── Mat4 _worldToObj

PrimitiveFactory
    └── std::unordered_map<std::string, PrimitiveCreator> creators_
```

### Dependency Relationships

```
All Primitives → Vec3, Ray, HitRecord
TransformedPrimitive → Mat4, transform functions
PrimitiveFactory → All concrete primitives
```





## Mathematical Foundations

### Ray-Primitive Intersection

**General Approach:**
1. Substitute ray equation P(t) = O + tD into primitive equation
2. Solve for parameter t
3. Validate solution within bounds
4. Compute geometric properties at intersection

### Transformation Matrices

**Translation:**
```
[1  0  0  tx]
[0  1  0  ty]
[0  0  1  tz]
[0  0  0  1 ]
```

**Rotation (axis-angle):**
Uses Rodrigues' rotation formula:
```
R = I + sin(θ)K + (1-cos(θ))K²
```
Where K is the cross-product matrix of the axis.

**Scale:**
```
[sx 0  0  0 ]
[0  sy 0  0 ]
[0  0  sz 0 ]
[0  0  0  1 ]
```

### Normal Transformation

Normals transform differently than points:
- Points: P' = M × P
- Normals: N' = (M⁻¹)ᵀ × N

This preserves orthogonality under non-uniform transformations.

---



## Extensibility

### Adding a New Primitive

1. **Create header file** in `include/primitives/`
```cpp
class NewPrimitive : public AbstractPrimitive {
    // Implement interface
};
```

2. **Create implementation file** in `src/primitives/`
```cpp
// Implement intersect(), calculateNormal(), configure()
extern "C" {
    IPrimitive *create() { return new NewPrimitive(); }
    const char* getType() { return "newprimitive"; }
}
```

3. **Register in factory** (optional, for static linking)
```cpp
factory.registerPrimitive<NewPrimitive>("newprimitive");
```

4. **Build as plugin** (recommended)
```makefile
newprimitive.so: NewPrimitive.cpp
    g++ -shared -fPIC -o plugins/newprimitive.so NewPrimitive.cpp
```

### Adding a New Transformation

1. **Add factory function** in `src/math/Mat4Factories.cpp`
```cpp
Mat4 newTransformation(params) {
    // Build and return matrix
}
```

2. **Add declaration** in `include/math/Mat4.hpp`

3. **Use in scene files** or code

---



## Conclusion

The primitives and transformations system demonstrates:

- **Clean Architecture:** Clear separation of concerns
- **Design Patterns:** Factory, Decorator, Template Method, Singleton
- **Extensibility:** Easy to add new primitives and transformations
- **Performance:** Efficient intersection algorithms
- **Maintainability:** Well-structured code with clear responsibilities

The system successfully balances flexibility with performance, making it suitable for both educational purposes and practical ray tracing applications.

---

## File Structure

```
include/
├── primitives/
│   ├── IPrimitive.hpp              # Interface
│   ├── AbstractPrimitive.hpp      # Base class
│   ├── TransformedPrimitive.hpp   # Decorator
│   ├── HitRecord.hpp              # Intersection data
│   ├── Sphere.hpp                 # Sphere primitive
│   ├── Plane.hpp                  # Plane primitive
│   ├── Cylinder.hpp               # Cylinder primitive
│   ├── Cone.hpp                   # Cone primitive
│   ├── Torus.hpp                  # Torus primitive
│   └── Triangle.hpp               # Triangle primitive
├── math/
│   ├── Vec3.hpp                   # 3D vector
│   ├── Mat4.hpp                   # 4x4 matrix
│   └── Ray.hpp                    # Ray structure
└── factories/
    └── PrimitiveFactory.hpp       # Factory pattern

src/
├── primitives/
│   ├── AbstractPrimitive.cpp
│   ├── TransformedPrimitives.cpp
│   ├── HitRecord.cpp
│   ├── sphere.cpp
│   ├── plane.cpp
│   ├── cylinder.cpp
│   ├── cone.cpp
│   ├── Torus.cpp
│   └── Triangle.cpp
└── math/
    ├── Vec3.cpp
    ├── Vec3Operators.cpp
    ├── Vec3Utils.cpp
    ├── Mat4.cpp
    ├── Mat4Factories.cpp
    └── Mat4Transform.cpp
