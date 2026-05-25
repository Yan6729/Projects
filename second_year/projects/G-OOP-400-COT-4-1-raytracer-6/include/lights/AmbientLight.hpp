/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** AmbientLight
*/


#ifndef AMBIENT_LIGHT_HPP
#define AMBIENT_LIGHT_HPP
    #include "ILights.hpp"

namespace RayTracer
{
    class AmbientLight : public ILight {
        public:
            explicit AmbientLight(double intensity);

            Color illuminate(
                const HitRecord& hit,
                const Color& surfaceColor) const override;

        private:
            double _intensity;
    };
}

#endif