/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** XnorComponent
*/

#ifndef XNORCOMPONENT_HPP_
    #include "AndComponent.hpp"
    #define XNORCOMPONENT_HPP_

namespace nts {
    class XnorComponent : public ElementaryComponent {
        public:
            XnorComponent();
            ~XnorComponent();
            Tristate compute(size_t pin) override;

        protected:
        private:
    };
}

#endif /* !XNORCOMPONENT_HPP_ */
