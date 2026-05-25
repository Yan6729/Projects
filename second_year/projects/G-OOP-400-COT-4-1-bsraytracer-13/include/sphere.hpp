/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** sphere
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_
    #include "ray.hpp"

namespace RayTracer {
    class Sphere {
        public:
            Point3D center;
            double radius;
            Sphere() = default;
            Sphere(const Point3D& givenCenter, double giveRadius);
            ~Sphere() = default;
            bool hits(const Ray& ray);

        private:
    };
}

#endif /* !SPHERE_HPP_ */
