/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** foo
*/
#include <iostream>
using namespace std;

__attribute__((constructor))
void init()
{
    cout << "[libfoo] Loading foo library..." << endl;
}

__attribute__((destructor))
void destroy()
{
    cout << "[libfoo] foo closing..." << endl;
}

extern "C" void myEntryPoint(void)
{
    cout << "[libfoo] Entry point for foo!" << endl;
}
