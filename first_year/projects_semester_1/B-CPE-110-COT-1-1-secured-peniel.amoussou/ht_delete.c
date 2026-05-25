/*
** EPITECH PROJECT, 2025
** ht_delete
** File description:
** delete the selected element
*/

#include "hashtable.h"

void del(content_t *current, content_t *prev, int id, hashtable_t *ht)
{
    if (prev == NULL) {
        ht->head[id] = current->next;
    } else {
        prev->next = current->next;
    }
}

int ht_delete(hashtable_t *ht, char *key)
{
    int id;
    content_t *current;
    content_t *prev = NULL;
    int hash_num;

    if (ht == NULL || key == NULL)
        return 84;
    id = ht->hash(key, ht->len) % ht->len;
    current = ht->head[id];
    hash_num = ht->hash(key, ht->len);
    while (current != NULL) {
        if (current->hash_num == hash_num) {
            del(current, prev, id, ht);
            free(current->val);
            free(current);
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}
