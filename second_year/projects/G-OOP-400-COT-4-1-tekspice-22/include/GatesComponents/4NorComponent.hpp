/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** FourNorComponent
*/

#ifndef FOURNORCOMPONENT_HPP_
    #include "4OrComponent.hpp"
    #define FOURNORCOMPONENT_HPP_

namespace nts {
    class FourNorComponent : public GatesComponent {
        public:
            FourNorComponent();
            ~FourNorComponent();
            Tristate compute(size_t pin) override;

        private:
    };
}

#endif /* !FOURNORCOMPONENT_HPP_ */
