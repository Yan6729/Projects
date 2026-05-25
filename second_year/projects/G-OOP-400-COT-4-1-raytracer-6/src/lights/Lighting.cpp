/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Lighting
*/


#include "../../include/lights/Lighting.hpp"

namespace RayTracer {

static void accumulateLights(
    Color& result,
    const HitRecord& hit,
    const Color& surfaceColor,
    const Scene::LightList& lights)
{
    for (const auto& light : lights)
        result += light->illuminate(hit, surfaceColor);
}

bool isOccluded(
    const Vec3& origin,
    const Vec3& direction,
    double tMax,
    const Scene& scene
) {
    Ray shadowRay(origin, direction);

    for (const auto& type : scene.primitives_presents) {
        for (const auto& prim : scene.getPrimitives(type)) {
            if (prim->intersect(shadowRay, 1e-4, tMax)) {
                return true;
            }
        }
    }
    return false;
}

Color computeLighting(
    const HitRecord& hit,
    const Color& surfaceColor,
    const Scene& scene)
{
    Color result(0.0, 0.0, 0.0);

    if (const Scene::LightList* ambient = scene.findLights("ambient"))
        accumulateLights(result, hit, surfaceColor, *ambient);
    if (const Scene::LightList* directional = scene.findLights("directional")) {
        for (const auto& it : *directional) {
            auto dl = static_cast<DirectionalLight *>(it.get());
            Vec3 shadowDirection = (dl->_direction).normalized();
            if (!(isOccluded(hit.point, shadowDirection, 1e9, scene))) {
                result += it->illuminate(hit, surfaceColor);
            }
        }
    }
    if (const Scene::LightList* point = scene.findLights("point")) {
        for (const auto& it : *point) {
            auto pl = static_cast<PointLight *>(it.get());
            Vec3 toLight = pl->_position - hit.point;
            double dist = toLight.length();
            if (!(isOccluded(hit.point, toLight / dist, dist, scene))) {
                result += it->illuminate(hit, surfaceColor);
            }
        }
    }

    return result.clamped01();
}

}
