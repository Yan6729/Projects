/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** IDirectoryLister
*/

#include "IDirectoryLister.hpp"

const char* IDirectoryLister::OpenFailureException::what() const noexcept
{
    return strerror(errno);
}


const char* IDirectoryLister::NoMoreFileException::what() const noexcept
{
    return "End of stream";
}
