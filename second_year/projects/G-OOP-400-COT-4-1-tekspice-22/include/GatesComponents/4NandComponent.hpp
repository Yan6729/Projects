/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** FourNandComponent
*/

#ifndef FOURNANDCOMPONENT_HPP_
    #include "4AndComponent.hpp"
    #define FOURNANDCOMPONENT_HPP_

namespace nts {
    class FourNandComponent : public GatesComponent {
        public:
            FourNandComponent();
            ~FourNandComponent();
            Tristate compute(size_t pin) override;

        private:
    };
}

#endif /* !FOURNANDCOMPONENT_HPP_ */
