#pragma once

#include "AbstractPrimitive.hpp"

namespace RayTracer {
    class Plane : public AbstractPrimitive {
        public:
            Plane(const Vec3& center = {0,0,0}, const Vec3& normal = {0,1,0}, const Vec3& color = {1,1,1});

            std::optional<HitRecord> intersect(
                const Ray& ray,
                double tMin,
                double tMax) const override;

            void configure(const std::map<std::string, double>& params);
            void setCenter(const Vec3& center);
            void setNormal(const Vec3& normal);
            void setColor(const Vec3& color);

        protected:
            Vec3 calculateNormal(const Vec3& point) const override;

        private:
            Vec3 _center;
            Vec3 _normal;
            Vec3 _color;
    };
} 