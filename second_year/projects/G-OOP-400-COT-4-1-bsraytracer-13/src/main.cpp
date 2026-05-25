/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** main
*/

#include "../include/camera.hpp"
#include "../include/sphere.hpp"
using namespace RayTracer;

void write_color(const Math::Vector3D &color)
{
    std::cout
        << (int)color.X << " "
        << (int)color.Y << " "
        << (int)color.Z << "\n";
}

int main(int ac, char *av[])
{
    int height = 0;
    int width = 0;
    Camera _camera;
    Sphere _sr(Point3D(-0.3, -0.1, -1), 0.5);
    Sphere _sr2(Point3D(0.3, 0.1, -1), 0.5);

    if (ac == 3) {
        height = stoi(av[2]);
        width = stoi(av[1]);
    } else {
        height = 800;
        width = 800;
    }

    cout << "P3\n" << width << " " << height << "\n255\n";
    for (int h = height - 1; h >= 0; h--) {
        for (int w = 0; w < width; w++) {
            double v = (double)h / (double)(height - 1);
            double u = (double)w / (double)(width - 1);
            Ray _ray = _camera.ray(u, v);
            if (_sr.hits(_ray))
                write_color(Math::Vector3D(w/255, h/255, 100));
            if (_sr2.hits(_ray) && !_sr.hits(_ray))
                write_color(Math::Vector3D(h/255, w/255, 140));
            if (!_sr.hits(_ray) && !_sr2.hits(_ray))
                write_color(Math::Vector3D(255, 255, 255));
        }
        cout << "" << endl;
    }
}
