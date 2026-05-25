/*
** EPITECH PROJECT, 2026
** member_functions.c
** File description:
** contain five members functions
*/

#include "array.h"

void *get(const array_t *this, size_t index)
{
    if (index < 0 || index >= this->len) {
        return NULL;
    }
    return this->arr[index];
}

void apply(array_t *this, void *(*function)(void *))
{
    for (int a = 0; a < this->len; a++) {
        this->arr[a] = function(this->arr[a]);
    }
}

bool set(array_t *this, size_t index, void *value)
{
    if (index < 0 || index >= this->len || !this->arr) {
        return false;
    } else {
        this->arr[index] = value;
        return true;
    }
}

void resize(array_t *this, size_t size)
{
    void **newTable = NULL;

    if (size < 0)
        return;
    if (size == 0) {
        free(this->arr);
        this->arr = NULL;
        this->len = 0;
        return;
    }
    newTable = realloc(this->arr, sizeof(void *) * size);
    if (size > this->len) {
        for (int a = this->len; a < size; a++) {
            newTable[a] = NULL;
        }
    }
    this->len = size;
    this->arr = newTable;
}

bool empty(const array_t *this)
{
    int a = this->len;

    if (a == 0) {
        return true;
    } else {
        return false;
    }
}
