/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Vec3Operators
*/

#include "../../include/math/Vec3.hpp"
using namespace RayTracer;

Vec3 Vec3::operator+(const Vec3& other) const
{
    return {
        x + other.x,
        y + other.y,
        z + other.z,
    };
}

Vec3 Vec3::operator-(const Vec3& other) const
{
    return {
        x - other.x,
        y - other.y,
        z - other.z,
    };
}

Vec3 Vec3::operator*(double t) const
{
    return {
        x * t,
        y * t,
        z * t,
    };
}

Vec3 Vec3::operator*(const Vec3& other) const
{
    return {
        x * other.x,
        y * other.y,
        z * other.z,
    };
}

Vec3 Vec3::operator/(double t) const
{
    if (t == 0) {
        throw RayTracerError("you can't divide anything by 0...");
    }
    return {
        x / t,
        y / t,
        z / t,
    };
}

Vec3 Vec3::operator/(const Vec3& other) const
{
    double newX = other.x == 0 ? 0 : x / other.x;
    double newY = other.y == 0 ? 0 : y / other.y;
    double newZ = other.z == 0 ? 0 : z / other.z;

    return {
        newX,
        newY,
        newZ,
    };
}

Vec3 Vec3::operator+=(const Vec3& other)
{
    Vec3 result = *this + other;
    *this = result;
    return *this;
}

Vec3 Vec3::operator-=(const Vec3& other)
{
    Vec3 result = *this - other;
    *this = result;
    return *this;
}

Vec3 Vec3::operator*=(double t)
{
    Vec3 result = *this * t;
    *this = result;
    return *this;
}

Vec3 Vec3::operator/=(double t)
{
    Vec3 result = *this / t;
    *this = result;
    return *this;
}

Vec3 Vec3::operator*=(const Vec3& other)
{
    Vec3 result = *this * other;
    *this = result;
    return *this;
}

Vec3 Vec3::operator/=(const Vec3& other)
{
    Vec3 result = *this / other;
    *this = result;
    return *this;
}

bool Vec3::operator==(const Vec3& other) const
{
    return (x == other.x) && (y == other.y) && (z == other.z);
}

bool Vec3::operator!=(const Vec3& other) const
{
    return !(*this == other);
}
