/*
** EPITECH PROJECT, 2025
** delete_hash
** File description:
** this function delete the hashtable
*/

#include "hashtable.h"

content_t *delete_hashtable_ext(content_t *list)
{
    content_t *temp = NULL;

    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp->val);
        free(temp);
    }
    return list;
}

void delete_hashtable(hashtable_t *ht)
{
    if (ht == NULL)
        return;
    for (int i = 0; i < ht->len; i++) {
        ht->head[i] = delete_hashtable_ext(ht->head[i]);
        free(ht->head[i]);
    }
    free(ht->head);
    free(ht);
}
