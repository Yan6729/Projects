/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** TangleCube
*/

#include "../../include/primitives/TangleCube.hpp"

namespace RayTracer {
    TangleCube::TangleCube(const Vec3& origin, const Vec3& color)
        : _origin(origin), _color(color)
    {}

    TangleCube::~TangleCube()
    {}

    Vec3 TangleCube::calculateNormal(const Vec3& point) const
    {
        return Vec3 {
            (4 * point.x * point.x * point.x) - 10 * point.x,
            (4 * point.y * point.y * point.y) - 10 * point.y,
            (4 * point.z * point.z * point.z) - 10 * point.z
        };
    }


    std::optional<HitRecord> TangleCube::intersect(const Ray& ray, double tMin, double tMax) const {
        Vec3 toOrigin = _origin - ray.origin;
        double tCenter = toOrigin.dot(ray.direction);
        double localMax = scale * 3.0;
        double clampedMin = std::max(tMin, tCenter - localMax);
        double clampedMax = std::min(tMax, tCenter + localMax);

        if (clampedMin > clampedMax)
            return std::nullopt;
        auto f = [&](double t) {
            auto p = (ray.at(t) - _origin) / scale;
            return (p.x * p.x * p.x * p.x) - (5 * p.x * p.x) +
                (p.y * p.y * p.y * p.y) - (5 * p.y * p.y) +
                (p.z * p.z * p.z * p.z) - (5 * p.z * p.z) + 11.8;
        };

        double step = 0.01 * scale;
        double t = clampedMin;
        double previous = f(t);
        while (t < clampedMax) {
            t += step;
            double current = f(t);
            if (current * previous < 0) {
                double lowerBound = t - step;
                double upperBound = t;
                for (int a = 0; a < 32; a++) {
                    double middle = (lowerBound + upperBound) / 2.0;
                    if (f(lowerBound) * f(middle) < 0)
                        upperBound = middle;
                    else
                        lowerBound = middle;
                }
                double tHit = (lowerBound + upperBound) / 2.0;
                HitRecord rec;
                rec.t = tHit;
                rec.point = ray.at(tHit);
                rec._color = _color;
                Vec3 normal = calculateNormal((rec.point - _origin) / scale);
                setFaceNormal(rec, ray, normal.normalized());
                assignMaterial(rec);
                return rec;
            }
            previous = current;
        }
        return std::nullopt;
    }

    void TangleCube::configure(const std::map<std::string, double>& params) {
        _origin = Vec3 {
            params.at("x"),
            params.at("y"),
            params.at("z")
        };

        scale = params.at("scale");
        setMaterial(FlatMaterial(
            (int)params.at("color.r"),
            (int)params.at("color.g"),
            (int)params.at("color.b")
        ));
        _color = Vec3 {
            params.at("color.r") / 255.0,
            params.at("color.g") / 255.0,
            params.at("color.b") / 255.0
        };
    }
}

extern "C" {
    RayTracer::IPrimitive *create() {
        return new RayTracer::TangleCube();
    }

    const char* getType() {
        return "tangle";
    }
}
