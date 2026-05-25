/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** FrameBuffer
*/

#ifndef FRAMEBUFFER_HPP_
    #define FRAMEBUFFER_HPP_
    #include <iostream>
    #include <vector>
    #include "../scene/SceneData.hpp"
    #include "../rayTracerError.hpp"

namespace RayTracer {
    struct Dimensions {
        int width;
        int height;
    };


    class FrameBuffer {
        public:
            FrameBuffer();
            FrameBuffer(const Dimensions& _dim);
            ~FrameBuffer();
            void setPixel(int x, int y, const Color& _color);
            const Color& getPixel(int x, int y) const;
            const Dimensions& getDimensions(void) const;
            void reset(void);

        private:
            Dimensions _dimensions;
            std::vector<std::vector<Color>> _pixels;
    };
}

#endif /* !FRAMEBUFFER_HPP_ */
