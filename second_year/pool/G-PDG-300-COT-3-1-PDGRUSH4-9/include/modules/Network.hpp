/*
** EPITECH PROJECT, 2026
** Network.hpp
** File description:
** Network.hpp
*/

#ifndef NETWORK_HPP
    #define NETWORK_HPP
    #include "../IModule.hpp"
    #include <iostream>
    #include <string>
    #include <fstream>
    #include <sstream>
    #include <vector>
    #include <map>

namespace Krell {
    class Network : public IModule{
        public:
            Network();
            std::string getName() const override;
            void update() override;
            std::map<std::string, std::string> getData() const override;

        protected:
        private:
            std::string ipAddress;
            std::string value_compl;
            std::map<std::string, std::string> monNet;
            
    };
}

#endif /* !NETWORK_HPP */
