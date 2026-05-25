/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** FalseComponent
*/

#ifndef FALSECOMPONENT_HPP_
    #include "SpecialComponent.hpp"
    #define FALSECOMPONENT_HPP_

namespace nts {
    class FalseComponent : public SpecialComponent {
        public:
            FalseComponent();
            ~FalseComponent();
            nts::Tristate compute(size_t pin) override;

        private:
    };
}

#endif /* !FALSECOMPONENT_HPP_ */
