/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** SceneBuilder
*/

#ifndef SCENE_BUILDER_HPP
    #define SCENE_BUILDER_HPP
    #include "SceneParser.hpp"
    #include "../scene/Scene.hpp"
    #include "../plugins/PluginFactory.hpp"
    #include "../primitives/Sphere.hpp"
    #include "../primitives/Plane.hpp"
    #include "../math/Mat4.hpp"
    #include "../primitives/TransformedPrimitive.hpp"
    #include "../lights/AmbientLight.hpp"
    #include "../lights/DirectionalLight.hpp"
    #include "../lights/Lighting.hpp"
    #include "../lights/PointLight.hpp"

namespace RayTracer {
    class SceneBuilder {
        public:

            SceneBuilder(PluginFactory<IPrimitive>& primitive_factory, PluginFactory<ILight>& light_factory);

            Scene build(const SceneParser& parser);

        private:

            void buildPrimitives(Scene& scene,const SceneParser& parser);
            void buildLights(Scene& scene, const SceneParser& parser);

            PluginFactory<IPrimitive>& primitive_factory_;
            PluginFactory<ILight>& light_factory_;
    };
}

#endif