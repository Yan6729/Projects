/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** PluginLoader
*/

#ifndef PLUGIN_LOADER_HPP
#define PLUGIN_LOADER_HPP

#include <string>
#include <memory>
#include <dlfcn.h>
#include <stdexcept>


namespace RayTracer {
    class PluginLoader {
    public:
        PluginLoader(const std::string& library_path);
        ~PluginLoader();

        void *loadsymbols(const std::string& sym_name) const;

    private:
        void* handle_;
    };
}

#endif