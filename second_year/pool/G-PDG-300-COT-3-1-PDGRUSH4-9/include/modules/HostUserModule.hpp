/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, Jan, 2026                                                     *
 * Title           - G-PDG-300-COT-3-1-PDGRUSH4-9                                       *
 * Description     -                                                                    *
 *     HostUserModule                                                                   *
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

#ifndef INCLUDED_HOSTUSERMODULE_HPP
#define INCLUDED_HOSTUSERMODULE_HPP

#include <iostream>
#include <string>
#include "../IModule.hpp"

namespace Krell {
    class HostUserModule : public IModule
    {
    public:
            HostUserModule();
            ~HostUserModule();
            void update() override;
            std::string getName() const override;
            std::map<std::string, std::string> getData() const override;

        private:
            std::map<std::string, std::string> _data;
    };
}

#endif
