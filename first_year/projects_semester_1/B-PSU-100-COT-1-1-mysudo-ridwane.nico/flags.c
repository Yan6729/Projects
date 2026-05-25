/*
** EPITECH PROJECT, 2025
** flags
** File description:
** flags
*/

#include "my.h"
int get_uid(char *username)
{
    char *uid = NULL;
    char *str = NULL;
    size_t len = 0;
    char **line = NULL;
    FILE *file = fopen("/etc/passwd", "r");

    if (!file)
        return -1;
    while (getline(&str, &len, file) != -1) {
        if (strstr(str, username) != NULL) {
            line = spe_str_to_word_array(str);
            uid = line[2];
            return atoi(uid);
        }
    }
    return -1;
}

int get_gid(char *grpname)
{
    char *gid = NULL;
    char *str = NULL;
    size_t len = 0;
    char **line = NULL;
    FILE *file = fopen("/etc/group", "r");

    if (!file)
        return -1;
    while (getline(&str, &len, file) != -1) {
        if (strstr(str, grpname) != NULL) {
            line = spe_str_to_word_array(str);
            gid = line[2];
            return atoi(gid);
        }
    }
    return -1;
}

int user_command(char *username, char *command, char **args)
{
    int uid = get_uid(username);

    if (setuid(uid) == -1)
        exit(84);
    if (execvp(command, args) == -1)
        exit(84);
}

int grp_command(char *grpname, char *command, char **args)
{
    int gid = get_gid(grpname);

    if (setgid(27) == -1)
        exit(84);
    if (execvp(command, args) == -1)
        exit(84);
}
