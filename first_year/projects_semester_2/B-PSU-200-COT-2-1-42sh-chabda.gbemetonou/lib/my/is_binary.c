/*
** EPITECH PROJECT, 2025
** is_binary.c
** File description:
** just a file
*/

#include "../../include/shell.h"

int count_suspect_bytes(const unsigned char *buf, size_t len)
{
    int count = 0;

    for (size_t i = 0; i < len; ++i)
        if ((buf[i] < 32 && buf[i] != 9 && buf[i] != 10
            && buf[i] != 13) || buf[i] == 127)
            count++;
    return count;
}

int is_binary(int total, int suspect)
{
    return total > 0 && (suspect * 100 / total > 1);
}

int is_text(const char *f)
{
    FILE *fp = fopen(f, "r");
    unsigned char buf[4096];
    size_t nb_read = 0;
    size_t total = 0;
    size_t suspect = 0;

    nb_read = fread(buf, 1, sizeof(buf), fp);
    while (nb_read > 0) {
        suspect += count_suspect_bytes(buf, nb_read);
        total += nb_read;
        nb_read = fread(buf, 1, sizeof(buf), fp);
    }
    fclose(fp);
    if (total > 0 && (suspect * 100 / total) > 1)
        return 1;
    else
        return 0;
}
