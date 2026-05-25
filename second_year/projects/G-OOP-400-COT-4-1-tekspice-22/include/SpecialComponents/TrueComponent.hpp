/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** TrueComponent
*/

#ifndef TRUECOMPONENT_HPP_
    #include "SpecialComponent.hpp"
    #define TRUECOMPONENT_HPP_

namespace nts {
    class TrueComponent : public SpecialComponent {
        public:
            TrueComponent();
            ~TrueComponent();
            nts::Tristate compute(size_t pin) override;

        protected:
    };
}

#endif /* !TRUECOMPONENT_HPP_ */
