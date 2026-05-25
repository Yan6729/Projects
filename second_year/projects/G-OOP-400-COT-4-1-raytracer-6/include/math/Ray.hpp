/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Ray
*/

#pragma once

#include "Vec3.hpp"

namespace RayTracer {
    struct Ray {
        Vec3 origin;
        Vec3 direction;

        Ray() = default;
        Ray(const Vec3& origin, const Vec3& direction);
        Vec3 at(double t) const;
    };
}
