/*
** EPITECH PROJECT, 2025
** hash_function
** File description:
** this is a hash_function
*/

#include "hashtable.h"

int hash_ext(char *key, int hash, int len)
{
    for (int i = 0; key[i] != '\0'; i++) {
        if (key[i - 1] >= key[i])
            hash += (32 + len) - key[i];
        if (key[i - 1] <= key[i])
            hash -= (32 - len) + key[i];
    }
    return hash;
}

int hash(char *key, int len)
{
    int hash = 6898;

    if (len <= 0 || key == NULL)
    return 84;
    hash = hash_ext(key, hash, len);
    if (hash < 0)
    hash *= -1;
    hash = hash % (999999 - 100000 + 1) + 123456;
        hash *= 9;
    return hash;
}
