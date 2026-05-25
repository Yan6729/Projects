/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Rendere=
*/

#include "../../include/renderer/Renderer.hpp"
#include "../../include/lights/Lighting.hpp"
using namespace RayTracer;
#define PI 3.14159265358979323846


Renderer::Renderer()
    : _maxX(800), _maxY(800)
{}

Renderer::Renderer(const Dimensions& dimensions)
    : _maxX(dimensions.width), _maxY(dimensions.height)
{}

Renderer::~Renderer()
{}

void Renderer::loader(const string& _filepath) {
    SceneParser _parse;
    _parse.parse_all(_filepath);
    LoadFiles _load("plugins");
    std::vector<std::string> _fileList = _load.getfiles();
    for (auto& file : _fileList) {
        if (file.find(".so") != string::npos)
            _prim.loadPlugin("plugins/" + file);
    }
    SceneBuilder _build(_prim, _light);
    _scene = _build.build(_parse);
    this->configCamera(_parse.camera_);
}

void Renderer::addOutput(std::unique_ptr<IOutput> _output)
{
    _outputs.push_back(move(_output));  
}

void Renderer::configCamera(CameraData _data)
{
    _cam.origin = Vec3(_data.xp, _data.yp, _data.zp);

    double _fov = _data.field_of_view * PI / 180.0;
    double _halfW = tan(_fov / 2.0);
    double _halfH = (double)_halfW * (double)_maxY / _maxX;

    double _yaw = _data.yr * PI / 180.0;
    double _pitch = -_data.xr * PI / 180.0;

    Vec3 _forward = Vec3(
        cos(_pitch) * sin(_yaw),
        sin(_pitch),
        cos(_pitch) * cos(_yaw)
    ).normalized();

    Vec3 worldUp = std::abs(_forward.dot(Vec3(0, 1, 0))) > 0.999 ? ({
        Vec3(0, 0, 1);
    }) : ({
        Vec3(0, 1, 0);
    });
    Vec3 _right = _forward.cross(worldUp).normalized();
    Vec3 _up = _right.cross(_forward).normalized();

    Vec3 s_Center = _cam.origin + _forward;
    Vec3 s_Corner = s_Center - _right * _halfW - _up * _halfH;

    _cam.screen = Rectangle3D(
        s_Corner,
        _right * (2 * _halfW),
        _up * (2 * _halfH)
    );
}

void Renderer::render(void)
{
    FrameBuffer buf({800, 800});
    vector<string> _types = _scene.primitives_presents;

    for (int h = 0; h < _maxY; h++) {
        for (int w = 0; w < _maxX; w++) {
            std::optional<HitRecord> _closest;
            double _tMin = 1e9;
            RayTracer::Ray _ray = _cam.thorwRay(
                (double)w / (_maxX - 1),
                (double)h / (_maxY - 1)
            );
            for (auto _type : _types) {
                for (auto& _prim : _scene.getPrimitives(_type)) {
                    auto _hit = _prim->intersect(_ray, 1e-1, _tMin);
                    if (_hit && _hit->t < _tMin) {
                        _tMin = _hit->t;
                        _closest = _hit;
                    }
                }
            }
            if (_closest) {
                Color surfaceColor(
                    _closest->_color.x,
                    _closest->_color.y,
                    _closest->_color.z
                );
                Color lit = computeLighting(*_closest, surfaceColor, _scene);
                RayTracer::Color _color = {
                    lit.r * 255.0,
                    lit.g * 255.0,
                    lit.b * 255.0
                };
                buf.setPixel(w, h, _color);
            }
        }
    }
    _outputs[0]->render(buf);
}