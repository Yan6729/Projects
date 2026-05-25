/*
** EPITECH PROJECT, 2025
** step4.c
** File description:
** just the step4 of the bootstrap
*/

#include "../include/shell.h"

int style1(char **dir, char *path, char **tab, char **env)
{
    int a = 0;
    struct stat buffer;

    for (int i = 0; dir[i] != NULL; i++) {
        strcpy(path, dir[i]);
        strcat(path, "/");
        strcat(path, tab[0]);
        if (stat(path, &buffer) == 0 && (buffer.st_mode & S_IXUSR)) {
            execve(path, tab, env);
        }
    }
    if (strcmp("exit", tab[0]) != 0) {
        print("stderr", "%s: Command not found.\n", tab[0]);
    }
    exit(EXIT_FAILURE);
}

int style2(char **tab, char **env, char *path)
{
    struct stat buffer;

    path = strdup(tab[0]);
    if (stat(path, &buffer) != 0)
        return 1;
    if (handle_shebang(path, tab))
        return 0;
    handle_text_or_elf(path, tab, env);
    return 0;
}

int my_execve(char **tab, char **env)
{
    char *path1 = NULL;
    char path[256];
    char **dir;
    int a = 0;

    path1 = my_getenv("PATH", env);
    if (!path1) {
        path1 = ("/usr/bin");
    }
    dir = strtowordarray(path1, ":");
    if (dir == NULL) {
        perror("strtowordarray");
    }
    style2(tab, env, path);
    a = style1(dir, path, tab, env);
    return a;
}

void affiche(int status, char *path)
{
    struct stat buffer;

    if (stat(path, &buffer) == 0 && (buffer.st_mode & S_IXUSR)) {
        if (status == 139) {
            print("stderr", strsignal(WTERMSIG(status)));
            print("stderr", " (core dumped)\n");
            exit(EXIT_FAILURE);
        }
        print("stderr", strsignal(WTERMSIG(status)));
        print("stderr", "\n");
        exit(EXIT_FAILURE);
    }
}

int get_pid(char **tab, char **env)
{
    int a = fork();
    int pid[2] = {0, 0};
    int status;
    int b = 0;

    if (a == -1)
        exit(84);
    if (a != 0) {
        pid[0] = getpid();
    } else {
        (my_execve(tab, env) == 0);
    }
    waitpid(pid[1], &status, 0);
    if (WIFEXITED(status)) {
    } else if (WIFSIGNALED(status)) {
        affiche(status, tab[0]);
    }
    return status;
}
