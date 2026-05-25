/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Mat4
*/

#pragma once

#include <ostream>
#include <array>
#include <cmath>
#include <stdexcept>
#include "Vec3.hpp"

namespace RayTracer {
    class Mat4 {
        public:
            std::array<std::array<double,4>, 4> m;
            Mat4();
            Mat4(double m00, double m01, double m02, double m03,
                double m10, double m11, double m12, double m13,
                double m20, double m21, double m22, double m23,
                double m30, double m31, double m32, double m33);
            Mat4 operator*(const Mat4& o) const;
            Mat4 transposed() const;
            Mat4 inverse() const;
    };
    Vec3 transformPoint(const Mat4& m, const Vec3& p);
    Vec3 transformDirection(const Mat4& m, const Vec3& d);
    Vec3 transformNormal(const Mat4& m, const Vec3& n);
    Mat4 identity();
    Mat4 translation(double tx, double ty, double tz);
    Mat4 translation(const Vec3& v);
    Mat4 rotationX(double angle);
    Mat4 vrotationY(double angle);
    Mat4 rotationZ(double angle);
    Mat4 rotation(const Vec3& axis, double angle);
    Mat4 scale(double sx, double sy, double sz);
    Mat4 scale(double s);
    Mat4 scale(const Vec3& v);
    std::ostream& operator<<(std::ostream& os, const Mat4& mat);
}