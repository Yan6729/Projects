/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** RamModule
*/

#ifndef RAMMODULE_HPP_
    #include "../IModule.hpp"
#define RAMMODULE_HPP_

namespace Krell {
    class RamModule : public IModule {
        public:
            RamModule();
            ~RamModule();
            std::string getName() const;
            void update();
            std::map<std::string, std::string> getData() const;

        private:
            std::map<std::string, std::string> _ramInfo;
    };
}

std::map<std::string, double> getMemInfo(void);
#endif /* !RAMMODULE_HPP_ */
