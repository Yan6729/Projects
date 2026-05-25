#pragma once

#include "AbstractPrimitive.hpp"

namespace RayTracer {
    class Sphere : public AbstractPrimitive {
        public:
            Sphere(const Vec3& center = {0,0,0}, double radius = 1.0, const Vec3& color = {1,1,1});

            std::optional<HitRecord> intersect(
                const Ray& ray,
                double tMin,
                double tMax) const override;
            void configure(const std::map<std::string, double>& params);
            void setCenter(const Vec3& center);
            void setRadius(double radius);
            void setColor(const Vec3& color);

        protected:
            Vec3 calculateNormal(const Vec3& point) const override;

        private:
            Vec3 _center;
            double _radius;
            Vec3 _color;
    };
} 