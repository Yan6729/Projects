/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
    #include <iostream>
    #include <string>
    #include <map>
    #include <list>
    #include <memory>
    #include <functional>
    #include <errno.h>
    #include <exception>
    #include <cstring>
    #include <sstream>
    #include <fstream>
    #include <csignal>
    #include <atomic>
    #include <iomanip>
    #include <unordered_set>
    #include <thread>
    #include <algorithm>
    #include <chrono>
    #include <cmath>
    #include <numbers>
    #define ICOMPONENT_HPP_
using namespace std;

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false,
        Void = 2
    };

    enum PinNumber {
        Special = 1,
        Elementary = 3,
        Gate = 14,
        Advanced = 16,
        Memory = 24,
        Logger = 10,
    };

    Tristate operator&&(const Tristate& one, const Tristate& two);
    Tristate operator||(const Tristate& one, const Tristate& two);
    Tristate operator!(const Tristate& one);
    Tristate operator^(const Tristate& one, const Tristate& two);

    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void simulate(std::size_t tick) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
    };
}

std::ostream& operator<<(std::ostream& s, nts::Tristate v);

#endif /* !ICOMPONENT_HPP_ */
