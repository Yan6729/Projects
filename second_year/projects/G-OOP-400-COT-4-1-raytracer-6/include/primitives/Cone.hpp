#pragma once

#include "AbstractPrimitive.hpp"

namespace RayTracer {
    class Cone : public AbstractPrimitive {
        public:
            Cone(const Vec3& center = {0,0,0}, double radius = 1.0, double height = 100.0, const Vec3& color = {1,1,1});
            void configure(const std::map<std::string, double>& params);
            std::optional<HitRecord> intersect(
                const Ray& ray,
                double tMin,
                double tMax) const override;

        protected:
            Vec3 calculateNormal(const Vec3& point) const override;

        private:
            Vec3 _center;
            double _radius;
            double _height;
            Vec3 _color;
    };
} 
