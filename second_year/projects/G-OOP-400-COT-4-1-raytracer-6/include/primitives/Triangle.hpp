#pragma once

#include "AbstractPrimitive.hpp"

namespace RayTracer {
    class Triangle : public AbstractPrimitive {
        public:
            Triangle(const Vec3& v0 = {0,0,0}, const Vec3& v1 = {1,0,0}, const Vec3& v2 = {0,1,0}, const Vec3& color = {1,1,1});
            void configure(const std::map<std::string, double>& params);
            std::optional<HitRecord> intersect(
                const Ray& ray,
                double tMin,
                double tMax) const override;

        protected:
            Vec3 calculateNormal(const Vec3& point) const override;

        private:
            Vec3 _v0;
            Vec3 _v1;
            Vec3 _v2;
            Vec3 _normal;   
            Vec3 _color;
    };
}