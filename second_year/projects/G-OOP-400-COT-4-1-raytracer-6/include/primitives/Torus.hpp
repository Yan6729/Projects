/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Torus
*/

#pragma once

#include "AbstractPrimitive.hpp"
#include <vector>

namespace RayTracer {
    class Torus : public AbstractPrimitive {
        public:
            Torus(const Vec3& center = {0,0,0}, double R = 2.0, double r = 0.5, const Vec3& color = {1,1,1});
            virtual ~Torus() noexcept = default;
            void configure(const std::map<std::string, double>& params);
            std::optional<HitRecord> intersect(
                const Ray& ray,
                double tMin,
                double tMax) const override;

        protected:
            Vec3 calculateNormal(const Vec3& point) const override;

        private:
            Vec3   _center;
            double _R; 
            double _r;
            Vec3   _color;

            std::vector<double> solveQuartic(double a, double b, double c, double d, double e) const;
            std::vector<double> solveCubic(double a, double b, double c) const;
    };
}
