/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** HitRecord
*/

#include "../../include/primitives/HitRecord.hpp"

namespace RayTracer {
    void setFaceNormal(HitRecord& rec, const Ray& ray, const Vec3& outwardNormal)
    {
        rec.frontFace = ray.direction.dot(outwardNormal) < 0;
        rec.normal = rec.frontFace ? outwardNormal : Vec3{-outwardNormal.x, -outwardNormal.y, -outwardNormal.z};
    }
}
