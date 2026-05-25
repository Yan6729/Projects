/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** ElementaryComponent
*/

#ifndef ELEMENTARYCOMPONENT_HPP_
    #include "../AComponent.hpp"
    #define ELEMENTARYCOMPONENT

namespace nts {
    class ElementaryComponent : virtual public nts::AComponent {
        public:
            ElementaryComponent();
            ~ElementaryComponent();

        private:
    };
}

#endif /* !ELEMENTARYCOMPONENT_HPP_ */
