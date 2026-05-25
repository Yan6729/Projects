/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** SceneData
*/


#ifndef SCENE_DATA_HPP
    #define SCENE_DATA_HPP
    #include "../lights/Color.hpp"
    #include <vector>
    #include <memory>
    #include <string>

namespace RayTracer {
    struct TransformData {
        bool has_translation = false;
        double tx = 0, ty = 0, tz = 0;
        bool has_rotation = false;
        double rx = 0, ry = 0, rz = 0;
    };

    struct CameraData {
        int width;
        int height;
        float field_of_view;
        int xp;
        int yp;
        int zp;
        int xr;
        int yr;
        int zr;
    };

    struct TriangleData {
        double x0, y0, z0; 
        double x1, y1, z1;  
        double x2, y2, z2; 
        Color color;
        TransformData transform;
    };

    struct TorusData {
        int x, y, z;
        double R;  
        double r;
        Color color;
        TransformData transform;
    };

    struct FractalData {
        double x, y, z;
        int iterations;
        double power;
        Color color;
        TransformData transform;
    };

    struct SphereData {
        int x;
        int y;
        int z;
        int r;
        Color color;
        TransformData transform;
    };

    struct ConeData {
        int x;
        int y;
        int z;
        int r;
        int height;
        Color color;
        TransformData transform;
    };

    struct MobiusData {
        int x;
        int y;
        int z;
        double R;
        double W;
        Color color;
        TransformData transform;
    };

    struct CylinderData {
        int x;
        int y;
        int z;
        int r;
        int height;
        Color color;
        TransformData transform;
    };

    struct TangleCudeData {
        int x;
        int y;
        int z;
        double scale;
        Color color;
        TransformData transform;
    };
  
    struct PlaneData {
        int position;
        std::string axis;
        Color color;
        TransformData transform;
    };

    struct PrimitiveData {
       std::vector<SphereData> sphere;
       std::vector<PlaneData> plane;
       std::vector<ConeData> cone;
       std::vector<CylinderData> cylinder;
       std::vector<TriangleData> triangle;
       std::vector<MobiusData> mobius;
       std::vector<TorusData> torus;
       std::vector<TangleCudeData> tangleCube;
       std::vector<FractalData> fractal;
    };

    struct PointLightData {
        int x;
        int y;
        int z;
        double intensity;
        Color color;
    };
  
    struct DirectionalLightData {
        int x;
        int y;
        int z;
        Color color;
    };

    struct LightData {
        float ambient;
        float diffuse;
        std::vector<PointLightData> point_light;
        std::vector<DirectionalLightData> directional_light;
    };

    std::ostream& operator<<(std::ostream& os, const Color& v);
}

#endif // SCENE_DATA_HPP