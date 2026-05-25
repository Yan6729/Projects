/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** TwelveBitsCounterComponent
*/

#ifndef TWELVEBITSCOUNTERCOMPONENT_HPP_
    #include "AdvancedComponent.hpp"
    #define TWELVEBITSCOUNTERCOMPONENT_HPP_

namespace nts {
    class TwelveBCComponent : public AdvancedComponent {
    public:
        TwelveBCComponent();
        ~TwelveBCComponent();
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;

    private:
        std::size_t _current = 0;
        Tristate _lastClock = Undefined;
        std::size_t _lastTick = 0;
    };
}

#endif /* !TWELVEBITSCOUNTERCOMPONENT_HPP_ */
