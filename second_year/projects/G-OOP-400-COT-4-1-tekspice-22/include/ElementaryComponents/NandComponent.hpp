/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** NandComponent
*/

#ifndef NANDCOMPONENT_HPP_
    #include "AndComponent.hpp"
    #define NANDCOMPONENT_HPP_

namespace nts {
    class NandComponent : public ElementaryComponent {
        public:
            NandComponent();
            ~NandComponent();
            Tristate compute(size_t pin) override;

        protected:
        private:
    };
}

#endif /* !NANDCOMPONENT_HPP_ */
