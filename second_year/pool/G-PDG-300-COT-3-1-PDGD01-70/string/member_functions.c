/*
** EPITECH PROJECT, 2026
** member_functions.c
** File description:
** contain five members functions
*/

#include "string.h"

bool empty(const string_t *this)
{
    int a = my_strlen(this->string, 0);

    if (a == 0) {
        return true;
    } else {
        return false;
    }
}

size_t length(const string_t *this)
{
    return my_strlen(this->string, 0);
}

char the_char_at_the_position(const string_t *this, size_t pos)
{
    if (pos < 0 || pos >= (size_t)my_strlen(this->string, 0))
        return -1;
    else
        return this->string[pos];
}

void print(const string_t *this)
{
    write(1, this->string, my_strlen(this->string, 0));
}

const char *data(const string_t *this)
{
    return this->string;
}
