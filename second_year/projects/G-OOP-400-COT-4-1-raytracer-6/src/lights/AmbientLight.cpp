/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, May, 2026                                                     *
 * Title           - G-OOP-400-COT-4-1-raytracer-6                                      *
 * Description     -                                                                    *
 *     AmbientLight                                                                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */


#include "../../include/lights/AmbientLight.hpp"
#include "../../include/primitives/HitRecord.hpp"

namespace RayTracer {

AmbientLight::AmbientLight(double intensity)
    : _intensity(intensity)
{}

Color AmbientLight::illuminate(
    const HitRecord& hit,
    const Color& surfaceColor) const
{
    (void)hit;
    return surfaceColor * _intensity;
}

}
