/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** ray
*/

#include "../include/ray.hpp"
using namespace RayTracer;

Ray::Ray(const Point3D& givenOrigin, const Vector3D& givenDirection)
    : origin(givenOrigin), direction(givenDirection)
{}
