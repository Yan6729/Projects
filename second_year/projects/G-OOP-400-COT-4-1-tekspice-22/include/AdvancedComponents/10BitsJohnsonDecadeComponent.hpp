/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** TenBitsJohnsonDecadeComponent
*/

#ifndef TENBITSJOHNSONDECADECOMPONENT_HPP_
    #include "AdvancedComponent.hpp"
    #define TENBITSJOHNSONDECADECOMPONENT_HPP_

namespace nts {
    class TenBJDComponent : public AdvancedComponent {
    public:
        TenBJDComponent();
        ~TenBJDComponent();
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;

    private:
        std::size_t _current = 0;
        Tristate _lastCP0 = Undefined;
        Tristate _lastCP1 = Undefined;
        std::size_t _lastTick = 0;
    };
}

#endif /* !TENBITSJOHNSONDECADECOMPONENT_HPP_ */
