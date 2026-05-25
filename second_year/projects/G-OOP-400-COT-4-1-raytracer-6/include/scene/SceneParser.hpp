
#ifndef SCENE_PARSER_HPP
    #define SCENE_PARSER_HPP
    #include <string>
    #include <map>
    #include <libconfig.h++>
    #include "SceneData.hpp"
    #include <filesystem>
    #include "../rayTracerError.hpp"
    using namespace libconfig;

namespace RayTracer {
    class SceneParser {
        public:
            void parse_camera(const std::string& filepath);
            void parse_primitive(const std::string& filepath);
            void parse_light(const std::string& filepath);
            void parse_all(const std::string& filepath);
            std::vector<std::string> _typesName;
            //private:
            CameraData camera_;
            PrimitiveData primitive_;
            LightData light_;
        private:
            std::vector<MobiusData> parse_mobius(const Setting& mobibus);
            std::vector<ConeData> parse_cone(const Setting& cone);
            std::vector<CylinderData> parse_cylinder(const Setting& cylinder);
            std::vector<PlaneData> parse_plane(const Setting& plane);
            std::vector<SphereData> parse_sphere(const Setting& sphere);
            std::vector<TriangleData> parse_triangle(const Setting& triangle);
            std::vector<TorusData> parse_torus(const Setting& torus);
            std::vector<FractalData> parse_fractal(const Setting& fractal);
            std::vector<TangleCudeData> parse_tangleCube(const Setting& tangle);
            TransformData parse_transform(const Setting& setting);
            void merge_scene(const std::string& filepath);
    };
}

#endif
