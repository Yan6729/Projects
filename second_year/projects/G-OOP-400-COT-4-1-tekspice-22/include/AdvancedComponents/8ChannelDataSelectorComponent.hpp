/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** 8ChannelDataSelectorComponent
*/

#ifndef HEIGHTCHANNELDATASELECTORCOMPONENT_HPP_
#define HEIGHTCHANNELDATASELECTORCOMPONENT_HPP_
#include "AdvancedComponent.hpp"
#include <array>

namespace nts {
    class HeightCDSComponent : public AdvancedComponent {
    public:
        HeightCDSComponent();
        ~HeightCDSComponent();
        Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
    };
}
#endif /* !HEIGHTCHANNELDATASELECTORCOMPONENT_HPP_ */
