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

    if (!(buffer.st_mode & S_IFDIR)) {
        my_puts_2(path);
        my_puts_2(": Not a directory.\n");
        return 0;
    }
    if (buffer.st_mode & S_IFDIR && (!(buffer.st_mode & S_IRUSR)
        || !(buffer.st_mode & S_IXUSR))) {
        my_puts_2(path);
        my_puts_2(": Permission denied.\n");
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
        my_puts(oldpwd);
        my_putchar('\n');
        return oldpwd;
    }
    return path;
}

env_t *update_pwd(env_t *list, char *new_pwd, char *old_pwd)
{
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
        my_puts_2(path);
        my_puts_2(": No such file or directory.\n");
        return list;
    }
    if (getcwd(new_pwd, 1024) == NULL)
        return list;
    list = update_pwd(list, new_pwd, old_pwd);
    return list;
}
