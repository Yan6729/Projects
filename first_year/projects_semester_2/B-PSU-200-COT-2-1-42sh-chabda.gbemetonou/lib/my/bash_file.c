/*
** EPITECH PROJECT, 2024
** Elementary
** File description:
** Map from file.
*/

#include "../../include/shell.h"

void create_bash(char *filename)
{
    int fd = 0;

    fd = open(filename, O_CREAT | O_RDWR, 0664);
    close(fd);
    return;
}

void write_bash(char *filename, char **env)
{
    FILE *file;
    char *str;

    if (filename == NULL)
        exit(84);
    str = file_histor(filename, env);
    create_bash(str);
    file = fopen(str, "wr+");
    fprintf(file, "alias ls 'ls --color=auto'\n");
    fprintf(file, "alias dir 'dir --color=auto'\n");
    fprintf(file, "alias vdir 'vdir --color=auto'\n");
    fprintf(file, "alias grep 'grep --color=auto'\n");
    fprintf(file, "alias fgrep 'fgrep --color=auto'\n");
    fprintf(file, "alias egrep 'egrep --color=auto'\n");
    fprintf(file, "alias tree 'tree -C'\n");
    fclose(file);
    return;
}

void disp_b(alias_t **hist)
{
    alias_t *list;

    for (list = *hist; list != NULL; list = list->next) {
        print("stdout", "%s\t%s\n", list->alias, list->illusion);
    }
}

void add_bash(alias_t **list, char *alias, char *value, char *real)
{
    alias_t *last = *list;
    alias_t *newNode = malloc(sizeof(alias_t));

    if (!alias)
        return;
    newNode->alias = my_strdup(alias, 0);
    newNode->value = my_strdup(value, 0);
    newNode->illusion = my_strdup(real, 0);
    newNode->next = NULL;
    if (*list == NULL) {
        *list = newNode;
    } else {
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

void separation_bash(alias_t **al, char *filename, char **env)
{
    char *buf = NULL;
    char *str = NULL;
    char **sep = NULL;
    char **line = NULL;

    if (filename == NULL)
        exit(84);
    str = file_histor(filename, env);
    buf = open_file(str);
    sep = strtowordarray(buf, "\n");
    for (int a = 0; sep[a] != NULL; a++) {
        line = my_split(sep[a], " \t");
        add_bash(al, line[1], line[2], line[2]);
    }
    free_line(str, buf, sep, line);
}
