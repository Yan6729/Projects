/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** ComponentFactory
*/

#include "../include/ComponentFactory.hpp"
using namespace nts;

ComponentFactory::ComponentFactory()
{
    _functions["input"] = [](){ return make_unique<InputComponent>(); };
    _functions["output"] = [](){ return make_unique<OutputComponent>(); };
    _functions["false"] = [](){ return make_unique<FalseComponent>(); } ;
    _functions["true"] = [](){ return make_unique<TrueComponent>(); };
    _functions["clock"] = [](){ return make_unique<ClockComponent>(); };
    _functions["and"] = [](){ return make_unique<AndComponent>(); };
    _functions["or"] = [](){ return make_unique<OrComponent>(); };
    _functions["xor"] = [](){ return make_unique<XorComponent>(); };
    _functions["nand"] = [](){ return make_unique<NandComponent>(); };
    _functions["nor"] = [](){ return make_unique<NorComponent>(); };
    _functions["xnor"] = [](){ return make_unique<XnorComponent>(); };
    _functions["not"] = [](){ return make_unique<NotComponent>(); };
    _functions["4001"] = [](){ return make_unique<FourNorComponent>(); };
    _functions["4011"] = [](){ return make_unique<FourNandComponent>(); };
    _functions["4030"] = [](){ return make_unique<FourXorComponent>(); };
    _functions["4069"] = [](){ return make_unique<FourNotComponent>(); };
    _functions["4071"] = [](){ return make_unique<FourOrComponent>(); };
    _functions["4081"] = [](){ return make_unique<FourAndComponent>(); };
    _functions["4008"] = [](){ return make_unique<FourBAComponent>(); };
    _functions["4013"] = [](){ return make_unique<DFFComponent>(); };
    _functions["4017"] = [](){ return make_unique<TenBJDComponent>(); };
    _functions["4040"] = [](){ return make_unique<TwelveBCComponent>(); };
    _functions["4094"] = [](){ return make_unique<HeightBSRComponent>(); };
    _functions["4512"] = [](){ return make_unique<HeightCDSComponent>(); };
    _functions["4514"] = [](){ return make_unique<FourBDComponent>(); };
    _functions["4801"] = [](){ return make_unique<RamComponent>(); };
    _functions["2716"] = [](){ return make_unique<RomComponent>(); };
    _functions["logger"] = [](){ return make_unique<LoggerComponent>(); };
    _functions["8008"] = [](){ return make_unique<HBAComponent>(); };
}

ComponentFactory::~ComponentFactory()
{}

unique_ptr<IComponent>ComponentFactory::createComponent(const string& type)
{
    if (_functions.find(type) == _functions.end()) {
        throw CircuitError("Unknown type: <" + type + "> is not a type");
    }
    return _functions[type]();
}
