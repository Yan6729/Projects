/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** plane
*/

#include "../../include/primitives/Plane.hpp"
#include "../../include/primitives/HitRecord.hpp"
#include "../../include/math/Ray.hpp"
#include <cmath>

namespace RayTracer {
    Plane::Plane(const Vec3& center, const Vec3& normal, const Vec3& color)
        : _center(center), _normal(normal.normalized()), _color(color) {}

    void Plane::setCenter(const Vec3& center) { _center = center; }
    void Plane::setNormal(const Vec3& normal) { _normal = normal.normalized(); }
    void Plane::setColor(const Vec3& color) { _color = color; }

    Vec3 Plane::calculateNormal(const Vec3& point) const {
        (void)point;
        return _normal;
    }

    std::optional<HitRecord> Plane::intersect(const Ray& ray, double tMin, double tMax) const
    {
        double denom = _normal.dot(ray.direction);
        if (std::abs(denom) < 1e-6) return std::nullopt;

        double t = (_center - ray.origin).dot(_normal) / denom;
        if (t < tMin || t > tMax) return std::nullopt;

        HitRecord rec;
        rec.t = t;
        rec.point = ray.at(t);
        rec._color = _color;
        setFaceNormal(rec, ray, _normal);
        assignMaterial(rec);
        return rec;
    }

    void Plane::configure(const std::map<std::string, double>& params) {
        _center = {
            params.at("c.x"),
            params.at("c.y"),
            params.at("c.z")
        };
        _normal = {
            params.at("n.x"),
            params.at("n.y"),
            params.at("n.z")
        };
        setMaterial(FlatMaterial(
            (int)params.at("color.r"),
            (int)params.at("color.g"),
            (int)params.at("color.b")
        ));
        _color = {
            params.at("color.r") / 255.0,
            params.at("color.g") / 255.0,
            params.at("color.b") / 255.0
        };
    }
}

extern "C" {
    RayTracer::IPrimitive *create() {
        return new RayTracer::Plane();
    }

    const char* getType() {
        return "plane";
    }
}
