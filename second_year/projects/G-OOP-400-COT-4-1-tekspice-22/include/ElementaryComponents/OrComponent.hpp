/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** OrComponent
*/

#ifndef ORCOMPONENT_HPP_
    #include "AndComponent.hpp"
    #define ORCOMPONENT_HPP_

namespace nts {
    class OrComponent : public nts::ElementaryComponent {
        public:
            OrComponent();
            ~OrComponent();
            Tristate compute(size_t pin) override;

        private:
    };
}

#endif /* !ORCOMPONENT_HPP_ */
