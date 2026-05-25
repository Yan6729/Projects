/*
** EPITECH PROJECT, 2026
** string_main.c
** File description:
** main file
*/

#include "string.h"

void clear(string_t *this)
{
    this->string[0] = '\0';
}

void assign(string_t *this, const char *str)
{
    if (str == NULL) {
        return;
    }
    if (this->string != NULL) {
        free(this->string);
        this->string = my_strdup(str, 0);
        return;
    }
    this->string = my_strdup(str, 0);
}

void append(string_t *this, const char *str)
{
    char *tmp;
    char *new;
    int old = strlen(this->string);
    int add = strlen(str);

    if (str == NULL) {
        return;
    }
    if (!this->string || this->string[0] == '\0') {
        new = my_strdup(str, 0);
        if (!new)
            return;
        free(this->string);
        this->string = new;
    } else {
        tmp = realloc(this->string,
            sizeof(char) * (old + add + 1));
        this->string = tmp;
        memcpy(this->string + old, str, add + 1);
    }
}

void string_init(string_t *this, const char *s)
{
    if (s == NULL)
        return;
    this->string = my_strdup(s, 0);
    this->empty = &empty;
    this->length = &length;
    this->at = &the_char_at_the_position;
    this->print = &print;
    this->data = &data;
    this->clear = &clear;
    this->assign = &assign;
    this->append = &append;
}

void string_destroy(string_t *this)
{
    if (this != NULL) {
        free(this->string);
    }
}
