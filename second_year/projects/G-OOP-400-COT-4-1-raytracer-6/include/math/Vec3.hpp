/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Vec3
*/

#pragma once

    #include <cmath>
    #include <stdexcept>
    using namespace std;
    #include "../rayTracerError.hpp"

namespace RayTracer {
    class Vec3 {
        public:
            double x;
            double y;
            double z;
            Vec3();
            Vec3(double Valx, double Valy, double  Valz);
            explicit Vec3(double v);
            double dot(const Vec3& o) const;
            Vec3 cross(const Vec3& o) const;
            double lengthSquared() const;
            double length() const;
            Vec3 normalized() const;
            Vec3 operator+(const Vec3& other) const;
            Vec3 operator-(const Vec3& other) const;
            Vec3 operator*(double t) const;
            Vec3 operator*(const Vec3& other) const;
            Vec3 operator/(double t) const;
            Vec3 operator/(const Vec3& other) const;
            Vec3 operator+=(const Vec3& other);
            Vec3 operator-=(const Vec3& other);
            Vec3 operator*=(double t);
            Vec3 operator/=(double t);
            Vec3 operator*=(const Vec3& other);
            Vec3 operator/=(const Vec3& other);
            bool operator==(const Vec3& other) const;
            bool operator!=(const Vec3& other) const;
    };
    double vec3Get(const Vec3& v, int i);
    double& vec3Ref(Vec3& v, int i);
    bool nearZero(const Vec3& v);
    Vec3 reflect(const Vec3& v, const Vec3& n);
    Vec3 refract(const Vec3& v, const Vec3& n, double niOverNt);
    Vec3 lerp(const Vec3& a, const Vec3& b, double t);
    Vec3 abs(const Vec3& v);
    Vec3 min(const Vec3& a, const Vec3& b);
    Vec3 max(const Vec3& a, const Vec3& b);
    ostream& operator<<(ostream& os, const RayTracer::Vec3& v);
}
