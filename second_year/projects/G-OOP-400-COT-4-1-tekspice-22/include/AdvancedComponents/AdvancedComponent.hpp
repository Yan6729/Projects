/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** AdvancedComponent
*/

#ifndef ADVANCEDCOMPONENT_HPP_
    #include "../AComponent.hpp"
    #define ADVANCEDCOMPONENT_HPP_

namespace nts {
    class AdvancedComponent : virtual public AComponent {
    public:
        AdvancedComponent();
        ~AdvancedComponent();
        void simulate(std::size_t tick) override;
        Tristate compute(size_t pin) override;

    protected:
    private:
    };
}

#endif /* !ADVANCEDCOMPONENT_HPP_ */
