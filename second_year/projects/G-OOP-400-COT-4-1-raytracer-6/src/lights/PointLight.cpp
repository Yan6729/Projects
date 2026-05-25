/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** PointLight
*/

#include "../../include/lights/PointLight.hpp"

namespace RayTracer {
    PointLight::PointLight()
        : _position(Vec3(0, 0, 0)), _intensity(2.0)
    {}

    PointLight::PointLight(const Vec3& position, double intensity)
        : _position(position), _intensity(intensity)
    {}

    PointLight::~PointLight()
    {}

    Color PointLight::illuminate(const HitRecord& hit, const Color& surfaceColor) const {
        Vec3 toLight = _position - hit.point;
        double dist = toLight.length();
        Vec3 lightDir = toLight / dist;

        double lambert = std::max(0.0, hit.normal.dot(lightDir));
        double attenuation = 1.0 / (1.0 + 0.0001 * dist * dist);
        return surfaceColor * _color * (_intensity * lambert * attenuation);
    }
}