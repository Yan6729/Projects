/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** OutputFactorie
*/

#ifndef OUTPUTFACTORIE_HPP_
    #define OUTPUTFACTORIE_HPP_
    #include "IOutput.hpp"
    #include "PpmOutput.hpp"
    #include <string>
    #include <memory>
    #include "../rayTracerError.hpp"

namespace RayTracer {
    class OutputFactorie {
        public:
            std::unique_ptr<IOutput> createOutput(std::size_t option);

        private:
    };
}

#endif /* !OUTPUTFACTORIE_HPP_ */
