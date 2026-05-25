/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** SafeDirectoryLister
*/

#ifndef SAFEDIRECTORYLISTER_HPP_
    #include "IDirectoryLister.hpp"
    #define SAFEDIRECTORYLISTER_HPP_

class SafeDirectoryLister : public IDirectoryLister {
    public:
        SafeDirectoryLister();
        SafeDirectoryLister(const SafeDirectoryLister& other) = delete;
        SafeDirectoryLister(const SafeDirectoryLister&& other) noexcept = delete;
        SafeDirectoryLister operator=(const SafeDirectoryLister& other) = delete;
        SafeDirectoryLister(const std::string& path, bool hidden);
        ~SafeDirectoryLister();
        bool open(const std::string& path, bool hidden);
        std::string get(void);

    private:
        std::string _path = ".";
        bool _hidden;
        struct stat buf;
        DIR* _dir = nullptr;
};

#endif /* !SAFEDIRECTORYLISTER_HPP_ */
