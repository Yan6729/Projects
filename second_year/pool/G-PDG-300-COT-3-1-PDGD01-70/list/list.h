/*
** EPITECH PROJECT, 2026
** list.h
** File description:
** contain prototypes, structures and librairies recall
*/

#ifndef LIST_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdbool.h>
    #define LIST_H

typedef struct lis {
    void *ptr;
    struct lis *head;
    struct lis *tail;
} lis_t;

typedef struct list_s {
    lis_t *list;

    void (*get)(const struct list_s *, size_t);
    void (*push_front)(struct list_s *, void *);
    void (*push_back)(struct list_s *, void *);
    void (*pop_front)(struct list_s *);
    void (*pop_back)(struct list_s *);
    void (*clear)(struct list_s *);
    void (*apply)(struct list_s *, void *(*)(void *));
    bool (*empty)(const struct list_s *);
    bool (*set)(struct list_s *, size_t, void *);
    size_t (*size)(const struct list_s *);

} list_t;

lis_t *create_node(lis_t *lis, void *ptr);
void list_init(list_t *this);
void list_destroy(list_t *this);
void *get(const list_t *this, size_t position);
void push_front(list_t *this, void *value);
void push_back(list_t *this, void *value);
void pop_front(list_t *this);
void pop_back(list_t *this);
void clear(list_t *this);
void apply(list_t *this, void *(*function)(void *));
bool empty(const list_t *this);
bool set(list_t *this, size_t position, void *value);
size_t size(const list_t *this);


#endif
