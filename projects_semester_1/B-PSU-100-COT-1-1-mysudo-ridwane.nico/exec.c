/*
** EPITECH PROJECT, 2025
** exec
** File description:
** exec
*/

#include "my.h"
int verify(void)
{
    char *str = NULL;
    size_t len = 0;
    char **line = NULL;
    char *username = get_name();
    char buffer[256];
    FILE *file = fopen("/etc/sudoers", "r");

    if (!file)
        return 84;
    snprintf(buffer, 256, "%s %s", username, "ALL=(ALL)ALL");
    while (getline(&str, &len, file) != -1) {
        if (strstr(str, buffer) != NULL) {
            return 1;
        }
    }
    return 0;
}

int verify_g(char *grp)
{
    char *str = NULL;
    size_t len = 0;
    char **line = NULL;
    char *username = get_name();
    char buffer[256];
    FILE *file = fopen("/etc/group", "r");

    if (!file)
        return 84;
    while (getline(&str, &len, file) != -1) {
        if (strncmp(str, grp, strlen(grp)) == 0 &&
            strstr(str, username) != NULL) {
            return 1;
        }
    }
    return 0;
}

int do_command(char *command, char **args)
{
    if (execvp(command, args) == -1)
        exit(84);
}

void style(char **av, char *str)
{
    if ((verify() == 1) || verify_grp() == 1) {
        do_command(av[1], &av[1]);
    } else {
        printf("%s is not in the sudoers file\n", str);
        exit(84);
    }
}

int exec(char **av)
{
    char *username = get_name();

    if (strcmp(username, "root") == 0) {
        do_command(av[1], &av[1]);
    } else {
        if (get_passwd() == 0) {
            style(av, username);
        }
    }
}
