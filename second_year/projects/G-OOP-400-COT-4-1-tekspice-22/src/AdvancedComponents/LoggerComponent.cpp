/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** LoggerComponent
*/

#include "../../include/AdvancedComponents/LoggerComponent.hpp"
using namespace nts;

LoggerComponent::LoggerComponent()
{
}

LoggerComponent::~LoggerComponent()
{
}

void LoggerComponent::simulate(size_t _tick) {
    (void)_tick;
    ofstream _file("log.bin", ios::app);
    for (int a = 1; a < 11; a++) {
        if (getLink(a) == Tristate::Undefined)
            return;
    }
    Tristate clock = getLink(9);
    int _001 = getLink(1) == Tristate::True ? 1 : 0;
    int _002 = getLink(2) == Tristate::True ? 2 : 0;
    int _004 = getLink(3) == Tristate::True ? 4 : 0;
    int _008 = getLink(4) == Tristate::True ? 8 : 0;
    int _016 = getLink(5) == Tristate::True ? 16 : 0;
    int _032 = getLink(6) == Tristate::True ? 32 : 0;
    int _064 = getLink(7) == Tristate::True ? 64 : 0;
    int _128 = getLink(8) == Tristate::True ? 128 : 0;
    Tristate inhibit = getLink(10);

    unsigned char _stock = _001 + _002 + _004 + _008 + _016 + _032 + _064 + _128;
    if (inhibit == Tristate::False && _file.is_open() && clock == Tristate::True) {
        _file << _stock;
        _file.close();
        return;
    }
}
