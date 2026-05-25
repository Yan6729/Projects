/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** FourNotComponent
*/

#ifndef FOURNOTCOMPONENT_HPP_
    #include "GatesComponent.hpp"
    #define FOURNOTCOMPONENT_HPP_

namespace nts {
    class FourNotComponent : public GatesComponent {
        public:
            FourNotComponent();
            ~FourNotComponent();
            Tristate compute(size_t pin) override;

        protected:
    };
}

#endif /* !FOURNOTCOMPONENT_HPP_ */
