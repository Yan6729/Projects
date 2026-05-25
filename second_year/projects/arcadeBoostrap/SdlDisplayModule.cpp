/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** SdlDisplayModule
*/

#include "SdlDisplayModule.hpp"

SDLDisplayModule::SDLDisplayModule()
{
    _name = "SDLDisplayModule";
}

SDLDisplayModule::~SDLDisplayModule()
{
}

void SDLDisplayModule::init(void)
{
    cout << "init the sld display module" << endl;
}

void SDLDisplayModule::stop(void)
{
    cout << "stop the sdl display module" << endl;
}

const string& SDLDisplayModule::getName(void) const
{
    return this->_name;
}

extern "C" IDisplayModule* myEntryPoint(void)
{
    return new SDLDisplayModule;
}
