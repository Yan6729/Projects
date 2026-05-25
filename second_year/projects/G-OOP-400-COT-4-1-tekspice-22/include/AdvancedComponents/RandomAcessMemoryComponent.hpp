/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** RandomAcessMemoryComponent
*/

#ifndef RANDOMACESSMEMORYCOMPONENT_HPP_
    #include "AdvancedComponent.hpp"
    #define RANDOMACESSMEMORYCOMPONENT_HPP_

namespace nts {
    class RamComponent : public AdvancedComponent {
    public:
        RamComponent();
        ~RamComponent();
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;

    protected:
        Tristate _memory[1024][8];
        std::size_t _lastTick = 0;
        std::size_t getAddress();
    };
}

#endif /* !RANDOMACESSMEMORYCOMPONENT_HPP_ */
