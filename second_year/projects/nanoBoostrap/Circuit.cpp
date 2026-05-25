/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** Circuit
*/

#include "Circuit.hpp"
using namespace nts;

Circuit::Circuit()
{}

Circuit::~Circuit()
{}

void Circuit::addComponent(string name, string type)
{
    ComponentFactory factory;
    _circuit[name] = factory.createComponent(type);
}
