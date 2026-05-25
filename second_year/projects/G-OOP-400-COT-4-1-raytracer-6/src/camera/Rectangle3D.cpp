/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Rectangle3D
*/

#include "../../include/camera/Rectangle3D.hpp"
using namespace RayTracer;

Rectangle3D::Rectangle3D(Vec3 o, Vec3 i, Vec3 j)
    : _O(o), _I(i), _J(j)
{
}

Rectangle3D::Rectangle3D()
    : _O(Vec3(0.0, 0.0, 0.0)), _I(Vec3(1.0, 0.0, 0.0)), _J(Vec3(0.0, 1.0, 0.0))
{
}

Rectangle3D::~Rectangle3D()
{
}

Vec3 Rectangle3D::convertTo3D(double u, double v) const
{
    return _O + (_I * u) + (_J * v);
}
