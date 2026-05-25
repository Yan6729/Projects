/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** rectangle3D
*/

#ifndef RECTANGLE3D_HPP_
    #define RECTANGLE3D_HPP_
    #include "point3D.hpp"
    #include "vector3D.hpp"
    using namespace Math;

namespace RayTracer {
    class Rectangle3D {
        public:
            Point3D origin;
            Vector3D bottom_side;
            Vector3D left_side;
            Point3D pointAt(double u, double v);
            Rectangle3D() = default;
            Rectangle3D(Point3D Origin3D, Vector3D givenBotton, Vector3D givenLeft);
            ~Rectangle3D() = default;

        private:
    };
}

#endif /* !RECTANGLE3D_HPP_ */
