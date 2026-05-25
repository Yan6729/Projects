/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** FourXorComponent
*/

#ifndef FOURXORCOMPONENT_HPP_
    #include "GatesComponent.hpp"
    #define FOURXORCOMPONENT_HPP_

namespace nts {
    class FourXorComponent : public GatesComponent {
        public:
            FourXorComponent();
            ~FourXorComponent();
            Tristate compute(size_t pin) override;

        protected:
        private:
    };
}

#endif /* !FOURXORCOMPONENT_HPP_ */
