/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, Jan, 2026                                                     *
 * Title           - G-PDG-300-COT-3-1-PDGRUSH4-9                                       *
 * Description     -                                                                    *
 *     DateTimeModule                                                                   *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "../../include/modules/DateTimeModule.hpp"
#include <ctime>
#include <iomanip>
#include <sstream>

Krell::DateTimeModule::DateTimeModule() 
{}

Krell::DateTimeModule::~DateTimeModule() 
{}

void Krell::DateTimeModule::update()
{
    std::time_t now = std::time(nullptr);
    struct std::tm *ltm = std::localtime(&now);

    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%d/%m/%Y", ltm);
    
    std::string dateStr = buffer;

    _data["Date"] = dateStr;
}

std::string Krell::DateTimeModule::getName() const
{
    return "Date"; 
}

std::map<std::string, std::string> Krell::DateTimeModule::getData() const
{
    return _data;
}
