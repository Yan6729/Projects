#pragma once

#include "../math/Mat4.hpp"
#include "../math/Ray.hpp"
#include "../materials/FlatMaterial.hpp"
#include "IPrimitive.hpp"
#include <memory>
#include <stdexcept>

namespace RayTracer {
    class TransformedPrimitive : public IPrimitive {
        public:
            TransformedPrimitive(
                std::shared_ptr<IPrimitive> inner,
                const Mat4& objectToWorld);
            void configure(const std::map<std::string, double>& params);
            std::optional<HitRecord> intersect(
                const Ray& ray,
                double tMin,
                double tMax) const override;

            void setMaterial(const FlatMaterial& material) override;
            const FlatMaterial& getMaterial() const override;

            const Mat4& objectToWorld() const;
            const Mat4& worldToObject() const;

        private:
            std::shared_ptr<IPrimitive> _inner;
            Mat4 _objToWorld;
            Mat4 _worldToObj;
    };
} 