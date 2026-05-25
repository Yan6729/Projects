/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** OutputFactorie
*/

#include "../../include/renderer/OutputFactorie.hpp"
using namespace RayTracer;
using namespace std;

unique_ptr<IOutput> OutputFactorie::createOutput(std::size_t option)
{
    switch (option) {
        case 0:
            return make_unique<PpmOutput>();

        default:
            throw RayTracerError("Invalid option. You have only two option:\n 0: PPM output\n, 1: Sfml output");
    }
}
