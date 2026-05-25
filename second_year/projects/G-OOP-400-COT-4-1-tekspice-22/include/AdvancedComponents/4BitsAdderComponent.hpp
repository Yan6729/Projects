/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** FourBitsAdderComponent
*/

#ifndef FOURBITSADDERCOMPONENT_HPP_
    #include "AdvancedComponent.hpp"
    #define FOURBITSADDERCOMPONENT_HPP_

namespace nts {
    class FourBAComponent : public AdvancedComponent {
    public:
        FourBAComponent();
        ~FourBAComponent();
        Tristate compute(std::size_t pin) override;

    private:
        Tristate computeSum(Tristate a, Tristate b, Tristate cin) const;
        Tristate computeCarry(Tristate a, Tristate b, Tristate cin) const;
    };
}

#endif /* !FOURBITSADDERCOMPONENT_HPP_ */
