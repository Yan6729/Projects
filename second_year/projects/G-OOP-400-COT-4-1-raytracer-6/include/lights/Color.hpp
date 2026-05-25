/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, May, 2026                                                     *
 * Title           - G-OOP-400-COT-4-1-raytracer-6                                      *
 * Description     -                                                                    *
 *     Color                                                                            *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *         ░        ░       ░░        ░        ░        ░░      ░░  ░░░░  ░             *
 *         ▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒  ▒▒▒▒  ▒             *
 *         ▓      ▓▓▓       ▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓      ▓▓▓  ▓▓▓▓▓▓▓        ▓             *
 *         █  ███████  ██████████  ███████  ████  ███████  ████  █  ████  █             *
 *         █        █  ███████        ████  ████        ██      ██  ████  █             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef INCLUDED_COLOR_HPP
#define INCLUDED_COLOR_HPP

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdint>

namespace RayTracer
{
    class Color {
        public:
            Color(double r, double g, double b);
            Color() = default;
            double r;
            double g;
            double b;
            ~Color();
            static Color fromRGB255(int r, int g, int b);
            Color operator+(const Color &rhs) const;
            Color operator*(double s) const;
            Color operator*(const Color &rhs) const;
            Color &operator+=(const Color &rhs);
            Color clamped01() const;
            std::uint8_t toByte(double v) const;
    };
}

#endif
