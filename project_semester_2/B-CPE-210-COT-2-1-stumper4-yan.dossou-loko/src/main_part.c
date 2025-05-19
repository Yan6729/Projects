/*
** EPITECH PROJECT, 2025
** emacs
** File description:
** emacs
*/

#include "../include/my.h"

void prog(ign_t *list, char *cmd, size_t size)
{
    while (1) {
        if (getline(&cmd, &size, stdin) == -1) {
            save(list);
            free(list);
            exit(0);
        }
        cmd[size - 1] = '\0';
        cmd = format_cmd(cmd);
        list = fridge(list, cmd);
        free(cmd);
        cmd = NULL;
    }
}

int main(int ac, char **av)
{
    char *cmd = NULL;
    size_t size = 0;
    ign_t *list = malloc(sizeof(ign_t) * 8);

    if (ac != 1) {
        free(list);
        return 84;
    }
    if (open(".save", O_RDONLY) == -1)
        create_file(".save");
    list = create_list(list);
    prog(list, cmd, size);
    return 0;
}
