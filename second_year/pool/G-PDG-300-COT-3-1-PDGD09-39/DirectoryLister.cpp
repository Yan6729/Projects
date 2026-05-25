/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** DirectoryLister
*/

#include "DirectoryLister.hpp"

DirectoryLister::DirectoryLister()
{}

DirectoryLister::DirectoryLister(const std::string& path, bool hidden)
{
    open(path, hidden);
}

DirectoryLister::~DirectoryLister()
{
}


bool DirectoryLister::open(const std::string& path, bool hidden)
{
    if (stat(path.c_str(), &buf) != -1) {
        _path = path;
        _hidden = hidden;
        if (S_ISDIR(buf.st_mode))
            if ((_dir = opendir(path.c_str())) == nullptr) {
               perror(path.c_str());
               return false;
            }
        return true;
    } else {
        _path = "";
        _hidden = false;
        perror(path.c_str());
        return false;
    }
}

std::string DirectoryLister::get()
{
    struct dirent *entry;
    std::string file;

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
            } else if (_hidden == true) {
                return entry->d_name;
            }
        }
    }
    closedir(_dir);
    _dir = nullptr;
    return "";
}
