/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, May, 2026                                                     *
 * Title           - G-OOP-400-COT-4-1-raytracer-6                                      *
 * Description     -                                                                    *
 *     FlatMaterial                                                                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄  ▄▀▀█▀▄    ▄▀▀▀█▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄ ▄▄             *
 *      ▐  ▄▀   ▐ █   █   █ █   █  █  █    █  ▐ ▐  ▄▀   ▐ █ █    ▌ █  █   ▄▀            *
 *        █▄▄▄▄▄  ▐  █▀▀▀▀  ▐   █  ▐  ▐   █       █▄▄▄▄▄  ▐ █      ▐  █▄▄▄█             *
 *        █    ▌     █          █        █        █    ▌    █         █   █             *
 *       ▄▀▄▄▄▄    ▄▀        ▄▀▀▀▀▀▄   ▄▀        ▄▀▄▄▄▄    ▄▀▄▄▄▄▀   ▄▀  ▄▀             *
 *       █    ▐   █         █       █ █          █    ▐   █     ▐   █   █               *
 *       ▐        ▐         ▐       ▐ ▐          ▐        ▐         ▐   ▐               *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */


#include "../../include/materials/FlatMaterial.hpp"

namespace RayTracer {

FlatMaterial::FlatMaterial()
    : _albedo(0.0, 0.0, 0.0)
{}

FlatMaterial::FlatMaterial(const Color& albedo)
    : _albedo(albedo)
{}

FlatMaterial::FlatMaterial(int r, int g, int b)
    : _albedo(Color::fromRGB255(r, g, b))
{}

FlatMaterial FlatMaterial::fromRGB255(int r, int g, int b)
{
    return FlatMaterial(r, g, b);
}

const Color& FlatMaterial::getAlbedo() const
{
    return _albedo;
}

void FlatMaterial::setAlbedo(const Color& albedo)
{
    _albedo = albedo;
}

}
