/*
** EPITECH PROJECT, 2025
** ht_search
** File description:
** this search the val in the hashtable
*/

#include "hashtable.h"

char *ht_search_ext(content_t *linked_list, int hash_num)
{
    content_t *actuel;

    actuel = linked_list;
    while (actuel != NULL) {
        if (actuel->hash_num == hash_num)
            return actuel->val;
    actuel = actuel->next;
    }
    return NULL;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int id;
    int hash_num;
    char *val = NULL;

    if (ht == NULL || ht->len <= 0 || key == NULL)
        return NULL;
    id = ht->hash(key, ht->len) % ht->len;
    hash_num = ht->hash(key, ht->len);
    val = ht_search_ext(ht->head[id], hash_num);
    return val;
}
