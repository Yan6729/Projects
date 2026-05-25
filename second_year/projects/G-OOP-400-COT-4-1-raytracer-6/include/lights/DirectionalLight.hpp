/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** DirectionalLight
*/


#ifndef DIRECTIONAL_LIGHT_HPP
#define DIRECTIONAL_LIGHT_HPP

#include "ILights.hpp"
    #include "ILights.hpp"
    #include "../math/Vec3.hpp"

namespace RayTracer {
    class DirectionalLight : public ILight {
        public:
            Color _color = Color(1.0, 1.0, 1.0);
            DirectionalLight(const Vec3& direction, double diffuse);
            Vec3 _direction;

            Color illuminate(
                const HitRecord& hit,
                const Color& surfaceColor) const override;

        private:
            double _diffuse;
    };
}

#endif