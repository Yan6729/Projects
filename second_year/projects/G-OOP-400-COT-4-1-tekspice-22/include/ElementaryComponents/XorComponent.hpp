/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** XorComponent
*/

#ifndef XORCOMPONENT_HPP_
    #include "AndComponent.hpp"
    #define XORCOMPONENT_HPP_

namespace nts {
    class XorComponent : public ElementaryComponent {
        public:
            XorComponent();
            ~XorComponent();
            Tristate compute(size_t pin) override;

        protected:
    };
}

#endif /* !XORCOMPONENT_HPP_ */
