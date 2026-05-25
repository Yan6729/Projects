/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** vector3D
*/

#ifndef VECTOR3D_HPP_
    #define VECTOR3D_HPP_
    #include <cmath>
    #include <iostream>
    #include <string>
    using namespace std;

namespace Math {
    class Vector3D {
        public:
            double X;
            double Y;
            double Z;
            Vector3D() = default;
            Vector3D(double valX, double valY, double valZ);
            double length(void);
            ~Vector3D() = default;
            double dot(const Vector3D& other);
            double dot(const Vector3D& other) const;
            Vector3D operator+(const Vector3D& other);
            Vector3D operator+=(const Vector3D& other);
            Vector3D operator-(const Vector3D& other);
            Vector3D operator-=(const Vector3D& other);
            Vector3D operator/(const Vector3D& other);
            Vector3D operator/=(const Vector3D& other);
            Vector3D operator*(const Vector3D& other);
            Vector3D operator*=(const Vector3D& other);
            Vector3D operator*(double value);
            Vector3D operator*=(double value);
            Vector3D operator/(double value);
            Vector3D operator/=(double value);
        private:
    };
}

#endif /* !VECTOR3D_HPP_ */
