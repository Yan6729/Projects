/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** Circuit
*/

#include "../include/Circuit.hpp"
using namespace nts;

Circuit::Circuit()
{}

Circuit::~Circuit()
{}

void checkPinValidity(IComponent *component, size_t pin)
{
    if (dynamic_cast<GatesComponent*>(component)) {
        pin >= 1 && pin <= PinNumber::Gate ? (void)pin : throw CircuitError("Links Error: Invalid pin id");
    } else if (dynamic_cast<ElementaryComponent*>(component)) {
        if (dynamic_cast<NotComponent*>(component)) {
            pin >= 1 && pin <= PinNumber::Elementary - 1 ? (void)pin : throw CircuitError("Links Error: Invalid pin id");
            return;
        }
        pin >= 1 && pin <= PinNumber::Elementary ? (void)pin : throw CircuitError("Links Error: Invalid pin id");
    } else if (dynamic_cast<SpecialComponent*>(component)) {
        pin >= 1 && pin <= PinNumber::Special ? (void)pin : throw CircuitError("Links Error: Invalid pin id");
    } else if (dynamic_cast<AdvancedComponent*>(component)) {
        if (dynamic_cast<RamComponent*>(component) || dynamic_cast<RomComponent*>(component) || dynamic_cast<FourBDComponent*>(component)) {
            pin >= 1 && pin <= PinNumber::Memory ? (void)pin : throw CircuitError("Links Error: Invalid pin id");
            return;
        } else if (dynamic_cast<DFFComponent*>(component)) {
            pin >= 1 && pin <= PinNumber::Advanced - 2 ? (void)pin : throw CircuitError("Links Error: Invalid pin id");
            return;
        } else if (dynamic_cast<LoggerComponent*>(component)) {
            pin >= 1 && pin <= PinNumber::Logger ? (void)pin : throw CircuitError("Links Error: Invalid pin id");
            return;
        } else {
            pin >= 1 && pin <= PinNumber::Advanced ? (void)pin : throw CircuitError("Links Error: Invalid pin id");
            return;
        }
        
    }
}

void Circuit::addComponent(const string& name, const string& type)
{
    if (_components.find(name) != _components.end()) {
        throw CircuitError("Program stoped: You cannot redeclare a composent with the same name two time");
    }
    _components[name] = _factory.createComponent(type);
}

const unique_ptr<IComponent>& Circuit::operator[](const string& name) const
{
    if (_components.find(name) == _components.end()) {
        throw CircuitError("The composent <"+ name + "> isn't in the scop");
    }
    return _components.at(name);
}

void Circuit::operator()(const string& name, const string& type)
{
    if ((_components.find(name) != _components.end())) {
        throw CircuitError("Program stoped: You cannot redeclare a composent with the same name two time");
    }
    _components[name] = _factory.createComponent(type);
}

unique_ptr<IComponent>& Circuit::operator[](const string& name)
{
    if (_components.find(name) == _components.end()) {
        throw CircuitError("The composent <"+ name + "> isn't in the scop");
    }
    return _components[name];
}

void Circuit::setInputVal(const string& name, const string& tristateStr)
{
    if (_components.find(name) == _components.end()) {
        throw CircuitError("The composent <"+ name + "> isn't in the scop");
    }   
    if (!dynamic_cast<SpecialComponent*>(_components[name].get()) || dynamic_cast<OutputComponent*>(_components[name].get())) {
        throw CircuitError("Invalid operation: You cannot assign a value to something else than an input or a clock");
    }
    InputComponent* input = dynamic_cast<InputComponent*>(_components[name].get());
    if (input == nullptr) {
        throw CircuitError("Invalid operation: Component is not an input");
    }
    if (tristateStr == "1") {
        *input = Tristate::True;
    } else if (tristateStr == "0") {
        *input = Tristate::False;
    } else if (tristateStr == "U") {
        *input = Tristate::Undefined;
    }
}

void Circuit::chipset(stringstream& line)
{
    string type = "";
    string name = "";
    string other = "";

    if (line >> type >> name >> other)
        throw CircuitError("Variable declaration syntax error: <type> <name>");
    else {
        if (name.empty())
            throw CircuitError("Variable declaration syntax error: <type> <name>");
        (*this)(name, type);
    }
}

