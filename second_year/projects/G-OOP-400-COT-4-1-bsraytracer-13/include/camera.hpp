/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** camera
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_
    #include "rectangle3D.hpp"
    #include "ray.hpp"

namespace RayTracer {
    class Camera {
        public:
            Camera();
            ~Camera() = default;
            Point3D origin;
            Rectangle3D screen;
            Ray ray(double u, double v);
        private:
    };
}

#endif /* !CAMERA_HPP_ */
