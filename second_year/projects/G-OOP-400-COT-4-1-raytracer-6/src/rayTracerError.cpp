/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** rayTracerError
*/

#include "../include/rayTracerError.hpp"
using namespace RayTracer;

RayTracerError::RayTracerError()
{
    _msg = "Oh... That's an error. It's not defined thought.";
}

RayTracerError::RayTracerError(string message) : _msg(message)
{}

const char *RayTracerError::what() const noexcept
{
    return _msg.c_str();
}
