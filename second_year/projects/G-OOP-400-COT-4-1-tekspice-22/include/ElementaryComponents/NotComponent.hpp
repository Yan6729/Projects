/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** NotComponent
*/

#ifndef NOTCOMPONENT_HPP_
    #include "AndComponent.hpp"
    #define NOTCOMPONENT_HPP_

namespace nts {
    class NotComponent : public ElementaryComponent {
        public:
            NotComponent();
            ~NotComponent();
            nts::Tristate compute(size_t pin) override;

        private:
    };
}

#endif /* !NOTCOMPONENT_HPP_ */
