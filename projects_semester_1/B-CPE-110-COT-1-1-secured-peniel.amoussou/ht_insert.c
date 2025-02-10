/*
** EPITECH PROJECT, 2025
** ht_insert
** File description:
** this functin insert in the ht
*/

#include "hashtable.h"

content_t *add_to_list(content_t *lista, int hash_num, char *value)
{
    content_t *nouveau = malloc(sizeof(*nouveau));

    nouveau->hash_num = hash_num;
    nouveau->val = my_strdup(value);
    nouveau->next = lista;
    lista = nouveau;
}

int error(hashtable_t *ht, char *key, char *value)
{
    if (ht == NULL)
    return 84;
    if (ht->len <= 0)
    return 84;
    if (key == NULL)
    return 84;
    if (value == NULL)
    return 84;
}

int ht_insert_ext(hashtable_t *ht, int updated, char *value, char *key)
{
    content_t *update;
    int id;

    id = ht->hash(key, ht->len) % ht->len;
    update = ht->head[id];
    while (update != NULL) {
        if (ht->hash(key, ht->len) == update->hash_num) {
            free(update->val);
            update->val = my_strdup(value);
            updated++;
        }
        ht->head[id] = update;
        update = update->next;
    }
    return updated;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int updated = 0;
    int id;

    if (error(ht, key, value) == 84)
        return 84;
    id = ht->hash(key, ht->len) % ht->len;
    updated = ht_insert_ext(ht, updated, value, key);
    if (updated > 0)
    return 0;
    ht->head[id] = add_to_list(ht->head[id], ht->hash(key, ht->len), value);
}
