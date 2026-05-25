/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
**  HeightBitsShiftRegisterComponent
*/

#ifndef _HEIGHTBITSSHIFTREGISTERCOMPONENT_HPP_
#define _HEIGHTBITSSHIFTREGISTERCOMPONENT_HPP_
#include "AdvancedComponent.hpp"
#include <array>

namespace nts {
    class HeightBSRComponent : public AdvancedComponent {
    public:
        HeightBSRComponent();
        ~HeightBSRComponent();
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;

    private:
        std::array<Tristate, 8> _rgt;
        std::array<Tristate, 8> _output;

        Tristate _lastClock = Undefined;
        Tristate _lastStrobe = Undefined;
        std::size_t _lastTick = 0;
    };
}

#endif /* !_HEIGHTBITSSHIFTREGISTERCOMPONENT_HPP_ */
