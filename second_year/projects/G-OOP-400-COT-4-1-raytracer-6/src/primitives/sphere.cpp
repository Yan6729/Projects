/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** sphere
*/

#include "../../include/primitives/Sphere.hpp"
#include "../../include/primitives/HitRecord.hpp"
#include "../../include/math/Ray.hpp"
#include <cmath>

namespace RayTracer {

    Sphere::Sphere(const Vec3& center, double radius, const Vec3& color)
        : _center(center), _radius(radius), _color(color) {}

    void Sphere::setCenter(const Vec3& center) {
        _center = center;
    }
    void Sphere::setRadius(double radius) {
        _radius = radius;
    }
    void Sphere::setColor(const Vec3& color) {
        _color = color;
    }

    Vec3 Sphere::calculateNormal(const Vec3& point) const {
        return (point - _center).normalized();
    }

    std::optional<HitRecord> Sphere::intersect(const Ray& ray, double tMin, double tMax) const
    {
        Vec3 oc = ray.origin - _center;
        double a = ray.direction.dot(ray.direction);
        double b = 2.0 * oc.dot(ray.direction);
        double c = oc.dot(oc) - _radius * _radius;
        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) return std::nullopt;

        double sqrtD = std::sqrt(discriminant);
        double t = (-b - sqrtD) / (2.0 * a);
        if (t < tMin || t > tMax) {
            t = (-b + sqrtD) / (2.0 * a);
            if (t < tMin || t > tMax)
                return std::nullopt;
        }

        HitRecord rec;
        rec.t = t;
        rec.point = ray.at(t);
        rec._color = _color;
        setFaceNormal(rec, ray, (rec.point - _center) / _radius); 
        assignMaterial(rec);
        return rec;
    }

    void Sphere::configure(const std::map<std::string, double>& params)
    {
        _center = {
            params.at("x"),
            params.at("y"),
            params.at("z"),
        };
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
        return new RayTracer::Sphere();
    }

    const char* getType() {
        return "sphere";
    }
}
