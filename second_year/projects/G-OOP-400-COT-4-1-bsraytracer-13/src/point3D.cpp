/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** point3D
*/

#include "../include/point3D.hpp"
using namespace Math;

Point3D::Point3D(double valX, double valY, double valZ)
    : X(valX), Y(valY), Z(valZ)
{}

Point3D Point3D::operator+(const Vector3D& vector)
{
    return Point3D(this->X + vector.X, this->Y + vector.Y, this->Z + vector.Z);
}

Point3D Point3D::operator+(const Vector3D& vector) const
{
    return Point3D(this->X + vector.X, this->Y + vector.Y, this->Z + vector.Z);
}

Point3D Point3D::operator+=(const Vector3D& vector)
{
    Point3D _new = *this + vector;
    *this = _new;
    return *this;
}

Vector3D Point3D::operator-(const Point3D& other)
{
    return Vector3D(this->X - other.X, this->Y - other.Y, this->Z - other.Z);
}

Vector3D Point3D::operator-(const Point3D& other) const
{
    return Vector3D(this->X - other.X, this->Y - other.Y, this->Z - other.Z);
}
