/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Mat4Factories
*/

#include "../../include/math/Mat4.hpp"

namespace RayTracer {
    Mat4 identity() {
        return Mat4{};
    }

    Mat4 translation(double tx, double ty, double tz) {
        Mat4 t;
        t.m[3][0] = tx;
        t.m[3][1] = ty;
        t.m[3][2] = tz;
        return t;
    }

    Mat4 translation(const Vec3& v) {
        return translation(v.x, v.y, v.z);
    }

    Mat4 rotationX(double angle) {
        Mat4 r;
        double c = std::cos(angle), s = std::sin(angle);
        r.m[1][1] =  c; r.m[2][1] = -s;
        r.m[1][2] =  s; r.m[2][2] =  c;
        return r;
    }

    Mat4 vrotationY(double angle) {
        Mat4 r;
        double c = std::cos(angle), s = std::sin(angle);
        r.m[0][0] =  c; r.m[2][0] =  s;
        r.m[0][2] = -s; r.m[2][2] =  c;
        return r;
    }

    Mat4 rotationZ(double angle) {
        Mat4 r;
        double c = std::cos(angle), s = std::sin(angle);
        r.m[0][0] =  c; r.m[1][0] = -s;
        r.m[0][1] =  s; r.m[1][1] =  c;
        return r;
    }

    Mat4 rotation(const Vec3& axis, double angle) {
        Vec3 u = axis.normalized();
        double c = std::cos(angle), s = std::sin(angle), t = 1.0 - c;
        double x = u.x, y = u.y, z = u.z;
        return Mat4(
            t*x*x+c,   t*x*y-s*z, t*x*z+s*y, 0,
            t*x*y+s*z, t*y*y+c,   t*y*z-s*x, 0,
            t*x*z-s*y, t*y*z+s*x, t*z*z+c,   0,
            0,         0,         0,          1
        );
    }

    Mat4 scale(double sx, double sy, double sz) {
        Mat4 s;
        s.m[0][0] = sx;
        s.m[1][1] = sy;
        s.m[2][2] = sz;
        return s;
    }

    Mat4 scale(double s)
    {
        return scale(s, s, s);
    }

    Mat4 scale(const Vec3& v)
    {
        return scale(v.x, v.y, v.z);
    }
}