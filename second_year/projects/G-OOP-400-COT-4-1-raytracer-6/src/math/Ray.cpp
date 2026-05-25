/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Ray
*/

#include "../../include/math/Ray.hpp"
using namespace RayTracer;

Ray::Ray(const Vec3& origin, const Vec3& direction)
    : origin(origin), direction(direction)
{}

Vec3 Ray::at(double t) const
{
    return origin + direction * t;
}
