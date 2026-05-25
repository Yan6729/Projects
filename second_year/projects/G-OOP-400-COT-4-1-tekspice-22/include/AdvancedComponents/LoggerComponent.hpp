/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** LoggerComponent
*/

#ifndef LOGGERCOMPONENT_HPP_
    #include "AdvancedComponent.hpp"
    #define LOGGERCOMPONENT_HPP_

namespace nts {
    class LoggerComponent : public AdvancedComponent {
        public:
            LoggerComponent();
            ~LoggerComponent();
            void simulate(size_t _tick) override;
        private:
    };
}

#endif /* !LOGGERCOMPONENT_HPP_ */
