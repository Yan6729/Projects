/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Vec3
*/

#include "../../include/math/Vec3.hpp"
using namespace RayTracer;

Vec3::Vec3()
    : x(0), y(0), z(0)
{
}

Vec3::Vec3(double Valx, double Valy, double Valz)
    : x(Valx), y(Valy), z(Valz)
{}

Vec3::Vec3(double v)
    : x(v), y(v), z(v)
{}

double Vec3::dot(const Vec3& o) const
{
    return (x * o.x) + (y * o.y) + (z * o.z);
}

Vec3 Vec3::cross(const Vec3& o) const
{
    return {
        (y * o.z) - (z * o.y),
        (z * o.x) - (x * o.z),
        (x * o.y) - (y * o.x)
    };
}

double Vec3::lengthSquared() const
{
    return (x * x) + (y * y) + (z * z);
}

double Vec3::length() const
{
    return sqrt(lengthSquared());
}

Vec3 Vec3::normalized() const {
    double l = length();
    if (l < 1e-12 || l == 0)
        throw std::runtime_error("Vec3::normalized() called on zero vector");
    return { (x / l), (y / l), (z / l) };
}

double vec3Get(const Vec3& v, int i)
{
    switch(i) {
        case 0:
            return v.x;
            break;
        case 1:
            return v.y;
            break;
        case 2:
            return v.z;
            break;
        default:
            throw std::out_of_range("Vec3: index out of range");
            break;
    }
}

double& vec3Ref(Vec3& v, int i)
{
    switch(i) {
        case 0:
            return v.x;
            break;
        case 1:
            return v.y;
            break;
        case 2:
            return v.z;
            break;
        default:
            throw std::out_of_range("Vec3: index out of range");
            break;
    }
}

ostream& operator<<(ostream& os, const RayTracer::Vec3& v) {
    return os << "Vec3(" << v.x << ", " << v.y << ", " << v.z << ")";
}
