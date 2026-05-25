/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** CoreEngine
*/

#include "../include/CoreEngine.hpp"

CoreEngine::CoreEngine()
{
    _opp["addition"].createACircuit("./bonus/src/addition.nts");
    _opp["substraction"].createACircuit("./bonus/src/substraction.nts");
}

CoreEngine::~CoreEngine()
{
}

int converChar(char s)
{
    switch (s) {
        case '0':
            return 0;
        case '1':
            return 1;
        default:
            break;
    }
    return -1;
}

string CoreEngine::calcul(string opperation)
{
    stringstream _dec(opperation);
    int _first;
    string symbol;
    int _second;
    if (_dec.str()[_dec.str().length() - 1] == ' ')
        return "error";
    _dec >> _first >> symbol >> _second;

    if (symbol.empty())
        return to_string(_first);
    if (_first > 255 || _second > 255)
        return "out of range";
    string first = bitset<8>(_first).to_string();
    string second = bitset<8>(_second).to_string();
    if (symbol == "+") {
        _opp["addition"].setInputVal("a1", to_string(first[7] - '0'));
        _opp["addition"].setInputVal("a2", to_string(first[6] - '0'));
        _opp["addition"].setInputVal("a3", to_string(first[5] - '0'));
        _opp["addition"].setInputVal("a4", to_string(first[4] - '0'));
        _opp["addition"].setInputVal("a5", to_string(first[3] - '0'));
        _opp["addition"].setInputVal("a6", to_string(first[2] - '0'));
        _opp["addition"].setInputVal("a7", to_string(first[1] - '0'));
        _opp["addition"].setInputVal("a8", to_string(first[0] - '0'));
        _opp["addition"].setInputVal("b1", to_string(second[7] - '0'));
        _opp["addition"].setInputVal("b2", to_string(second[6] - '0'));
        _opp["addition"].setInputVal("b3", to_string(second[5] - '0'));
        _opp["addition"].setInputVal("b4", to_string(second[4] - '0'));
        _opp["addition"].setInputVal("b5", to_string(second[3] - '0'));
        _opp["addition"].setInputVal("b6", to_string(second[2] - '0'));
        _opp["addition"].setInputVal("b7", to_string(second[1] - '0'));
        _opp["addition"].setInputVal("b8", to_string(second[0] - '0'));
        _opp["addition"].simulate();

        int in_001 = _opp["addition"]["s1"]->compute(1) == Tristate::True ? 1 : 0;
        int in_002 = _opp["addition"]["s2"]->compute(1) == Tristate::True ? 2 : 0;
        int in_004 = _opp["addition"]["s3"]->compute(1) == Tristate::True ? 4 : 0;
        int in_008 = _opp["addition"]["s4"]->compute(1) == Tristate::True ? 8 : 0;
        int in_016 = _opp["addition"]["s5"]->compute(1) == Tristate::True ? 16 : 0;
        int in_032 = _opp["addition"]["s6"]->compute(1) == Tristate::True ? 32 : 0;
        int in_064 = _opp["addition"]["s7"]->compute(1) == Tristate::True ? 64 : 0;
        int in_128 = _opp["addition"]["s8"]->compute(1) == Tristate::True ? 128 : 0;
        int result = in_001 + in_002 + in_004 + in_008 + in_016 + in_032 + in_064 + in_128;
        if (result > 255)
            return "out of range";
        return to_string(result);
    } else if (symbol == "*") {
        int result = 0;
        for (int i = 0; i < _second; i++) {
            string first = bitset<8>(result).to_string();
            string second = bitset<8>(_first).to_string();

            for (int j = 0; j < 8; j++) {
                _opp["addition"].setInputVal("a" + to_string(j+1), to_string(first[7-j]-'0'));
                _opp["addition"].setInputVal("b" + to_string(j+1), to_string(second[7-j]-'0'));
            }
            _opp["addition"].simulate();

            int in_001 = _opp["addition"]["s1"]->compute(1) == Tristate::True ? 1 : 0;
            int in_002 = _opp["addition"]["s2"]->compute(1) == Tristate::True ? 2 : 0;
            int in_004 = _opp["addition"]["s3"]->compute(1) == Tristate::True ? 4 : 0;
            int in_008 = _opp["addition"]["s4"]->compute(1) == Tristate::True ? 8 : 0;
            int in_016 = _opp["addition"]["s5"]->compute(1) == Tristate::True ? 16 : 0;
            int in_032 = _opp["addition"]["s6"]->compute(1) == Tristate::True ? 32 : 0;
            int in_064 = _opp["addition"]["s7"]->compute(1) == Tristate::True ? 64 : 0;
            int in_128 = _opp["addition"]["s8"]->compute(1) == Tristate::True ? 128 : 0;

            result = in_001 + in_002 + in_004 + in_008 + in_016 + in_032 + in_064 + in_128;
        }
        if (result > 255)
            return "out of range";
        return to_string(result);
    } else if (symbol == "-") {
        _opp["substraction"].setInputVal("a1", to_string(first[7] - '0'));
        _opp["substraction"].setInputVal("a2", to_string(first[6] - '0'));
        _opp["substraction"].setInputVal("a3", to_string(first[5] - '0'));
        _opp["substraction"].setInputVal("a4", to_string(first[4] - '0'));
        _opp["substraction"].setInputVal("a5", to_string(first[3] - '0'));
        _opp["substraction"].setInputVal("a6", to_string(first[2] - '0'));
        _opp["substraction"].setInputVal("a7", to_string(first[1] - '0'));
        _opp["substraction"].setInputVal("a8", to_string(first[0] - '0'));
        _opp["substraction"].setInputVal("b1", to_string(second[7] - '0'));
        _opp["substraction"].setInputVal("b2", to_string(second[6] - '0'));
        _opp["substraction"].setInputVal("b3", to_string(second[5] - '0'));
        _opp["substraction"].setInputVal("b4", to_string(second[4] - '0'));
        _opp["substraction"].setInputVal("b5", to_string(second[3] - '0'));
        _opp["substraction"].setInputVal("b6", to_string(second[2] - '0'));
        _opp["substraction"].setInputVal("b7", to_string(second[1] - '0'));
        _opp["substraction"].setInputVal("b8", to_string(second[0] - '0'));
        _opp["substraction"].simulate();

        int in_001 = _opp["substraction"]["s1"]->compute(1) == Tristate::True ? 1 : 0;
        int in_002 = _opp["substraction"]["s2"]->compute(1) == Tristate::True ? 2 : 0;
        int in_004 = _opp["substraction"]["s3"]->compute(1) == Tristate::True ? 4 : 0;
        int in_008 = _opp["substraction"]["s4"]->compute(1) == Tristate::True ? 8 : 0;
        int in_016 = _opp["substraction"]["s5"]->compute(1) == Tristate::True ? 16 : 0;
        int in_032 = _opp["substraction"]["s6"]->compute(1) == Tristate::True ? 32 : 0;
        int in_064 = _opp["substraction"]["s7"]->compute(1) == Tristate::True ? 64 : 0;
        int in_128 = _opp["substraction"]["s8"]->compute(1) == Tristate::True ? 128 : 0;
        int result = in_001 + in_002 + in_004 + in_008 + in_016 + in_032 + in_064 + in_128;
        return to_string(result);
    } else if (symbol == "/") {
        if (_second == 0)
            return "error";

        int dividend = _first;
        int divisor = _second;
        int quotient = 0;
        while (dividend >= divisor) {
            string first = bitset<8>(dividend).to_string();
            string second = bitset<8>(divisor).to_string();

            for (int j = 0; j < 8; j++) {
                _opp["substraction"].setInputVal("a" + to_string(j+1), to_string(first[7-j]-'0'));
                _opp["substraction"].setInputVal("b" + to_string(j+1), to_string(second[7-j]-'0'));
            }
            _opp["substraction"].simulate();

            int in_001 = _opp["substraction"]["s1"]->compute(1) == Tristate::True ? 1 : 0;
            int in_002 = _opp["substraction"]["s2"]->compute(1) == Tristate::True ? 2 : 0;
            int in_004 = _opp["substraction"]["s3"]->compute(1) == Tristate::True ? 4 : 0;
            int in_008 = _opp["substraction"]["s4"]->compute(1) == Tristate::True ? 8 : 0;
            int in_016 = _opp["substraction"]["s5"]->compute(1) == Tristate::True ? 16 : 0;
            int in_032 = _opp["substraction"]["s6"]->compute(1) == Tristate::True ? 32 : 0;
            int in_064 = _opp["substraction"]["s7"]->compute(1) == Tristate::True ? 64 : 0;
            int in_128 = _opp["substraction"]["s8"]->compute(1) == Tristate::True ? 128 : 0;

            dividend = in_001 + in_002 + in_004 + in_008 + in_016 + in_032 + in_064 + in_128;
            quotient++;
        }
        return to_string(quotient);
    }
    return "error";
}
