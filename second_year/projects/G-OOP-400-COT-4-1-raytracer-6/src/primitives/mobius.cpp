#include "../../include/primitives/Mobius.hpp"
#include "../../include/math/Ray.hpp"

#include <cmath>
#include <limits>

namespace RayTracer {

    static constexpr double TWO_PI = 2.0 * M_PI;
    static constexpr int U_STEPS = 120;
    static constexpr int V_STEPS = 20;

    Mobius::Mobius(const Vec3& center, double radius, double width, const Vec3& color)
        : _center(center), _R(radius), _w(width), _color(color)
    {
        buildMesh();
    }

    void Mobius::configure(const std::map<std::string, double>& params) {
        _center = {
            params.at("x"),
            params.at("y"),
            params.at("z")
        };
        _R = params.at("R");
        _w = params.at("w");
        _color = {
            params.at("color.r") / 255.0,
            params.at("color.g") / 255.0,
            params.at("color.b") / 255.0
        };
        setMaterial(
            FlatMaterial(
                (int)params.at("color.r"),
                (int)params.at("color.g"),
                (int)params.at("color.b")
            )
        );
        buildMesh();
    }

    Vec3 Mobius::surface(double u, double v) const {
        double cu = std::cos(u);
        double su = std::sin(u);
        double cu2 = std::cos(u / 2.0);
        double su2 = std::sin(u / 2.0);
        double r = _R + v * cu2;
        return Vec3(
            _center.x + r * cu,
            _center.y + r * su,
            _center.z + v * su2
        );
    }
    void Mobius::buildMesh()
    {
        _mesh.clear();
        _mesh.reserve(U_STEPS * V_STEPS * 2);
        for (int iu = 0; iu < U_STEPS; ++iu) {
            double u0 = TWO_PI * iu / U_STEPS;
            double u1 = TWO_PI * (iu + 1) / U_STEPS;
            for (int iv = 0; iv < V_STEPS; ++iv) {
                double v0 = -_w + (2.0 * _w * iv       / V_STEPS);
                double v1 = -_w + (2.0 * _w * (iv + 1) / V_STEPS);
                Vec3 p00 = surface(u0, v0);
                Vec3 p01 = surface(u0, v1);
                Vec3 p10 = surface(u1, v0);
                Vec3 p11 = surface(u1, v1);
                Triangle t1;
                t1.a = p00;
                t1.b = p10;
                t1.c = p11;
                t1.normal = (p10 - p00).cross(p11 - p00).normalized();

                Triangle t2;
                t2.a = p00;
                t2.b = p11;
                t2.c = p01;
                t2.normal = (p11 - p00).cross(p01 - p00).normalized();
                _mesh.push_back(t1);
                _mesh.push_back(t2);
            }
        }
    }

    bool Mobius::intersectTriangle(const Ray& ray, const Triangle& tri, double& t) const {
        const double EPS = 1e-8;
        Vec3 edge1 = tri.b - tri.a;
        Vec3 edge2 = tri.c - tri.a;
        Vec3 h = ray.direction.cross(edge2);
        double a = edge1.dot(h);
        if (std::abs(a) < EPS)
            return false;
        double f = 1.0 / a;
        Vec3 s = ray.origin - tri.a;
        double u = f * s.dot(h);
        if (u < 0.0 || u > 1.0)
            return false;
        Vec3 q = s.cross(edge1);
        double v = f * ray.direction.dot(q);
        if (v < 0.0 || u + v > 1.0)
            return false;
        t = f * edge2.dot(q);
        return t > EPS;
    }

    static bool sphereTest(const Ray& ray, const Vec3& center, double radius) {
        Vec3 oc = ray.origin - center;
        double a = ray.direction.dot(ray.direction);
        double b = 2.0 * oc.dot(ray.direction);
        double c = oc.dot(oc) - radius * radius;
        double delta = b * b - 4.0 * a * c;
        return delta >= 0.0;
    }

    std::optional<HitRecord> Mobius::intersect(const Ray& ray, double tMin, double tMax) const {
        if (!sphereTest(ray, _center, _R + _w))
            return std::nullopt;

        bool found = false;
        double closest = tMax;
        HitRecord rec;
        for (const auto& tri : _mesh) {
            double t;
            if (!intersectTriangle(ray, tri, t))
                continue;
            if (t < tMin || t > closest)
                continue;
            closest = t;
            rec.t = t;
            rec.point = ray.at(t);
            rec.normal = (tri.normal.dot(ray.direction) > 0.0) ? tri.normal * -1.0 : tri.normal;
            rec._color = _color;
            found  = true;
        }

        if (!found)
            return std::nullopt;

        assignMaterial(rec);
        return rec;
    }

    Vec3 Mobius::calculateNormal(const Vec3& point) const {
        double bestDist = std::numeric_limits<double>::max();
        Vec3   bestNormal(0.0, 1.0, 0.0);

        for (const auto& tri : _mesh) {
            Vec3 centroid = (tri.a + tri.b + tri.c) * (1.0 / 3.0);
            Vec3 diff = point - centroid;
            double dist = diff.dot(diff);
            if (dist < bestDist) {
                bestDist = dist;
                bestNormal = tri.normal;
            }
        }
        return bestNormal;
    }

}

extern "C" {
    RayTracer::IPrimitive* create() {
        return new RayTracer::Mobius();
    }

    const char* getType() {
        return "mobius";
    }
}