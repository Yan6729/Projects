/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** OutputComponent
*/

#ifndef OUTPUTCOMPONENT_HPP_
    #include "SpecialComponent.hpp"
    #define OUTPUTCOMPONENT_HPP_

namespace nts {
    class OutputComponent : public nts::SpecialComponent {
        public:
            OutputComponent();
            ~OutputComponent();
            nts::Tristate compute(size_t pin) override;

        private:
    };
}

#endif /* !OUTPUTCOMPONENT_HPP_ */
