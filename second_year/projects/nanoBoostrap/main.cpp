/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** main
*/

#include "InputComponent.hpp"
#include "OutputComponent.hpp"
#include "NotComponent.hpp"
#include "TrueComponent.hpp"
#include "FalseComponent.hpp"
#include "AndComponent.hpp"
#include "OrComponent.hpp"
#include "XorComponent.hpp"

int main ( void )
{
    unique_ptr<nts::IComponent> gate = make_unique<nts::XorComponent>();
    unique_ptr<nts::IComponent> input1 = make_unique<nts::InputComponent>();
    unique_ptr<nts::IComponent> input2 = make_unique<nts::InputComponent>();
    unique_ptr<nts::IComponent> inverter = make_unique<nts::NotComponent>();
    unique_ptr<nts::IComponent> output = make_unique<nts::OutputComponent>();
    gate->setLink(1, *input1, 1);
    gate->setLink(2, *input2, 1);
    inverter->setLink(1 , *gate, 3);
    output->setLink(1, *gate, 3);
    std::cout << "!(" << input1->compute(1) << " && " << input2->compute(1) << ") -> " << output->compute(1) << endl;
}