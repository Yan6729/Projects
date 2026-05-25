/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** main
*/

#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>

int main(int ac, char **av)
{
    void *handle = dlopen("./libfoo.so", RTLD_LAZY);

    void (*_func)() = (void (*)())dlsym(handle, "myEntryPoint");
    _func();
    
    dlclose(handle);
}