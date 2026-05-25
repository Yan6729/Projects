#pragma once

#include "../math/Vec3.hpp"
#include "../math/Ray.hpp"
#include "../materials/FlatMaterial.hpp"

namespace RayTracer {
    struct HitRecord {
        double       t;
        Vec3         point;
        Vec3         normal;
        bool         frontFace;
        FlatMaterial material;
        Vec3 _color;
    };

    void setFaceNormal(HitRecord& rec, const Ray& ray, const Vec3& outwardNormal);
}