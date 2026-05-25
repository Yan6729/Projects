/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** IDirectoryLister
*/

#ifndef IDIRECTORYLISTER_HPP_
    #include <string>
    #include <list>
    #include <iostream>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <errno.h>
    #include <cstring>
    #include <type_traits>
#define IDIRECTORYLISTER_HPP_

class IDirectoryLister {
    public:
        virtual ~IDirectoryLister() = default;
        virtual bool open(const std::string& path, bool hidden) = 0;
        virtual std::string get(void) = 0;

        class OpenFailureException : public std::exception {
            public:
                virtual const char *what() const noexcept override;
            private:
        };

        class NoMoreFileException : public std::exception {
            public:
                virtual const char *what() const noexcept override;  
            private:
        };
    protected:
    private:
};

#endif /* !IDIRECTORYLISTER_HPP_ */
