/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** ComponentFactory
*/

#ifndef COMPONENTFACTORY_HPP_
    #include "SpecialComponents/InputComponent.hpp"
    #include "SpecialComponents/OutputComponent.hpp"
    #include "SpecialComponents/TrueComponent.hpp"
    #include "SpecialComponents/FalseComponent.hpp"
    #include "SpecialComponents/ClockComponent.hpp"
    #include "ElementaryComponents/AndComponent.hpp"
    #include "ElementaryComponents/OrComponent.hpp"
    #include "ElementaryComponents/NotComponent.hpp"
    #include "ElementaryComponents/XorComponent.hpp"
    #include "ElementaryComponents/NandComponent.hpp"
    #include "ElementaryComponents/NorComponent.hpp"
    #include "ElementaryComponents/XnorComponent.hpp"
    #include "GatesComponents/4AndComponent.hpp"
    #include "GatesComponents/4OrComponent.hpp"
    #include "GatesComponents/4NandComponent.hpp"
    #include "GatesComponents/4NorComponent.hpp"
    #include "GatesComponents/4XorComponent.hpp"
    #include "GatesComponents/6NotComponent.hpp"
    #include "AdvancedComponents/4BitsAdderComponent.hpp"
    #include "AdvancedComponents/8BitsAdderComponent.hpp"
    #include "AdvancedComponents/4BitsDecoderComponent.hpp"
    #include "AdvancedComponents/8BitsShiftRegisterComponent.hpp"
    #include "AdvancedComponents/8ChannelDataSelectorComponent.hpp"
    #include "AdvancedComponents/10BitsJohnsonDecadeComponent.hpp"
    #include "AdvancedComponents/12BitsCounterComponent.hpp"
    #include "AdvancedComponents/DualFlipFlopComponent.hpp"
    #include "AdvancedComponents/RandomAcessMemoryComponent.hpp"
    #include "AdvancedComponents/ReadOnlyMemoryComponent.hpp"
    #include "AdvancedComponents/LoggerComponent.hpp"
    #define COMPONENTFACTORY_HPP_

namespace nts {
    class ComponentFactory {
        public:
            ComponentFactory();
            ~ComponentFactory();
            unique_ptr<IComponent> createComponent(const string& type);

        private:
            map<string, function<unique_ptr<IComponent>()>> _functions;
    };
}

#endif /* !COMPONENTFACTORY_HPP_ */
