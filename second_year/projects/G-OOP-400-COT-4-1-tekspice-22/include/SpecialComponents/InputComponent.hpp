/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** InputComponent
*/

#ifndef INPUTCOMPONENT_HPP_
    #include "SpecialComponent.hpp"
    #define INPUTCOMPONENT_HPP_

namespace nts {
    class InputComponent : public nts::SpecialComponent {
        public:
            InputComponent();
            ~InputComponent();
            nts::Tristate compute(size_t pin) override;
            InputComponent& operator=(nts::Tristate newValue);
            void simulate(size_t tick) override;

        protected:
            nts::Tristate _value = Tristate::Undefined;
            nts::Tristate _temp = Tristate::Void;
    };
}

#endif /* !INPUTCOMPONENT_HPP_ */
