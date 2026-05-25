/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** DirectoryLister
*/

#ifndef DIRECTORYLISTER_HPP_
    #include "IDirectoryLister.hpp"
    #define DIRECTORYLISTER_HPP_

class DirectoryLister : public IDirectoryLister {
    public:
        DirectoryLister();
        DirectoryLister(const DirectoryLister& other) = delete;
        DirectoryLister(const DirectoryLister&& other) noexcept = delete;
        DirectoryLister operator=(const DirectoryLister& other) = delete;
        DirectoryLister(const std::string& path, bool hidden);
        ~DirectoryLister();
        bool open(const std::string& path, bool hidden);
        std::string get(void);

    private:
        std::string _path = ".";
        bool _hidden;
        struct stat buf;
        DIR* _dir = nullptr;
};

#endif /* !DIRECTORYLISTER_HPP_ */
