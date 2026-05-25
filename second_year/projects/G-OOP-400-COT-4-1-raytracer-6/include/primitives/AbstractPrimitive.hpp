#pragma once

#include "IPrimitive.hpp"
#include "../math/Vec3.hpp"
#include "../materials/FlatMaterial.hpp"

namespace RayTracer {
    class AbstractPrimitive : public IPrimitive {
        public:
            AbstractPrimitive();
            virtual ~AbstractPrimitive();
            void setMaterial(const FlatMaterial& material) override;
            const FlatMaterial& getMaterial() const override;

        protected:
            void assignMaterial(HitRecord& rec) const;
            Vec3 getNormalAtPoint(const Vec3& point) const;
            virtual Vec3 calculateNormal(const Vec3& point) const = 0;
            bool isValidIntersection(double t, double tMin, double tMax) const;


        private:
            FlatMaterial _material;
    };
} 
