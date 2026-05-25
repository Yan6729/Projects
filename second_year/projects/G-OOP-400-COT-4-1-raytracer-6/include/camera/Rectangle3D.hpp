/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
    #define RECTANGLE_HPP_
    #include "../math/Vec3.hpp"

namespace RayTracer {
    class Rectangle3D {
        public:
            Vec3 _O;
            Vec3 _I;
            Vec3 _J;
            Rectangle3D();
            Rectangle3D(Vec3 o, Vec3 i, Vec3 j);
            ~Rectangle3D();
            Vec3 convertTo3D(double u, double v) const;

        private:
    };
}

#endif /* !RECTANGLE_HPP_ */
