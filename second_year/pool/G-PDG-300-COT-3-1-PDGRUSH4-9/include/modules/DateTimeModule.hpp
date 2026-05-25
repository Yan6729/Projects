/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, Jan, 2026                                                     *
 * Title           - G-PDG-300-COT-3-1-PDGRUSH4-9                                       *
 * Description     -                                                                    *
 *     Date                                                                             *
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

#ifndef DATETIMEMODULE_HPP_
#define DATETIMEMODULE_HPP_

#include <string>
#include "../IModule.hpp"

namespace Krell {
    class DateTimeModule : public IModule {
        public:
            DateTimeModule();
            ~DateTimeModule();

            void update() override;
            std::string getName() const override;
            std::map<std::string, std::string> getData() const override;

        private:
            std::map<std::string, std::string> _data;
    };
}

#endif