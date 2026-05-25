/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Vec3Utils
*/

#include "../../include/math/Vec3.hpp"

namespace RayTracer {
    bool nearZero(const Vec3& v) {
        const double eps = 1e-8;
        return std::abs(v.x) < eps && std::abs(v.y) < eps && std::abs(v.z) < eps;
    }

    Vec3 reflect(const Vec3& v, const Vec3& n) {
        return v - n * (2.0 * v.dot(n));
    }

    Vec3 refract(const Vec3& v, const Vec3& n, double niOverNt) {
        double cosTheta = std::fmin(-v.dot(n), 1.0);
        Vec3 rPerp = (v + n * cosTheta) * niOverNt;
        Vec3 rParallel = n * (-std::sqrt(std::fabs(1.0 - rPerp.lengthSquared())));
        return rPerp + rParallel;
    }

    Vec3 lerp(const Vec3& a, const Vec3& b, double t) {
        return a * (1.0 - t) + b * t;
    }

    Vec3 abs(const Vec3& v) {
        return {std::abs(v.x), std::abs(v.y), std::abs(v.z)};
    }

    Vec3 min(const Vec3& a, const Vec3& b) {
        return {std::fmin(a.x, b.x), std::fmin(a.y, b.y), std::fmin(a.z, b.z)};
    }

    Vec3 max(const Vec3& a, const Vec3& b) {
        return {std::fmax(a.x, b.x), std::fmax(a.y, b.y), std::fmax(a.z, b.z)};
    }
}