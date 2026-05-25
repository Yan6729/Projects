/*
** EPITECH PROJECT, 2025
** change dir
** File description:
** cd.c
*/

#include "../include/shell.h"

int check_directory(char *path)
{
    struct stat buffer;

    if (stat(path, &buffer) != 0) {
        print("stderr", "%s: No such file or directory.\n", path);
        return 1;
    }
    if (!S_ISDIR(buffer.st_mode)) {
        print("stderr", "%s: Not a directory.\n", path);
        return 1;
    }
    if (S_ISDIR(buffer.st_mode) && (!(buffer.st_mode & S_IRUSR)
        || !(buffer.st_mode & S_IXUSR) || (!buffer.st_mode & S_IRUSR) ||
        !(buffer.st_mode & S_IRUSR))) {
        print("stderr", "%s: Permission denied.\n", path);
        return 1;
    }
    return 0;
}

char *special_cd(char *path, env_t *list)
{
    char *home;
    char *oldpwd;

    if (!path || strcmp(path, "~") == 0) {
        home = my_getenv_list(list, "HOME");
        return home;
    }
    if (strcmp(path, "-") == 0) {
        oldpwd = my_getenv_list(list, "OLDPWD");
        if (oldpwd == NULL) {
            print("stderr", ": No such file or directory.\n");
            return NULL;
        }
        print("stdout", "%s\n", oldpwd);
        return oldpwd;
    }
    return path;
}

env_t *update_pwd(env_t *list, char *new_pwd, char *old_pwd)
{
    if (old_pwd == NULL) {
        print("stderr", "cd: OLDPWD not set\n");
        exit(EXIT_FAILURE);
    }
    list = my_setenv(list, "OLDPWD", old_pwd);
    list = my_setenv(list, "PWD", new_pwd);
    return list;
}

env_t *change_directory(shell_t *tmp, char *path, char **env)
{
    char old_pwd[1024];
    char new_pwd[1024];
    char *resolved_path;

    if (getcwd(old_pwd, 1024) == NULL)
        return tmp->list;
    resolved_path = special_cd(path, tmp->list);
    if (!resolved_path)
        return tmp->list;
    if (chdir(resolved_path) != 0) {
        tmp->status = check_directory(path);
        return tmp->list;
    }
    if (getcwd(new_pwd, 1024) == NULL)
        return tmp->list;
    tmp->list = update_pwd(tmp->list, new_pwd, old_pwd);
    return tmp->list;
}
