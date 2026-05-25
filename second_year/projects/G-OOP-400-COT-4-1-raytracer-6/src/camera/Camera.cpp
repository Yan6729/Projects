/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Camera
*/

#include "../../include/camera/Camera.hpp"

using namespace RayTracer;

Camera::Camera()
{}

Camera::~Camera()
{}

Ray Camera::thorwRay(double u, double v)
{
    Vec3 _pointAt = this->screen.convertTo3D(u, v);

    return Ray(this->origin, _pointAt - this->origin);
}
