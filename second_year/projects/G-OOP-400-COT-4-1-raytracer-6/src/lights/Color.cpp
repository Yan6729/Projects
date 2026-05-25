/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, May, 2026                                                     *
 * Title           - G-OOP-400-COT-4-1-raytracer-6                                      *
 * Description     -                                                                    *
 *     Color                                                                            *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "../../include/lights/Color.hpp"
using namespace RayTracer;

Color::Color(double r, double g, double b) : r(r), g(g), b(b)
{
}

Color::~Color()
{
}

Color Color::fromRGB255(int r, int g, int b)
{
    return Color(r / 255.0, g / 255.0, b / 255.0);
}

Color Color::operator+(const Color &rhs) const
{
    return Color(r + rhs.r, g + rhs.g, b + rhs.b);
}

Color Color::operator*(const Color &rhs) const
{
    return Color(r * rhs.r, g * rhs.g, b * rhs.b);
}

Color Color::operator*(double s) const
{
    return Color(r * s, g * s, b * s);
}

Color &Color::operator+=(const Color &rhs)
{

    r += rhs.r;
    g += rhs.g;
    b += rhs.b;
    return *this;
}

Color Color::clamped01() const
{

    return Color(std::clamp(r, 0.0, 1.0), std::clamp(g, 0.0, 1.0), std::clamp(b, 0.0, 1.0));
}

std::uint8_t Color::toByte(double v) const
{

    const double c = std::clamp(v, 0.0, 1.0);
    return static_cast<std::uint8_t>(c * 255.0 + 0.5);
}
