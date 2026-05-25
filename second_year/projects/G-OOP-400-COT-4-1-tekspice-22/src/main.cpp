/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** main
*/

#include "../include/Circuit.hpp"
using namespace nts;

atomic<bool> run(true);

void cmd_error(string cmd)
{
    if (cmd != "display" && cmd != "loop" && cmd != "exit" && cmd != "simulate" && cmd.find("=") == string::npos)
        throw CircuitError("Unknown command: <" + cmd + "> is not a command");
}

void handle_signal(int signum)
{
    if (signum == SIGINT) {
        run = false;
    }
}

void assignment(const string& cmd, Circuit& _circuit)
{
    size_t pos = cmd.find("=");
    string var = cmd.substr(0, pos);
    string val = cmd.substr(pos + 1);

    if (val.find("=") != string::npos || val.empty())
        throw CircuitError("Invalid syntax: invalid value assignment");
    _circuit.setInputVal(var, val);
}

int main(int ac, char *av[])
{
    try {
        if (ac < 2) {
            throw CircuitError("File error: Not enought arguments");
        }
        size_t tick = 0;
        Circuit _circuit;
        string line;
        _circuit.createACircuit(av[1]);
        if (_circuit.noComponent() == true)
            throw CircuitError("Invalid file: can't found any component");
        signal(SIGINT, handle_signal);
        while (true) {
            cout << "> ";
            if (getline(cin, line)) {
                stringstream cmd(formatLine(line));
                cmd_error(cmd.str());
                if (cmd.str().find("=") != string::npos) {
                    assignment(cmd.str(), _circuit);
                    cmd.clear();
                } else if (cmd.str() == "display") {
                    _circuit.display();
                } else if (cmd.str() == "simulate") {
                    _circuit.simulate();
                } else if (cmd.str() == "loop") {
                    _circuit.loop(run);
                } else if (cmd.str() == "exit")
                    return 0;
            } else if (cin.eof() || cin.fail()) {
                return 0;
            }
       }
    } catch (const CircuitError& e) {
        cerr << e.what() << endl;
        return 84;
    }
}
