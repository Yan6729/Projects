/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** TangleCube
*/

#ifndef TANGLECUBE_HPP_
    #define TANGLECUBE_HPP_
    #include "AbstractPrimitive.hpp"

namespace RayTracer {
    class TangleCube : public AbstractPrimitive {
        public:
            TangleCube(const Vec3& origin = {0, 0, 0}, const Vec3& color = {1, 1, 1});
            ~TangleCube();
            void configure(const std::map<std::string, double>& params);
            std::optional<HitRecord> intersect(
                const Ray& ray,
                double tMin,
                double tMax) const override;
        
        protected:
            Vec3 calculateNormal(const Vec3& point) const override;

        private:
            Vec3 _origin;
            double scale;
            Vec3 _color;
    };
}

#endif /* !TANGLECUBE_HPP_ */
