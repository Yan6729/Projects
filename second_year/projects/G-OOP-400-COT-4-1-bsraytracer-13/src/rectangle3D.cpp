/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** rectangle3D
*/

#include "../include/rectangle3D.hpp"
using namespace Math;
using namespace RayTracer;

Rectangle3D::Rectangle3D(Point3D givenOrigin, Vector3D givenBotton, Vector3D givenLeft)
    : origin(givenOrigin), bottom_side(givenBotton), left_side(givenLeft)
{}

Point3D Rectangle3D::pointAt(double u, double v)
{
    if (u < 0 || u > 1 || v < 0 || v > 1 )
        return Point3D(-1.0, -1.0, -1.0);
    return origin + (bottom_side * u) + (left_side * v);
}
