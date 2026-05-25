/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** TransformedPrimitives
*/

#include "../../include/primitives/TransformedPrimitive.hpp"
#include "../../include/primitives/HitRecord.hpp"
#include "../../include/math/Ray.hpp"
#include <stdexcept>

namespace RayTracer
{
    TransformedPrimitive::TransformedPrimitive(
        std::shared_ptr<IPrimitive> inner,
        const Mat4 &objectToWorld)
        : _inner(std::move(inner)), _objToWorld(objectToWorld), _worldToObj(objectToWorld.inverse())
    {
        if (!_inner)
            throw std::invalid_argument("TransformedPrimitive: inner must not be null");
    }

    const Mat4 &TransformedPrimitive::objectToWorld() const
    {
        return _objToWorld;
    }
    const Mat4 &TransformedPrimitive::worldToObject() const
    {
        return _worldToObj;
    }

    std::optional<HitRecord> TransformedPrimitive::intersect(const Ray &ray, double tMin, double tMax) const
    {
        Ray localRay{
            transformPoint(_worldToObj, ray.origin),
            transformDirection(_worldToObj, ray.direction)};

        auto hit = _inner->intersect(localRay, tMin, tMax);
        if (!hit)
            return std::nullopt;

        hit->point = transformPoint(_objToWorld, hit->point);
        Vec3 worldNormal = transformNormal(_objToWorld, hit->normal);
        setFaceNormal(*hit, ray, worldNormal.normalized());

        return hit;
    }

    void TransformedPrimitive::configure(const std::map<std::string, double> &params)
    {
        (void)params;
    }

    void TransformedPrimitive::setMaterial(const FlatMaterial &material)
    {
        _inner->setMaterial(material);
    }

    const FlatMaterial &TransformedPrimitive::getMaterial() const
    {
        return _inner->getMaterial();
    }

}