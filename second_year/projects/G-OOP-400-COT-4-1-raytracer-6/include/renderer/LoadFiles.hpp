/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** LoadFiles
*/

#ifndef LOADFILES_HPP_
    #define LOADFILES_HPP_
    #include <iostream>
    #include <string>
    #include <vector>
    #include <dirent.h>
    #include "../rayTracerError.hpp"

namespace RayTracer {
    class LoadFiles {
        public:
            LoadFiles(const std::string& dirname);
            ~LoadFiles();
            std::vector<std::string> getfiles(void);

        private:
            std::vector<std::string> _filelist;
            DIR *_dir;
            struct dirent *_entry;
    };
}

#endif /* !LOADFILES_HPP_ */
