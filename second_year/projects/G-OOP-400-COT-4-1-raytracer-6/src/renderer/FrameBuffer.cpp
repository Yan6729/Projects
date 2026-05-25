/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** FrameBuffer
*/

#include "../../include/renderer/FrameBuffer.hpp"
using namespace RayTracer;

FrameBuffer::FrameBuffer()
{
    _dimensions = {800, 800};
    _pixels.assign(800, std::vector<Color>(800, Color{0 ,0 ,0}));
}

FrameBuffer::FrameBuffer(const Dimensions& dimensions)
    : _dimensions(dimensions)
{
    _pixels.assign(dimensions.height, std::vector<Color>(dimensions.width, Color {0, 0, 0}));
}

FrameBuffer::~FrameBuffer()
{
}

void FrameBuffer::reset(void)
{
    _pixels.clear();
    _pixels.assign(800, std::vector<Color>(800, Color{0, 0, 0}));
}

const Dimensions& FrameBuffer::getDimensions(void) const
{
    return this->_dimensions;
}

void FrameBuffer::setPixel(int x, int y, const Color& _color)
{
    if (x > _dimensions.width || y > _dimensions.height || x < 0 || y < 0)
        throw RayTracerError("Invalid dimentions... you're not respecting the bound.");
    _pixels[y][x] = _color;
}


const Color& FrameBuffer::getPixel(int x, int y) const
{
    if (x > _dimensions.width || y > _dimensions.height || x < 0 || y < 0)
        throw RayTracerError("Invalid dimentions... you're not respecting the bound.");
    return _pixels[y][x];
}
