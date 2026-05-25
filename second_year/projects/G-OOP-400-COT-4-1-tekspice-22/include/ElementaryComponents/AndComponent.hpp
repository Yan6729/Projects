/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** AndComponent
*/

#ifndef ANDCOMPONENT_HPP_
    #include "ElementaryComponent.hpp"
    #define ANDCOMPONENT_HPP_

namespace nts {
    class AndComponent : public ElementaryComponent {
        public:
            AndComponent();
            ~AndComponent();
            nts::Tristate compute(size_t pin) override;

        private:
    };
}

#endif /* !ANDCOMPONENT_HPP_ */
