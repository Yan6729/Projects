/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Mat4
*/

#include "../../include/math/Mat4.hpp"
using namespace RayTracer;

Mat4::Mat4()
{
    for (int c = 0; c < 4; c++)
        for (int r = 0; r < 4; r++)
            m[c][r] = (c == r) ? 1.0 : 0.0; 
}

Mat4::Mat4(
    double m00, double m01, double m02, double m03,
    double m10, double m11, double m12, double m13,
    double m20, double m21, double m22, double m23,
    double m30, double m31, double m32, double m33
){
    m[0] = {m00, m10, m20, m30};
    m[1] = {m01, m11, m21, m31};
    m[2] = {m02, m12, m22, m32};
    m[3] = {m03, m13, m23, m33};
}

Mat4 Mat4::operator*(const Mat4& o) const
{
    Mat4 res;
    for (int c = 0; c < 4; c++)
        for (int r = 0; r < 4; r++) {
            res.m[c][r] = 0;
            for (int k = 0; k < 4; k++)
                res.m[c][r] += m[k][r] * o.m[c][k];
        }
    return res;
}

Mat4 Mat4::transposed() const
{
    Mat4 t;
    for (int c = 0; c < 4; c++)
        for (int r = 0; r < 4; r++)
            t.m[r][c] = m[c][r];
    return t;
}

Mat4 Mat4::inverse() const
{
    double a[4][8];
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) a[r][c]   = m[c][r];
        for (int c = 0; c < 4; c++) a[r][4+c] = (r == c) ? 1.0 : 0.0;
    }
    for (int col = 0; col < 4; col++) {
        int pivot = col;
        for (int r = col+1; r < 4; r++)
            if (std::abs(a[r][col]) > std::abs(a[pivot][col])) pivot = r;
        std::swap(a[col], a[pivot]);
        if (std::abs(a[col][col]) < 1e-12)
            throw std::runtime_error("Mat4::inverse(): singular matrix");
        double inv = 1.0 / a[col][col];
        for (int c = 0; c < 8; c++) a[col][c] *= inv;
        for (int r = 0; r < 4; r++) {
            if (r == col) continue;
            double factor = a[r][col];
            for (int c = 0; c < 8; c++) a[r][c] -= factor * a[col][c];
        }
    }
    Mat4 result;
    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++)
            result.m[c][r] = a[r][4+c];
    return result;
}

std::ostream& operator<<(std::ostream& os, const Mat4& mat)
{
    for (int r = 0; r < 4; r++) {
        os << "[ ";
        for (int c = 0; c < 4; c++) os << mat.m[c][r] << " ";
        os << "]\n";
    }
    return os;
}
