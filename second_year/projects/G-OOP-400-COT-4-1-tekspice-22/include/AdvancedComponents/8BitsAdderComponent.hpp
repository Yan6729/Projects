/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** 8BitsAdderComponent
*/

#ifndef HEIGHTBITSADDERCOMPONENT_HPP_
    #include "AdvancedComponent.hpp"
    #define HEIGHBITSADDERCOMPONENT_HPP_
namespace nts {
    class HBAComponent: public AdvancedComponent {
        public:
            HBAComponent();
            ~HBAComponent();
            Tristate compute(size_t pin) override;
        private:
            Tristate computeSum(Tristate a, Tristate b, Tristate cin) const;
            Tristate computeCarry(Tristate a, Tristate b, Tristate cin) const;
    };
}

#endif /* !8BITSADDERCOMPONENT_HPP_ */
