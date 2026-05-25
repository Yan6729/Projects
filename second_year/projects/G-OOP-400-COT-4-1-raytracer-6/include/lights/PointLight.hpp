/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** PointLight
*/

#ifndef POINTLIGHT_HPP_
    #define POINTLIGHT_HPP_
    #include "ILights.hpp"
    #include "../scene/SceneData.hpp"
    #include "../primitives/HitRecord.hpp"
    #include "../math/Vec3.hpp"

namespace RayTracer {
    class PointLight : public ILight {
        public:
            Color _color = Color(1.0, 1.0, 1.0);
            Vec3 _position;
            PointLight();
            ~PointLight();
            PointLight(const Vec3& position, double intensity);
            Color illuminate(const HitRecord& hit, const Color& surfaceColor) const override;
        private:
            double _intensity;
};
}
#endif /* !POINTLIGHT_HPP_ */
