/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_
    #include "../math/Ray.hpp"
    #include "Rectangle3D.hpp"

namespace RayTracer {
    class Camera {
        public:
            Vec3 origin;
            Rectangle3D screen;
            Camera();
            ~Camera();
            Ray thorwRay(double u, double v);

        private:
    };
}

#endif /* !CAMERA_HPP_ */
