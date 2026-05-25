/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** main
*/

#include "IDisplayModule.hpp"
#define type_ IDisplayModule* (*)()

vector<string> get_library(const string& dirname)
{
    vector<string> _stock;
    DIR *lib_dir = opendir(dirname.c_str());
    if (lib_dir == nullptr) {
        cerr << "Can't find the lib dir" << endl;
        return _stock;
    }

    struct dirent *entry;
    struct stat buf;

    while ((entry = readdir(lib_dir)) != nullptr) {
        if (stat((dirname + "/" + string(entry->d_name)).c_str(), &buf) == -1) {
            cerr << "Stat failed" << endl;
            continue;
        }
        if (string(entry->d_name).find(".so") != string::npos) {
            _stock.push_back(dirname + "/" + string(entry->d_name));
        }
    }
    closedir(lib_dir);
    return _stock;
}

int main(int ac, char *av[])
{
    vector<string> libnames = get_library("./lib");
    vector<void *> _handles;

    for (auto& it : libnames) {
        _handles.push_back(dlopen(it.c_str(), RTLD_LAZY));
    }
    void *_handle = dlopen("./SdlDisplayModule.so", RTLD_LAZY);
    
    for (auto& handle : _handles) {
        ((void (*)())dlsym(handle, "myEntryPoint"))();
    }
    auto func = (type_)dlsym(_handle, "myEntryPoint");
    IDisplayModule *sld_display = func();

    sld_display->init();
    sld_display->stop();
    cout << sld_display->getName() << endl;
    dlclose(_handle);

    for (auto& it : _handles) {
        dlclose(it);
    }

    DLLoader<IDisplayModule> loadSDL("./SdlDisplayModule.so");
    IDisplayModule *sdl = loadSDL.getInstance("myEntryPoint");
    sdl->init();
    cout << sdl->getName() << endl;
    sdl->stop();
}