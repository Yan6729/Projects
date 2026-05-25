/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Torus
*/

#include "../../include/primitives/Torus.hpp"
#include "../../include/math/Vec3.hpp"
#include "../../include/math/Ray.hpp"
#include <cmath>
#include <limits>
#include <algorithm>

namespace RayTracer {

    Torus::Torus(const Vec3& center, double R, double r, const Vec3& color)
        : _center(center), _R(R), _r(r), _color(color) {}

    Vec3 Torus::calculateNormal(const Vec3& point) const {
        Vec3 p = point - _center;
        double factor = 1.0 - _R / std::sqrt(p.x*p.x + p.z*p.z);
        return Vec3(factor * p.x, p.y, factor * p.z).normalized();
    }

    std::vector<double> Torus::solveCubic(double a, double b, double c) const {
        double p = b - a * a / 3.0;
        double q = 2.0 * a * a * a / 27.0 - a * b / 3.0 + c;
        double D = q * q / 4.0 + p * p * p / 27.0;
        std::vector<double> roots;
        const double shift = a / 3.0;

        if (D > 1e-10) {
            double sqD = std::sqrt(D);
            double u = std::cbrt(-q / 2.0 + sqD);
            double v = std::cbrt(-q / 2.0 - sqD);
            roots.push_back(u + v - shift);
        } else if (D > -1e-10) {
            double u = std::cbrt(-q / 2.0);
            roots.push_back(2.0 * u - shift);
            roots.push_back(-u - shift);
        } else {
            double rr = std::sqrt(-p * p * p / 27.0);
            double theta = std::acos(std::clamp(-q / (2.0 * rr), -1.0, 1.0));
            double m = 2.0 * std::cbrt(rr);
            roots.push_back(m * std::cos( theta / 3.0) - shift);
            roots.push_back(m * std::cos((theta + 2.0*M_PI) / 3.0) - shift);
            roots.push_back(m * std::cos((theta + 4.0*M_PI) / 3.0) - shift);
        }
        return roots;
    }

    std::vector<double> Torus::solveQuartic(double a, double b, double c, double d, double e) const 
    {
        b /= a; c /= a; d /= a; e /= a;

        double p = c - 3.0*b*b / 8.0;
        double q = b*b*b / 8.0 - b*c / 2.0 + d;
        double r = -3.0*b*b*b*b / 256.0 + b*b*c / 16.0 - b*d / 4.0 + e;

        std::vector<double> roots;

        if (std::abs(q) < 1e-10) {
            double disc = p*p - 4.0*r;
            if (disc >= 0) {
                double sq = std::sqrt(disc);
                for (double s : {(-p + sq) / 2.0, (-p - sq) / 2.0}) {
                    if (s >= 0) {
                        roots.push_back( std::sqrt(s) - b / 4.0);
                        roots.push_back(-std::sqrt(s) - b / 4.0);
                    }
                }
            }
            return roots;
        }

        auto cubicRoots = solveCubic(p, (p*p / 4.0 - r), -q*q / 8.0);
        double m = std::numeric_limits<double>::lowest();
        for (double root : cubicRoots) {
            if (root > 1e-10 && root > m)
                m = root;
        }
        if (m <= 1e-10)
            m = *std::max_element(cubicRoots.begin(), cubicRoots.end());
        double sqrtTwoM = std::sqrt(std::abs(2.0 * m));
        if (sqrtTwoM < 1e-10) return roots;

        for (int sign : {1, -1}) {
            double qa = 1.0;
            double qb = sign * sqrtTwoM;
            double qc = m - sign * (q / (2.0 * sqrtTwoM));
            double disc = qb*qb - 4.0*qa*qc;
            if (disc >= 0) {
                double sq = std::sqrt(disc);
                roots.push_back((-qb + sq) / 2.0 - b / 4.0);
                roots.push_back((-qb - sq) / 2.0 - b / 4.0);
            }
        }
        return roots;
    }

    std::optional<HitRecord> Torus::intersect(const Ray& ray, double tMin, double tMax) const {
        Vec3 o = ray.origin - _center;
        Vec3 d = ray.direction;

        double R2 = _R * _R;
        double r2 = _r * _r;

        double dd = d.dot(d);
        double od = o.dot(d);
        double oo = o.dot(o);
        double sum = oo - R2 - r2;

        double A = dd * dd;
        double B = 4.0 * dd * od;
        double C = 2.0 * dd * sum + 4.0 * od * od - 4.0 * R2 * d.y * d.y;
        double D = 4.0 * sum * od - 8.0 * R2 * o.y * d.y;
        double E = sum * sum - 4.0 * R2 * (r2 - o.y * o.y);

        auto roots = solveQuartic(A, B, C, D, E);

        double tHit = std::numeric_limits<double>::max();
        for (double t : roots) {
            if (t > tMin && t < tMax && t < tHit)
                tHit = t;
        }

        if (tHit == std::numeric_limits<double>::max())
            return std::nullopt;

        Vec3 hitPoint = ray.at(tHit);
        Vec3 normal = calculateNormal(hitPoint);

        HitRecord rec;
        rec.t = tHit;
        rec.point = hitPoint;
        setFaceNormal(rec, ray, normal);
        assignMaterial(rec);
        rec._color = _color;
        return rec;
    }

    void Torus::configure(const std::map<std::string, double>& params) {
        _center = { params.at("x"), params.at("y"), params.at("z") };
        _R = params.at("R");
        _r = params.at("r");
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
        return new RayTracer::Torus();
    }

    const char* getType() {
        return "torus";
    }
}