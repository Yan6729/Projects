/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** ReadOnlyMemoryComponent
*/

#include "../../include/AdvancedComponents/ReadOnlyMemoryComponent.hpp"
using namespace nts;

RomComponent::RomComponent()
{
    std::ifstream file("rom.bin", std::ios::in | std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Erreur d'ouverture du fichier" << std::endl;
        return;
    }
    int i = 0;
    int val_asci;
    while (i < 2048 && (val_asci = file.get()) > 0) {
        auto translate = convert_to_binary(val_asci);
        for (int j = 0; j < 8; j++) {
            _memory[i][j] = translate[7 - j];
        }
        i++;
    }
}

RomComponent::~RomComponent()
{}

std::vector<Tristate> RomComponent::convert_to_binary(unsigned char n)
{
    std::vector<Tristate> bin(8, Tristate::False);
    for (int i = 0; i < 8; i++) {
        if (n & (1 << i))
            bin[7 - i] = True;
    }
    return bin;
}

std::size_t RomComponent::getAddress()
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
    Tristate a10 = getLink(19);

    if (a0 == Undefined || a1 == Undefined || a2 == Undefined || a3 == Undefined || a4 == Undefined || a5 == Undefined || a6 == Undefined || a7 == Undefined || a8 == Undefined || a9 == Undefined || a10 == Undefined)
        return -1;

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
    if (a10 == True)
	address += 1024;

    return address;
}

Tristate RomComponent::compute(std::size_t pin)
{
    Tristate ce = getLink(18);
    Tristate oe = getLink(20);

    if (ce == False && oe == False) {
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
