/*
** EPITECH PROJECT, 2025
** new_hashtable
** File description:
** this add new file
*/

#include "hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc(sizeof(ht));
    content_t **linked_tab = malloc(sizeof(content_t *) * len);

    if (hash == NULL || len <= 0) {
        return NULL;
    }
    ht->len = len;
    ht->hash = hash;
    for (int i = 0; i < len; i++) {
        linked_tab[i] = NULL;
    }
    ht->head = linked_tab;
    return ht;
}
