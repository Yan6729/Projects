/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** ReadOnlyMemoryComponent
*/

#ifndef READONLYMEMORYCOMPONENT_HPP_
    #include "AdvancedComponent.hpp"
    #define READONLYMEMORYCOMPONENT_HPP_

namespace nts {
    class RomComponent : public AdvancedComponent {
    public:
        RomComponent();
        ~RomComponent();
        Tristate compute(std::size_t pin) override;

    private:
        Tristate _memory[2048][8];
        std::vector<Tristate> convert_to_binary(unsigned char n);
        std::size_t getAddress();
    };
}

#endif /* !READONLYMEMORYCOMPONENT_HPP_ */
