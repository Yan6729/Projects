/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** 4BitsDecoderComponent
*/

#ifndef FOURBITSDECODERCOMPONENT_HPP_
    #include "AdvancedComponent.hpp"
    #define FOURBITSDECODERCOMPONENT_HPP_

namespace nts {
    class FourBDComponent : public AdvancedComponent {
    public:
        FourBDComponent();
        ~FourBDComponent();
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;

    private:
        std::size_t _latchedIndex;
        Tristate _lastStrobe;
        std::array<Tristate, 16> _outputs;
        std::size_t _lastTick = 0;
    };
}

#endif /* !4BITSDECODERCOMPONENT_HPP_ */
