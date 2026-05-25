/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Mat4Transform
*/

#include "../../include/math/Mat4.hpp"

namespace RayTracer {
    Vec3 transformPoint(const Mat4& m, const Vec3& p)
    {
        double x = m.m[0][0]*p.x + m.m[1][0]*p.y + m.m[2][0]*p.z + m.m[3][0];
        double y = m.m[0][1]*p.x + m.m[1][1]*p.y + m.m[2][1]*p.z + m.m[3][1];
        double z = m.m[0][2]*p.x + m.m[1][2]*p.y + m.m[2][2]*p.z + m.m[3][2];
        double w = m.m[0][3]*p.x + m.m[1][3]*p.y + m.m[2][3]*p.z + m.m[3][3];
        if (std::abs(w - 1.0) > 1e-12)
            return {x/w, y/w, z/w};
        return {x, y, z};
    }


    Vec3 transformDirection(const Mat4& m, const Vec3& d)
    {
        return {
            m.m[0][0]*d.x + m.m[1][0]*d.y + m.m[2][0]*d.z,
            m.m[0][1]*d.x + m.m[1][1]*d.y + m.m[2][1]*d.z,
            m.m[0][2]*d.x + m.m[1][2]*d.y + m.m[2][2]*d.z
        };
    }


    Vec3 transformNormal(const Mat4& m, const Vec3& n)
    {
        Mat4 invT = m.inverse().transposed();
        return transformDirection(invT, n);
    }
}
