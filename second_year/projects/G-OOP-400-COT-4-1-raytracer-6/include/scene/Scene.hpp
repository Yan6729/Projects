/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_
    #include "../primitives/IPrimitive.hpp"
    #include "../lights/ILights.hpp"
    #include <vector>
    #include <unordered_map>
    #include <iostream>
    #include <string>
    #include <memory>
    using namespace std;

namespace RayTracer {
    class Scene {
        public:
            using PrimitiveList = std::vector<std::unique_ptr<IPrimitive>>;
            using LightList = std::vector<std::unique_ptr<ILight>>;

            void addPrimitive(const std::string& type, std::unique_ptr<IPrimitive> primitive);
            void addLight(const std::string& type, std::unique_ptr<ILight> light);

            const PrimitiveList& getPrimitives(const std::string& type) const;
            const LightList& getLights(const std::string& type) const;
            const LightList* findLights(const std::string& type) const;
            std::vector<std::string> primitives_presents;            

        private:

            std::unordered_map<std::string, PrimitiveList> primitives_;
            std::unordered_map<std::string, LightList> lights_;};
}

#endif /* !SCENE_HPP_ */
