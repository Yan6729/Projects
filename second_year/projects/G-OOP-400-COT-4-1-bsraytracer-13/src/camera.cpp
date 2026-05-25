/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** camera
*/

#include "../include/camera.hpp"
using namespace RayTracer;

Camera::Camera()
    : origin(Point3D(0, 0, 0)), screen(Point3D(-1, -1, -1), Vector3D(2, 0, 0), Vector3D(0, 2, 0))
{
}

Ray Camera::ray(double u, double v)
{
    Point3D _at = screen.pointAt(u, v);
    return Ray(origin, Vector3D(_at.X - origin.X, _at.Y - origin.Y, _at.Z - origin.Z));
}