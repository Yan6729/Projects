/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** cylinder
*/

#include "../../include/primitives/Cylinder.hpp"
#include "../../include/math/Vec3.hpp"
#include "../../include/math/Ray.hpp"
#include <cmath>

namespace RayTracer {
    Cylinder::Cylinder(const Vec3& center, double radius, double height, const Vec3& color)
        : _center(center), _radius(radius), _height(height), _color(color) {}

    Vec3 Cylinder::calculateNormal(const Vec3& point) const {
        Vec3 n = (point - _center);
        n.y = 0;
        return n.normalized();
    }

    std::optional<HitRecord> Cylinder::intersect(const Ray& ray, double tMin, double tMax) const {
        Vec3 oc = ray.origin - _center;
        double a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
        double b = 2.0 * (oc.x * ray.direction.x + oc.z * ray.direction.z);
        double c = oc.x * oc.x + oc.z * oc.z - _radius * _radius;

        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) return std::nullopt;

        double sqrtD = std::sqrt(discriminant);

        auto isValid = [&](double t) {
            if (t < tMin || t > tMax) return false;
            double hitY = ray.at(t).y;
            return hitY >= _center.y - _height / 2.0 && hitY <= _center.y + _height / 2.0;
        };

        double t = (-b - sqrtD) / (2.0 * a);
        if (!isValid(t)) {
            t = (-b + sqrtD) / (2.0 * a);
            if (!isValid(t)) return std::nullopt;
        }

        HitRecord rec;
        rec.t     = t;
        rec.point = ray.at(t);
        rec._color = _color;
        setFaceNormal(rec, ray, Vec3{rec.point.x - _center.x, 0, rec.point.z - _center.z});
        assignMaterial(rec);
        return rec;
    }

    void Cylinder::configure(const std::map<std::string, double>& params) {
        _center = {
            params.at("x"),
            params.at("y"),
            params.at("z"),
        };
        _height = params.at("height");
        _radius = params.at("r");
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
        return new RayTracer::Cylinder();
    }

    const char* getType() {
        return "cylinder";
    }
}