/*
** EPITECH PROJECT, 2026
** array_main.c
** File description:
** main file
*/

#include "array.h"

size_t size_function(const array_t *this)
{
    return this->len;
}

void array_init(array_t *this, size_t size)
{
    this->apply = &apply;
    this->empty = &empty;
    this->get = &get;
    this->resize = &resize;
    this->set = &set;
    this->size = &size_function;
    this->len = size;
    this->arr = malloc(sizeof(void *) * (size + 1));
    if (!this->arr) {
        return;
    }
    for (int b = 0; b < size; b++) {
        this->arr[b] = NULL;
    }
}

void array_destroy(array_t *this)
{
    if (!this->arr)
        return;
    free(this->arr);
    this = NULL;
}
