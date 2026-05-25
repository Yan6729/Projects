/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** DualFlipFlop
*/

#ifndef DUALFLIPFLOP_HPP_
    #include "AdvancedComponent.hpp"
    #define DUALFLIPFLOP_HPP_

namespace nts {
    class DFFComponent : public AdvancedComponent {
    public:
        DFFComponent();
        ~DFFComponent();
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;

    private:
        void updateFlipFlop(Tristate &q, Tristate &_q, Tristate &lastClock, std::size_t clkPin,
                            std::size_t dataPin, std::size_t resetPin, std::size_t setPin);
        Tristate _q1 = Undefined;
        Tristate _q2 = Undefined;
        Tristate q1 = Undefined;
        Tristate q2 = Undefined;

        Tristate _lastClock1 = Undefined;
        Tristate _lastClock2 = Undefined;
        std::size_t _lastTick = 0;
    };
}

#endif /* !DUALFLIPFLOP_HPP_ */
