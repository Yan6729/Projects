/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
    #include "ComponentFactory.hpp"
    #define CIRCUIT_HPP_

namespace nts {
    class Circuit {
        public:
            Circuit();
            ~Circuit();
            void addComponent(const string& name, const string& type);
            void operator()(const string& name, const string& type);
            const unique_ptr<IComponent>& operator[](const string& name) const;
            unique_ptr<IComponent>& operator[](const string& name);
            void setInputVal(const string& name, const string& tristateStr);
            void chipset(stringstream& line);
            void links(stringstream& line);
            void simulate(void);
            void loop(atomic<bool>& run);
            void display(void);
            bool noComponent(void);
            void createACircuit(string filepath);

        private:
            ComponentFactory _factory;
            size_t _tick = 0;
            map<string, unique_ptr<IComponent>> _components;
    };
}
string formatLine(const string& line);

#endif /* !CIRCUIT_HPP_ */
