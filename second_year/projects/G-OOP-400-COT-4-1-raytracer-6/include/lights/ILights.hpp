/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** ILights
*/

#ifndef ILIGHTS_HPP_
    #define ILIGHTS_HPP_
    #include "Color.hpp"

namespace RayTracer {
    struct HitRecord;

    class ILight {
        public:
            virtual ~ILight() = default;
            virtual Color illuminate(
                const HitRecord& hit,
                const Color& surfaceColor) const = 0;
    };
}

#endif /* !ILIGHTS_HPP_ */
