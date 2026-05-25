/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** triangle
*/

#include "../../include/primitives/Triangle.hpp"
#include "../../include/math/Vec3.hpp"
#include "../../include/math/Ray.hpp"
#include <cmath>

namespace RayTracer {
    Triangle::Triangle(const Vec3& v0, const Vec3& v1, const Vec3& v2, const Vec3& color)
        : _v0(v0), _v1(v1), _v2(v2), _color(color)
    {
        _normal = (_v1 - _v0).cross(_v2 - _v0).normalized();
    }

    Vec3 Triangle::calculateNormal(const Vec3& point) const {
        (void)point;
        return _normal;
    }

    std::optional<HitRecord> Triangle::intersect(const Ray& ray, double tMin, double tMax) const {
        constexpr double EPSILON = 1e-8;

        Vec3 edge1 = _v1 - _v0;
        Vec3 edge2 = _v2 - _v0;
        Vec3 h = ray.direction.cross(edge2);
        double a = edge1.dot(h);

        if (std::abs(a) < EPSILON)
            return std::nullopt;

        double f = 1.0 / a;
        Vec3 s = ray.origin - _v0;
        double u = f * s.dot(h);

        if (u < 0.0 || u > 1.0)
            return std::nullopt;

        Vec3 q = s.cross(edge1);
        double v = f * ray.direction.dot(q);

        if (v < 0.0 || u + v > 1.0)
            return std::nullopt;

        double t = f * edge2.dot(q);
        if (t < tMin || t > tMax)
            return std::nullopt;

        Vec3 hitPoint = ray.at(t);
        // Vec3 normal = (a < 0) ? -_normal : _normal;
        Vec3 normal = (a < 0) ? _normal * -1.0 : _normal;

        return HitRecord{t, hitPoint, normal, true, FlatMaterial(), _color};
    }

    void Triangle::configure(const std::map<std::string, double>& params) {
        _v0 = { params.at("x0"), params.at("y0"), params.at("z0") };
        _v1 = { params.at("x1"), params.at("y1"), params.at("z1") };
        _v2 = { params.at("x2"), params.at("y2"), params.at("z2") };
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
        _normal = (_v1 - _v0).cross(_v2 - _v0).normalized();
    }
}

extern "C" {
    RayTracer::IPrimitive *create() {
        return new RayTracer::Triangle();
    }

    const char* getType() {
        return "triangle";
    }
}