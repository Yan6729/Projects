/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** PpmOutput
*/

#include "../../include/renderer/PpmOutput.hpp"
#include <ctime>
using namespace RayTracer;

PpmOutput::PpmOutput()
{
    _maxX = 800;
    _maxY = 800;
}

PpmOutput::PpmOutput(int maxX, int maxY)
    : _maxX(maxX), _maxY(maxY)
{}

PpmOutput::~PpmOutput()
{}

void PpmOutput::render(const FrameBuffer& buffer)
{
    std::string path = "results/output_" + std::to_string(std::time(nullptr)) + ".ppm";
    std::ofstream _file(path);

    if (!_file.is_open())
        throw RayTracerError("Error while creating the ppm file");
    _file << "P3\n" << _maxX << " " << _maxY << "\n255" << "\n";

    for (int h = 0; h < _maxY; h++) {
        for (int w = 0; w < _maxY; w++) {
            _file << buffer.getPixel(w, h);
        }
        _file << "\n";
    }
    _file.close();
    cout << "[ok] Scene file: " << path << " CREATED !" << "\n";
}
