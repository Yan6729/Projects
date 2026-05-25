/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** point3D
*/

#ifndef POINT3D_HPP_
    #define POINT3D_HPP_
    #include "vector3D.hpp"

namespace Math {
    class Point3D {
        public:
            double X;
            double Y;
            double Z;
            Point3D() = default;
            ~Point3D() = default;
            Point3D(double valX, double valY, double valZ);
            Point3D operator+(const Vector3D& vector);
            Point3D operator+(const Vector3D& vector) const;
            Vector3D operator-(const Point3D& other);
            Vector3D operator-(const Point3D& other) const;
            Point3D operator+=(const Vector3D& vector);

        private:
    };
}

#endif /* !POINT3D_HPP_ */
