/*
** EPITECH PROJECT, 2025
** ht_dump
** File description:
** this function displays the ht
*/

#include "hashtable.h"

int afficherliste(content_t *list)
{
    while (list != NULL) {
        if (list->val != NULL) {
            my_putstr("> ");
            my_put_nbr(list->hash_num);
            my_putstr(" - ");
            my_putstr(list->val);
            my_putchar('\n');
        }
        list = list->next;
    }
    return 0;
}

void ht_dump(hashtable_t *ht)
{
    if (ht == NULL || ht->head == NULL || ht->len <= 0)
        return;
    for (int i = 0; i < ht->len; i++) {
        my_putchar('[');
        my_put_nbr(i);
        my_putstr("]:\n");
        if (ht->head[i] != NULL)
            afficherliste(ht->head[i]);
    }
}