void Circuit::links(stringstream& line)
{
    string first;
    string second;
    string last;

    try {
        if (line >> first >> second >> last)
            throw CircuitError("Set Links Error: Too many arguments/components");
        if (second.empty())
            throw CircuitError("Set Links Error: Not enought components");
        size_t sep1 = first.find(":");
        size_t sep2 = second.find(":");
        if (sep1 == string::npos || sep2 == string::npos)
            throw CircuitError("Set Links Error: Invalid pin forma");
        string comp1 = first.substr(0, sep1);
        string comp2 = second.substr(0, sep2);
        string _pin1 = first.substr(sep1 + 1);
        string _pin2 = second.substr(sep2 + 1);
        if (comp1.empty() || comp2.empty() || _pin1.empty() || _pin2.empty())
            throw CircuitError("Set Links Error: invalid syntax");
        size_t pin1 = stoul(_pin1);
        size_t pin2 = stoul(_pin2);
        checkPinValidity((*this)[comp1].get(), pin1);
        checkPinValidity((*this)[comp2].get(), pin2);
        (*this)[comp1]->setLink(pin1, *(*this)[comp2], pin2);
    } catch (const invalid_argument& e) {
        throw CircuitError("Set Links Error: invalid syntax");
    } catch (const CircuitError& f) {
        throw f;
    }
}

void Circuit::simulate(void)
{
    _tick += 1;

    for (auto& it : _components) {
        if (dynamic_cast<InputComponent *>(it.second.get()))
            it.second->simulate(_tick);
    }

    for (auto& it : _components) {
        if (!dynamic_cast<InputComponent *>(it.second.get()))
            it.second->simulate(_tick);
    }
}

void Circuit::display(void)
{
    cout << "tick: " << _tick << "\n";
    cout << "input(s):" << "\n";
    for (auto& it : _components) {
        if (dynamic_cast<InputComponent*>(it.second.get())) {
            cout << "  " << it.first << ": " << it.second->compute(1) << endl;
        }
    }
    cout << "output(s):" << "\n";
    for (auto& it : _components) {
        if (dynamic_cast<OutputComponent*>(it.second.get())) {
            cout << "  " << it.first << ": " << it.second->compute(1) << endl;
        }
    }
}

void Circuit::loop(atomic<bool>& run)
{
    while (run) {
        this->simulate();
        this->display();
        this_thread::sleep_for(chrono::seconds(1));
    }
}

bool Circuit::noComponent(void)
{
    return _components.empty();
}

string formatLine(const string& line)
{
    size_t pos = line.find('#');
    string newline = line.substr(0, pos);

    replace(newline.begin(), newline.end(), '\t', ' ');

    auto bothAreSpace = [](char l, char r) {
        return l == ' ' && r == ' ';
    };
    newline.erase(unique(newline.begin(), newline.end(), bothAreSpace), newline.end());
    while (!newline.empty() && newline.front() == ' ')
        newline.erase(newline.begin());
    while (!newline.empty() && newline.back() == ' ')
        newline.pop_back();

    return newline;
}

void Circuit::createACircuit(string filepath)
{
    bool normal = false;
    if (filepath.find(".nts") == string::npos) {
        throw CircuitError("File error: the file given as argument is not supported");
    }
    ifstream file(filepath);
    string line;
    int part = 0;

    while (getline(file, line)) {
        if (!formatLine(line).empty()) {
            stringstream ss(formatLine(line));
            if (ss.str().at(0) == '.' && (ss.str() != ".chipsets:" && ss.str() != ".links:"))
                throw CircuitError("Unknown part: the file must only have neither a '.chipsets:' nor a '.links' parts");
            if (ss.str() == ".chipsets:") {
                part = 1;
                normal = true;
                continue;
            }
            else if (ss.str() == ".links:") {
                part = 2;
                normal = true;
                continue;
            }
            if (normal == false)
                throw CircuitError("Invalid command (" + ss.str() + "): command must be inside a '.links' or a '.chipsets'");
            switch (part) {
                case 1:
                    this->chipset(ss);
                    break;
                case 2:
                    this->links(ss);
                    break;
                default:
                    break;
            }
        }
    }
    return;
}
