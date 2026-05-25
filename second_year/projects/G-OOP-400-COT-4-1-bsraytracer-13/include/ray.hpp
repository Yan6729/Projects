/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** ray
*/

#ifndef RAY_HPP_
    #define RAY_HPP_
    #include "point3D.hpp"
    #include "vector3D.hpp"
    #include <memory>
    using namespace Math;

namespace RayTracer {
    class Ray {
        public:
            Point3D origin;
            Vector3D direction;
            Ray() = default;
            Ray(const Point3D& givenOrigin, const Vector3D& givenDirection);
            ~Ray() = default;

        private:
    };
}

#endif /* !RAY_HPP_ */
