/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** NorComponent
*/

#ifndef NORCOMPONENT_HPP_
    #include "AndComponent.hpp"
    #define NORCOMPONENT_HPP_

namespace nts {
    class NorComponent : public ElementaryComponent {
        public:
            NorComponent();
            ~NorComponent();
            Tristate compute(size_t pin) override;

        protected:
        private:
    };
}

#endif /* !NORCOMPONENT_HPP_ */
