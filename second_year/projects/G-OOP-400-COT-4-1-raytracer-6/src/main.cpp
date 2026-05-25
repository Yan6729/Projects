/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** main
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/rayTracerError.hpp"
#include "../include/scene/SceneBuilder.hpp"
#include "../include/primitives/IPrimitive.hpp"
#include "../include/renderer/Renderer.hpp"
#include "../include/renderer/OutputFactorie.hpp"
#include "../include/renderer/SfmlOutput.hpp"
using namespace std;
using namespace RayTracer;
using namespace sf;

void usage()
{
    cout << "USAGE: ./raytracer [ <SCENE_FILE> || --graphics || -g ]" << "\n" <<
         " SCENE_FILE: scene configuration" << endl;
}

int main(int ac, char *av[])
{
    try {
        if (ac < 2)
            throw RayTracerError("Not enought arguments... Try ./raytracer --help");
        else if (ac > 2)
            throw RayTracerError("Too many arguments... Try ./raytracer --help");
        if (av[1] == string("-h") || av[1] == string("--help")) {
            usage();
            return 0;
        }
        if (av[1] == string("--graphics") || av[1] == string("-g")) {
            RayTracer::SfmlOutput _sfml;
            _sfml.render();
            return 0;
        }
        if (string(av[1]).find(".cfg") == string::npos) {
            throw RayTracerError("Invalid file... We need a .cfg file...");
        } else {
            if (!std::filesystem::exists(av[1]))
                throw RayTracerError("The file must be an existed one...");
            if (std::filesystem::is_empty(av[1]))
                throw RayTracerError("Invalid file... the file must not be empty");
            OutputFactorie _fact;
            Renderer _rend;
            _rend.addOutput(_fact.createOutput(0));
            _rend.loader(av[1]);
            _rend.render();
        };
        return 0;
    } catch (const RayTracerError& e ) {
        cerr << "Caught exception: " << e.what() << endl;
        return 84;
    } catch (const libconfig::ConfigException& f) {
        cerr << "Caught exeption: " << f.what() << endl;
        return 84;
    }
}