/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** cone
*/

#include "../../include/primitives/Cone.hpp"
#include "../../include/math/Vec3.hpp"
#include "../../include/math/Ray.hpp"
#include <cmath>

namespace RayTracer
{
    Cone::Cone(const Vec3 &center, double radius, double height, const Vec3 &color)
        : _center(center), _radius(radius), _height(height), _color(color) {}

    Vec3 Cone::calculateNormal(const Vec3 &point) const
    {
        Vec3 n = (point - _center);
        n.y = -std::sqrt(n.x * n.x + n.z * n.z);
        return n.normalized();
    }

    std::optional<HitRecord> Cone::intersect(const Ray &ray, double tMin, double tMax) const
    {
        Vec3 oc = ray.origin - _center;
        double k = _radius / _height;
        double k2 = k * k;

        double a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z
                - k2 * ray.direction.y * ray.direction.y;
        double b = 2.0 * (oc.x * ray.direction.x + oc.z * ray.direction.z
                - k2 * oc.y * ray.direction.y);
        double c = oc.x * oc.x + oc.z * oc.z - k2 * oc.y * oc.y;

        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
            return std::nullopt;

        double sqrtD = std::sqrt(discriminant);
        auto tryT = [&](double t) -> std::optional<double> {
            if (t < tMin || t > tMax) return std::nullopt;
            double hitY = ray.at(t).y - _center.y;
            if (hitY < 0.0 || hitY > _height) return std::nullopt;
            return t;
        };

        auto tOpt = tryT((-b - sqrtD) / (2.0 * a));
        if (!tOpt) tOpt = tryT((-b + sqrtD) / (2.0 * a));
        if (!tOpt) return std::nullopt;

        HitRecord rec;
        rec.t = *tOpt;
        rec.point = ray.at(rec.t);
        rec._color = _color;

        Vec3 local = rec.point - _center;
        const Vec3 outward{
            local.x,
            -std::sqrt(local.x * local.x + local.z * local.z) * k,
            local.z
        };
        setFaceNormal(rec, ray, outward.normalized());
        assignMaterial(rec);
        return rec;
    }

    void Cone::configure(const std::map<std::string, double> &params)
    {
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

extern "C"
{
    RayTracer::IPrimitive *create()
    {
        return new RayTracer::Cone();
    }

    const char *getType()
    {
        return "cone";
    }
}
