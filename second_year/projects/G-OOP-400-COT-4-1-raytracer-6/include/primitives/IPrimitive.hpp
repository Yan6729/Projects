/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** IPrimitive
*/

#pragma once

#include "HitRecord.hpp"
#include "../math/Ray.hpp"
#include "../materials/FlatMaterial.hpp"
#include <optional>
#include <limits>
#include <map>

namespace RayTracer {
    class IPrimitive {
        public:
            virtual ~IPrimitive() = default;
            virtual void configure(const std::map<std::string, double>& params) = 0;
            virtual std::optional<HitRecord> intersect(
                const Ray& ray,
                double tMin = 1e-4,
                double tMax = std::numeric_limits<double>::infinity()) const = 0;

            virtual void setMaterial(const FlatMaterial& material) = 0;
            virtual const FlatMaterial& getMaterial() const = 0;
    };
}