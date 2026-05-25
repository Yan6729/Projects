/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** fractal
*/

#include "../../include/primitives/Fractal.hpp"
#include "../../include/primitives/HitRecord.hpp"
#include "../../include/math/Ray.hpp"
#include <cmath>

namespace RayTracer {

    Fractal::Fractal(const Vec3& center, int iterations, double power, const Vec3& color)
        : _center(center), _iterations(iterations), _power(power), _color(color) {}

    void Fractal::setCenter(const Vec3& center) {
        _center = center;
    }
    void Fractal::setIterations(int iterations) {
        _iterations = iterations;
    }
    void Fractal::setPower(double power) {
        _power = power;
    }
    void Fractal::setColor(const Vec3& color) {
        _color = color;
    }

    double Fractal::MandelbulbDE(const Vec3& pos) const {
        Vec3 z = pos;
        double dr = 1.0;
        double r = 0.0;
        for (int i = 0; i < _iterations; i++) {
            r = z.length();
            if (r > 2.0) break;
            
            double theta = acos(z.z / r);
            double phi = atan2(z.y, z.x);
            dr = pow(r, _power - 1.0) * _power * dr + 1.0;
            
            double zr = pow(r, _power);
            theta = theta * _power;
            phi = phi * _power;
            
            z = Vec3(sin(theta) * cos(phi), sin(phi) * sin(theta), cos(theta)) * zr;
            z = z + pos;
        }
        return 0.5 * log(r) * r / dr;
    }

    Vec3 Fractal::calculateNormal(const Vec3& point) const {
        double eps = 0.001;
        Vec3 xDir(eps, 0, 0);
        Vec3 yDir(0, eps, 0);
        Vec3 zDir(0, 0, eps);
        double d = MandelbulbDE(point - _center);
        double nx = MandelbulbDE(point - _center + xDir) - d;
        double ny = MandelbulbDE(point - _center + yDir) - d;
        double nz = MandelbulbDE(point - _center + zDir) - d;
        return Vec3(nx, ny, nz).normalized();
    }

    std::optional<HitRecord> Fractal::intersect(const Ray& ray, double tMin, double tMax) const
    {
        double t = tMin;
        for (int i = 0; i < 200; i++) {
            Vec3 p = ray.at(t);
            double d = MandelbulbDE(p - _center);
            if (d < 0.001) {
                HitRecord rec;
                rec.t = t;
                rec.point = p;
                rec._color = _color;
                setFaceNormal(rec, ray, calculateNormal(p)); 
                assignMaterial(rec);
                return rec;
            }
            t += d;
            if (t > tMax) break;
        }
        return std::nullopt;
    }

    void Fractal::configure(const std::map<std::string, double>& params)
    {
        _center = {
            params.at("x"),
            params.at("y"),
            params.at("z"),
        };
        _iterations = (int)params.at("iterations");
        _power = params.at("power");
        setMaterial(FlatMaterial(
            (int)params.at("color.r"),
            (int)params.at("color.g"),
            (int)params.at("color.b")
        ));
        _color = {
            params.at("color.r") / 255.0,
            params.at("color.g") / 255.0,
            params.at("color.b") / 255.0
        };
    }

}

extern "C" {
    RayTracer::IPrimitive *create() {
        return new RayTracer::Fractal();
    }

    const char* getType() {
        return "fractal";
    }
}
