/*
** EPITECH PROJECT, 2026
** list_main.c
** File description:
** main file
*/

#include "list.h"

lis_t *create_node(lis_t *lis, void *ptr)
{
    lis_t *newNode = malloc(sizeof(lis_t));

    if (!lis || ptr == NULL) {
        return NULL;
    }
    newNode->tail = NULL;
    newNode->ptr = ptr;
    newNode->head = NULL;
    lis = newNode;
    return newNode;
}

void push_front(list_t *this, void *value)
{
    lis_t *tmp = malloc(sizeof(lis_t));

    tmp->tail = NULL;
    tmp->ptr = value;
    tmp->head = NULL;
    tmp->head = this->list;
    this->list->tail = tmp;
    this->list = &tmp;
}

void push_back(list_t *this, void *value)
{
}

void list_init(list_t *this)
{
    this->list = create_node(this->list, NULL);
    this->get = &get;
    this->push_front = &push_front;
    this->push_back = &push_back;
    this->pop_front = &pop_front;
    this->pop_back = &pop_back;
    this->clear = &clear;
    this->apply = &apply;
    this->empty = &empty;
    this->set = &set;
    this->size = &size;
}

void list_destroy(list_t *this)
{
}
