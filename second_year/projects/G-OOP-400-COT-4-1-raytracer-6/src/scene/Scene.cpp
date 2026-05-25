/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Scene
*/

#include "../../include/scene/Scene.hpp"
#include "../../include/rayTracerError.hpp"

using namespace RayTracer;

void Scene::addPrimitive(const std::string& type, std::unique_ptr<IPrimitive>primitive) {
    primitives_[type].push_back(std::move(primitive));
}

void Scene::addLight(const std::string& type, std::unique_ptr<ILight> light) {
    lights_[type].push_back(std::move(light));
}

const Scene::PrimitiveList& Scene::getPrimitives(const std::string& type) const {
    auto it = primitives_.find(type);

    if (it == primitives_.end()) {
        throw RayTracerError("Unknown primitive type: " + type);
    }
    return it->second;
}

const Scene::LightList& Scene::getLights(const std::string& type) const {
    auto it = lights_.find(type);

    if (it == lights_.end()) {
        throw RayTracerError("Unknown light type: " + type);
    }
    return it->second;
}

const Scene::LightList* Scene::findLights(const std::string& type) const {
    auto it = lights_.find(type);

    if (it == lights_.end())
        return nullptr;
    return &it->second;
}
