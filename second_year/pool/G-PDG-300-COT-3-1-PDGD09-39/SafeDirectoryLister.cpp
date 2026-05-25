/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** SafeDirectoryLister
*/

#include "SafeDirectoryLister.hpp"

SafeDirectoryLister::SafeDirectoryLister()
{
}

SafeDirectoryLister::SafeDirectoryLister(const std::string& path, bool hidden)
{
    open(path, hidden);
}

SafeDirectoryLister::~SafeDirectoryLister()
{
}


bool SafeDirectoryLister::open(const std::string& path, bool hidden)
{
    if (stat(path.c_str(), &buf) != -1) {
        _path = path;
        _hidden = hidden;
        if (S_ISDIR(buf.st_mode))
            if ((_dir = opendir(path.c_str())) == nullptr) {
              throw IDirectoryLister::OpenFailureException();
               return false;
            }
        return true;
    } else {
        _path = "";
        _hidden = false;
        throw IDirectoryLister::OpenFailureException();
        return false;
    }
}

std::string SafeDirectoryLister::get()
{
    struct dirent *entry;

    if (!S_ISDIR(buf.st_mode)) {
        std::string file = _path;
        _path = "";
        return file;
    }
    if (_dir != nullptr) {
        while ((entry = readdir(_dir)) != nullptr) {
            if (_hidden == false) {
                if (entry->d_name[0] != '.') {
                    return entry->d_name;
                }
            } else {
                return entry->d_name;
            }
        }
    }
    closedir(_dir);
    _dir = nullptr;
    if (entry == nullptr) {
        throw IDirectoryLister::NoMoreFileException();
    }
    return "";
}
