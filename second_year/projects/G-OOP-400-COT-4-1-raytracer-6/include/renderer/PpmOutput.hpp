/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** PpmOutput
*/

#ifndef PPMOUTPUT_HPP_
    #define PPMOUTPUT_HPP_
    #include "IOutput.hpp"

namespace RayTracer {
    class PpmOutput : public IOutput {
        public:
            PpmOutput();
            PpmOutput(int maxX, int maxY);
            int _maxX;
            int _maxY;
            ~PpmOutput();
            void render(const FrameBuffer& _buffer) override;

        private:
    };
}

#endif /* !PPMOUTPUT_HPP_ */
