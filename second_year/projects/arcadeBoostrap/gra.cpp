/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** gra
*/

#include <iostream>
using namespace std;

__attribute__((constructor))
void init()
{
    cout << "[libgra] Loading gra library..." << endl;
}

__attribute__((destructor))
void destroy()
{
    cout << "[libgra] Gra's getting out..." << endl;
}

extern "C" void myEntryPoint(void)
{
    cout << "[libgra] Another entry point!!" << endl;
}