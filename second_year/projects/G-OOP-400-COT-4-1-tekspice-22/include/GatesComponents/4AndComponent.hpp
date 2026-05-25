/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** FourandComponent
*/

#ifndef FOURANDCOMPONENT_HPP_
    #include "GatesComponent.hpp"
    #define FOURANDCOMPONENT_HPP_

namespace nts {
    class FourAndComponent : public GatesComponent {
        public:
            FourAndComponent();
            ~FourAndComponent();
            Tristate compute(size_t pin) override;

        protected:
        private:
    };
}

#endif /* !FOURANDCOMPONENT_HPP_ */
