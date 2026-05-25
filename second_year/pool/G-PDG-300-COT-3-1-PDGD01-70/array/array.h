/*
** EPITECH PROJECT, 2026
** array.h
** File description:
** contain prototypes, structures and library calling
*/

#ifndef ARRAY_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdbool.h>
    #define ARRAY_H

typedef struct array_s {
    void **arr;
    size_t len;

    void (*resize)(struct array_s *, size_t);
    void *(*get)(const struct array_s *, size_t);
    void (*apply)(struct array_s *, void *(*)(void *));
    bool (*set)(struct array_s *, size_t, void *);
    bool (*empty)(const struct array_s *);
    size_t (*size)(const struct array_s *);
} array_t;

void array_init(array_t *this, size_t size);
void array_destroy(array_t *this);
void resize(array_t *this, size_t size);
void *get(const array_t *this, size_t index);
void apply(array_t *this, void *(*function)(void *));
void **allocate_memory(size_t size);
bool set(array_t *this, size_t index, void *value);
bool empty(const array_t *this);
size_t size_function(const array_t *this);
char *my_strdup(char const *src, int lim);
char *my_strndup(char const *src, int lim, int size);
char *my_strcat(char *dest, char const *src);
int my_strlen(char *str, int start);

#endif
