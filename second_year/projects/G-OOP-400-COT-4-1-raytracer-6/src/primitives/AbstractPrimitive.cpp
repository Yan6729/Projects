#include "../../include/primitives/AbstractPrimitive.hpp"

namespace RayTracer
{

    AbstractPrimitive::AbstractPrimitive() {}
    AbstractPrimitive::~AbstractPrimitive() {}

    Vec3 AbstractPrimitive::getNormalAtPoint(const Vec3 &point) const
    {
        return calculateNormal(point);
    }

    bool AbstractPrimitive::isValidIntersection(double t, double tMin, double tMax) const
    {
        return t >= tMin && t <= tMax;
    }

    void AbstractPrimitive::setMaterial(const FlatMaterial &material)
    {
        _material = material;
    }

    const FlatMaterial &AbstractPrimitive::getMaterial() const
    {
        return _material;
    }

    void AbstractPrimitive::assignMaterial(HitRecord& rec) const
    {
        rec._color = Vec3(
            _material.getAlbedo().r,
            _material.getAlbedo().g,
            _material.getAlbedo().b
        );
    }
}
