/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
    #define IDISPLAYMODULE_HPP_
    #include <iostream>
    #include <string>
    #include <dlfcn.h>
    #include "DLLoader.hpp"
    #include <sys/stat.h>
    #include <dirent.h>
    using namespace std;

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;
        virtual void init(void) = 0;
        virtual void stop(void) = 0;
        virtual const string& getName() const = 0;
};

#endif /* !IDISPLAYMODULE_HPP_ */
