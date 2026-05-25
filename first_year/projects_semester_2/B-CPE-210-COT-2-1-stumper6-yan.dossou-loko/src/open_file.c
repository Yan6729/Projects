/*
** EPITECH PROJECT, 2024
** parsing.c
** File description:
** an intermediar function
*/

#include "../include/stumper.h"

FILE *open_file(char *filename)
{
    FILE *file = NULL;
    long nb = 0;

    if (filename == NULL)
        exit(84);
    file = fopen(filename, "r");
    if (file == NULL) {
        dprintf(2, "Sorry \"%s\" doesn't exit\n", filename);
        exit(84);
    }
    fseek(file, 0, SEEK_END);
    nb = ftell(file);
    if (nb == 0) {
        fclose(file);
        dprintf(2, "Sorry \"%s\" is empty\n", filename);
        exit(84);
    }
    rewind(file);
    return file;
}

int is_space(char *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if (my_isalpha(str[a]) || str[a] == '_')
            continue;
        else {
            return 1;
        }
    }
    return 0;
}

dict_t *verify(char *buffer, dict_t *tmp)
{
    if (is_space(buffer) == 1)
        exit(84);
    tmp->word[tmp->count] = buffer;
    return tmp;
}

dict_t *recup(char *filename)
{
    FILE *file = open_file(filename);
    char *buf = malloc(sizeof(char) * 1001);
    size_t size = 1000;
    dict_t *cmp = malloc(sizeof(*cmp));

    cmp->count = 0;
    cmp->word = malloc(sizeof(char *) * 1001);
    while (getline(&buf, &size, file) != -1) {
        buf[strcspn(buf, "\n")] = '\0';
        verify(strdup(buf), cmp);
        cmp->count++;
    }
    cmp->word[cmp->count] = NULL;
    return cmp;
}
