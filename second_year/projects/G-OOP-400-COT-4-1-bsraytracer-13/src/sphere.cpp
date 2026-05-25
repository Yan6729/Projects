/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** sphere
*/

#include "../include/sphere.hpp"
using namespace RayTracer;

Sphere::Sphere(const Point3D& givenCenter, double givenRadius)
    : center(givenCenter), radius(givenRadius)
{}

bool Sphere::hits(const Ray& ray)
{
    Vector3D origin_center = ray.origin - center;
    double a = ray.direction.dot(ray.direction);
    double b = 2 * ray.direction.dot(origin_center);
    double c  = origin_center.dot(origin_center) - pow(radius, 2);

    double discriminant = pow(b, 2) - (4 * a * c);
    if (discriminant >= 0)
        return true;
    return false;
}
