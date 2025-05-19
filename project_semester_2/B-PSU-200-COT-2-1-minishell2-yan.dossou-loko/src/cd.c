/*
** EPITECH PROJECT, 2025
** change dir
** File description:
** cd.c
*/

#include "../include/mysh.h"

int check_directory(char *path)
{
    struct stat buffer;

    if (stat(path, &buffer) != 0) {
        my_puts(path, 2);
        my_puts(": No such file or directory.\n", 2);
        return 0;
    }
    if (!S_ISDIR(buffer.st_mode)) {
        my_puts(path, 2);
        my_puts(": Not a directory.\n", 2);
        return 0;
    }
    if (S_ISDIR(buffer.st_mode) && (!(buffer.st_mode & S_IRUSR)
        || !(buffer.st_mode & S_IXUSR) || (!buffer.st_mode & S_IRUSR) ||
        !(buffer.st_mode & S_IRUSR))) {
        my_puts(path, 2);
        my_puts(": Permission denied.\n", 2);
        return 0;
    }
    return 1;
}

char *special_cd(char *path, env_t *list)
{
    char *home;
    char *oldpwd;

    if (!path || my_strcmp(path, "~") == 0) {
        home = my_getenv_list(list, "HOME");
        return home;
    }
    if (my_strcmp(path, "-") == 0) {
        oldpwd = my_getenv_list(list, "OLDPWD");
        if (oldpwd == NULL) {
            my_puts(": No such file or directory.\n", 2);
            return NULL;
        }
        my_puts(oldpwd, 1);
        my_putchar('\n', 1);
        return oldpwd;
    }
    return path;
}

env_t *update_pwd(env_t *list, char *new_pwd, char *old_pwd)
{
    if (old_pwd == NULL) {
        my_puts("cd: OLDPWD not set\n", 1);
        exit(EXIT_FAILURE);
    }
    list = my_setenv(list, "OLDPWD", old_pwd);
    list = my_setenv(list, "PWD", new_pwd);
    return list;
}

env_t *change_directory(env_t *list, char *path, char **env)
{
    char old_pwd[1024];
    char new_pwd[1024];
    char *resolved_path;

    if (getcwd(old_pwd, 1024) == NULL)
        return list;
    resolved_path = special_cd(path, list);
    if (!resolved_path)
        return list;
    if (chdir(resolved_path) != 0) {
        check_directory(path);
        return list;
    }
    if (getcwd(new_pwd, 1024) == NULL)
        return list;
    list = update_pwd(list, new_pwd, old_pwd);
    return list;
}
