/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** GatesComponent
*/

#ifndef GATESCOMPONENT_HPP_
    #include "../ElementaryComponents/AndComponent.hpp"
    #include "../ElementaryComponents/OrComponent.hpp"
    #include "../ElementaryComponents/XorComponent.hpp"
    #include "../ElementaryComponents/NotComponent.hpp"
    #define GATESCOMPONENT_HPP_

namespace nts {
    class GatesComponent : virtual public AComponent {
        public:
            GatesComponent();
            ~GatesComponent();

        protected:
    };
}

#endif /* !GATESCOMPONENT_HPP_ */
