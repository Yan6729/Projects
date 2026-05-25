/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** ClockComponent
*/

#ifndef CLOCKCOMPONENT_HPP_
    #include "InputComponent.hpp"
    #define CLOCKCOMPONENT_HPP_

namespace nts {
    class ClockComponent : public InputComponent {
        public:
            ClockComponent();
            ~ClockComponent();
            void simulate(size_t tick) override;
            ClockComponent& operator=(nts::Tristate newValue);

        protected:
    };
}

#endif /* !CLOCKCOMPONENT_HPP_ */
