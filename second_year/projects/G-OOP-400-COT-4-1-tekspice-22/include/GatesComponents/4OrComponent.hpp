/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** ForOrComponent
*/

#ifndef FOURORCOMPONENT_HPP_
    #include "GatesComponent.hpp"
    #define FOURORCOMPONENT_HPP_

namespace nts {
    class FourOrComponent : public GatesComponent {
        public:
            FourOrComponent();
            ~FourOrComponent();
            Tristate compute(size_t pin) override;

        protected:
        private:
    };
}

#endif /* !FOURORCOMPONENT_HPP_ */
