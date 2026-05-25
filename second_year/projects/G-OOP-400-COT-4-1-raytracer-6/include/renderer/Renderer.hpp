/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Renderer
*/

#ifndef RENDERER_HPP_
    #define RENDERER_HPP_
    #include "../reSf/ModifiedWindow.hpp"
    #include <memory>
    #include "OutputFactorie.hpp"
    #include "../scene/Scene.hpp"
    #include "../camera/Camera.hpp"
    #include "../scene/SceneData.hpp"
    #include "LoadFiles.hpp"
    #include "../scene/SceneParser.hpp"
    #include "../scene/SceneBuilder.hpp"

namespace RayTracer {
    class Renderer {
        public:
            Renderer();
            Renderer(const Dimensions& dimentions);
            ~Renderer();
            void addOutput(std::unique_ptr<IOutput>);
            void render(void);
            void configCamera(CameraData _data);
            void loader(const std::string& _filepath);

        private:
            std::vector<std::unique_ptr<IOutput>> _outputs;
            FrameBuffer _createBuff(const Scene& _scene);
            int _maxX;
            int _maxY;
            PluginFactory<IPrimitive> _prim;
            PluginFactory<ILight> _light;
            Scene _scene;
            Camera _cam;
    };
}

#endif /* !RENDERER_HPP_ */
