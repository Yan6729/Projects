/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** vector3D
*/

#include "../include/vector3D.hpp"
using namespace Math;

Vector3D::Vector3D(double valX, double valY, double valZ)
    : X(valX), Y(valY), Z(valZ)
{}

double Vector3D::length()
{
    return sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
}

double Vector3D::dot(const Vector3D& other)
{
    return (this->X * other.X) + (this->Y * other.Y) + (this->Z * other.Z);
}

double Vector3D::dot(const Vector3D& other) const
{
    return (this->X * other.X) + (this->Y * other.Y) + (this->Z * other.Z);
}

Vector3D Vector3D::operator+(const Vector3D& other)
{
    return Vector3D(this->X + other.X, this->Y + other.Y, this->Z + other.Z);
}

Vector3D Vector3D::operator+=(const Vector3D& other)
{
    Vector3D _new = *this + other;
    *this = _new;
    return *this;
}

Vector3D Vector3D::operator-=(const Vector3D& other)
{
    Vector3D _new = *this - other;
    *this = _new;
    return *this;
}

Vector3D Vector3D::operator-(const Vector3D& other)
{
    return Vector3D(this->X - other.X, this->Y - other.Y, this->Z - other.Z);
}

Vector3D Vector3D::operator*(double value)
{
    return Vector3D(this->X * value, this->Y * value, this->Z * value);
}

Vector3D Vector3D::operator*=(double value)
{
    Vector3D _new = *this * value;
    *this = _new;
    return *this;
}

Vector3D Vector3D::operator/(double value)
{
    return *this * (1 / value);
}

Vector3D Vector3D::operator/=(double value)
{
    Vector3D _new = *this / value;
    *this = _new;
    return *this;
}

Vector3D Vector3D::operator*(const Vector3D& other)
{
    return Vector3D(((Y * other.Z) - (Z * other.Y)), ((Z * other.X) - (X * other.Z)), ((X * other.Y) - (Y * other.X)));
}

Vector3D Vector3D::operator*=(const Vector3D& other)
{
    Vector3D _new = *this * other;
    *this = _new;
    return *this;
}

Vector3D Vector3D::operator/(const Vector3D& other)
{
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    other.X == 0.0 ? x = 0.0 : x = this->X / other.X;
    other.Y == 0.0 ? y = 0.0 : y = this->Y / other.Y;
    other.Z == 0.0 ? z = 0.0 : z = this->Z / other.Z;

    return Vector3D(x, y, z);
}

Vector3D Vector3D::operator/=(const Vector3D& other)
{
    Vector3D _new = *this / other;
    *this = _new;
    return *this;
}
