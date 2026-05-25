#pragma once

#include "AbstractPrimitive.hpp"

#include "../math/Vec3.hpp"

#include <optional>
#include <vector>
#include <map>


namespace RayTracer {

    class Mobius : public AbstractPrimitive {
    public:

        Mobius(
            const Vec3& center = Vec3(0, 0, 0),
            double radius = 40.0,
            double width = 10.0,
            const Vec3& color = Vec3(1, 0, 0)
        );

        ~Mobius() override = default;

        void configure(
            const std::map<std::string, double>& params
        ) override;

        std::optional<HitRecord> intersect(
            const Ray& ray,
            double tMin,
            double tMax
        ) const override;

        Vec3 calculateNormal(
            const Vec3& point
        ) const override;

    private:

        struct Triangle {
            Vec3 a;
            Vec3 b;
            Vec3 c;
            Vec3 normal;
        };

    private:

        void buildMesh();

        Vec3 surface(double u, double v) const;

        bool intersectTriangle(
            const Ray& ray,
            const Triangle& tri,
            double& t
        ) const;

    private:

        Vec3 _center;

        double _R;
        double _w;

        Vec3 _color;

        std::vector<Triangle> _mesh;
    };

}