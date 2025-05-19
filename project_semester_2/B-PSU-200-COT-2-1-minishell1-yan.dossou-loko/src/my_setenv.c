/*
** EPITECH PROJECT, 2025
** my_setenv.c
** File description:
** setenv, env...
*/

#include "../include/mysh.h"

env_t *add(env_t **head, char *name, char *value)
{
    env_t *last = *head;
    env_t *newNode = malloc(sizeof(env_t));

    if (!name)
        return NULL;
    newNode->name = my_strdup(name, 0);
    newNode->value = my_strdup(value, 0);
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
    return newNode;
}

void display(env_t *head)
{
    env_t *tmp = head;

    for (tmp; tmp != NULL; tmp = tmp->next) {
        if (tmp->value) {
            my_puts(tmp->name);
            my_putchar('=');
            my_puts(tmp->value);
            my_putchar('\n');
        } else {
            my_puts(tmp->name);
            my_putchar('\n');
        }
    }
}

env_t *copy_env(char **env)
{
    char *name;
    char *value;
    char *entry;
    env_t *head = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        entry = my_strdup(env[i], 0);
        if (!entry)
            continue;
        name = strtok(entry, "=");
        value = strtok(NULL, "");
        if (name && value && my_strcmp(name, "OLDPWD") != 0) {
            add(&head, name, value);
        }
        free(entry);
    }
    return head;
}

env_t *my_setenv(env_t *list, char *name, char *value)
{
    env_t *var = find_var(list, name);

    if (var != NULL && value) {
        free(var->value);
        var->value = my_strdup(value, 0);
    } else if (name && value) {
        add(&list, name, value);
    }
    if (!value)
        add(&list, name, NULL);
    return list;
}

env_t *find_var(env_t *list, char *name)
{
    while (list) {
        if (my_strcmp(list->name, name) == 0)
            return list;
        list = list->next;
    }
    return NULL;
}
