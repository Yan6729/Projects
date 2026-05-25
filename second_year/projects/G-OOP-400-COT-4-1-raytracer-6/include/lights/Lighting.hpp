/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Lighting
*/

#ifndef LIGHTING_HPP_
    #define LIGHTING_HPP_

    #include "Color.hpp"
    #include "../primitives/HitRecord.hpp"
    #include "../scene/Scene.hpp"
    #include "PointLight.hpp"
    #include "DirectionalLight.hpp"

namespace RayTracer {
    Color computeLighting(
        const HitRecord& hit,
        const Color& surfaceColor,
        const Scene& scene);
    bool isOccluded(
        const Vec3& origin,
        const Vec3& direction,
        double tMax,
        const Scene& scene
    );
}

#endif /* !LIGHTING_HPP_ */
