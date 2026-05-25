/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** IOutput
*/

#ifndef IOUTPUT_HPP_
    #define IOUTPUT_HPP_
    #include "FrameBuffer.hpp"
    #include <fstream>

namespace RayTracer {
    class IOutput {
        public:
            virtual ~IOutput() = default;
            virtual void render(const FrameBuffer& _buffer) = 0;

        private:
    };
}

#endif /* !IOUTPUT_HPP_ */
