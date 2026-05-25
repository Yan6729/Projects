/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** LoadFiles
*/

#include "../../include/renderer/LoadFiles.hpp"

namespace RayTracer {
    LoadFiles::LoadFiles(const std::string& dirname)
    {
        _dir = opendir(dirname.c_str());

        if (!_dir)
            throw RayTracerError("Error while trying to open the directory: " + dirname);
    }

    LoadFiles::~LoadFiles()
    {
    }

    std::vector<std::string> LoadFiles::getfiles(void) {
        while ((_entry = readdir(_dir)) != nullptr) {
            if (_entry->d_type == DT_REG)
                _filelist.push_back(_entry->d_name);
        }
        closedir(_dir);
        return _filelist;
    }
}