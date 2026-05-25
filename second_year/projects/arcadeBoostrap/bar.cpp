/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** bar
*/

#include <iostream>
using namespace std;

__attribute__((constructor))
void init()
{
    cout << "[libbar] Loading bar library..." << endl;
}

__attribute__((destructor))
void destroy()
{
    cout << "[libbar] Closing bar..." << endl;
}

extern "C" void myEntryPoint(void)
{
    cout << "[libbar] Entry point for bar!" << endl;
}