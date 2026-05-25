/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
    #include "IComponent.hpp"
    #define ACOMPONENT_HPP_

namespace nts {
    class Link {
        public:
            IComponent *other;
            size_t pin;
    };

    class CircuitError : public exception {
        public:
            CircuitError(const string& message);
            ~CircuitError();
            virtual const char* what(void) const noexcept override;
        private:
            string _msg;
    };

    struct Verified {
        IComponent *cmp;
        size_t pin;

        bool operator==(const Verified& other) const {
            return cmp == other.cmp && pin == other.pin;
        }
    };

    struct VerifiedHash {
        size_t operator()(const Verified& ver) const {
            size_t h1 = hash<const IComponent *>{}(ver.cmp);
            size_t h2 = hash<size_t>{}(ver.pin);
            return h1 ^ h2;
        }
    };

    class AComponent : public nts::IComponent {
        public:
            AComponent();
            ~AComponent();
            virtual nts::Tristate compute(size_t pin) = 0;
            void simulate(size_t tick);
            void setLink(size_t pin, nts::IComponent &other, size_t otherPin);
            nts::Tristate getLink(size_t pin);

        protected:
            map<size_t, Link> _pins;
    };
}

#endif /* !ACOMPONENT_HPP_ */
