/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** RandomAcessMemoryComponent
*/

#include "../../include/AdvancedComponents/RandomAcessMemoryComponent.hpp"
using namespace nts;

RamComponent::RamComponent()
{
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 8; j++)
            _memory[i][j] = Undefined;
    }
}

RamComponent::~RamComponent()
{}

std::size_t RamComponent::getAddress()
{
    Tristate a0 = getLink(8);
    Tristate a1 = getLink(7);
    Tristate a2 = getLink(6);
    Tristate a3 = getLink(5);
    Tristate a4 = getLink(4);
    Tristate a5 = getLink(3);
    Tristate a6 = getLink(2);
    Tristate a7 = getLink(1);
    Tristate a8 = getLink(23);
    Tristate a9 = getLink(22);

    if (a0 == Undefined || a1 == Undefined || a2 == Undefined || a3 == Undefined || a4 == Undefined || a5 == Undefined || a6 == Undefined || a7 == Undefined || a8 == Undefined || a9 == Undefined)
        return 0;

    std::size_t address = 0;

    if (a0 == True)
        address += 1;
    if (a1 == True)
        address += 2;
    if (a2 == True)
        address += 4;
    if (a3 == True)
        address += 8;
    if (a4 == True)
        address += 16;
    if (a5 == True)
        address += 32;
    if (a6 == True)
        address += 64;
    if (a7 == True)
        address += 128;
    if (a8 == True)
        address += 256;
    if (a9 == True)
        address += 512;

    return address;
}

void RamComponent::simulate(std::size_t tick)
{
    Tristate ce = getLink(18);
    Tristate we = getLink(21);

    if (ce == False && we == False) {
         
        std::size_t address = getAddress();
        if (address == -1)
            return;

        _memory[address][0] = getLink(9);
        _memory[address][1] = getLink(10);
        _memory[address][2] = getLink(11);
        _memory[address][3] = getLink(13);
        _memory[address][4] = getLink(14);
        _memory[address][5] = getLink(15);
        _memory[address][6] = getLink(16);
        _memory[address][7] = getLink(17);
    }
}

Tristate RamComponent::compute(std::size_t pin)
{
    Tristate ce = getLink(18);
    Tristate oe = getLink(20);
    Tristate we = getLink(21);

    if (ce == False && oe == False && we == True) {

        std::size_t address = getAddress();

        switch (pin) {
        case 9: return _memory[address][0];
        case 10: return _memory[address][1];
        case 11: return _memory[address][2];
        case 13: return _memory[address][3];
        case 14: return _memory[address][4];
        case 15: return _memory[address][5];
        case 16: return _memory[address][6];
        case 17: return _memory[address][7];
        default: return Undefined;
        }
    }
    return Undefined;
}
