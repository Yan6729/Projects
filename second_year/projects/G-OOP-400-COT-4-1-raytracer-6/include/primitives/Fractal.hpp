/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Fractal
*/

#ifndef FRACTAL_HPP_
    #define FRACTAL_HPP_
    #include "AbstractPrimitive.hpp"
    #include "../math/Vec3.hpp"
    #include <map>
    #include <string>
    #include <optional>

namespace RayTracer {
    class Fractal : public AbstractPrimitive {
        public:
            Fractal() = default;
            Fractal(const Vec3& center, int iterations, double power, const Vec3& color);
            ~Fractal() = default;

            void setCenter(const Vec3& center);
            void setIterations(int iterations);
            void setPower(double power);
            void setColor(const Vec3& color);

            std::optional<HitRecord> intersect(const Ray& ray, double tMin, double tMax) const override;
            Vec3 calculateNormal(const Vec3& point) const override;
            void configure(const std::map<std::string, double>& params) override;

        private:
            Vec3 _center;
            int _iterations;
            double _power;
            Vec3 _color;

            double MandelbulbDE(const Vec3& pos) const;
    };
}

#endif /* !FRACTAL_HPP_ */
