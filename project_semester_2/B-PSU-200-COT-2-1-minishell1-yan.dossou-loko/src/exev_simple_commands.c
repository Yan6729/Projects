/*
** EPITECH PROJECT, 2025
** step4.c
** File description:
** just the step4 of the bootstrap
*/

#include "../include/mysh.h"

int style1(char **dir, char *path, char **tab, char **env)
{
    struct stat buffer;

    for (int i = 0; dir[i] != NULL; i++) {
        my_strcpy(path, dir[i]);
        my_strcat(path, "/");
        my_strcat(path, tab[0]);
        if (stat(path, &buffer) == 0 && (buffer.st_mode & S_IXUSR)) {
            execve(path, tab, env);
        }
    }
    my_puts_2(tab[0]);
    my_puts_2(": Command not found.");
    my_putchar_2('\n');
    return 1;
}

int style2(char **tab, char **env, char *path)
{
    if (tab[0][0] == '/' || tab[0][0] == '.') {
        my_strncpy(path, tab[0], sizeof(path));
        execve(path, tab, env);
        perror("execve");
        exit(EXIT_FAILURE);
    } else {
        execve(tab[0], tab, env);
    }
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
        perror("getenv PATH");
    }
    dir = strtowordarray(path1, ":");
    if (dir == NULL) {
        perror("str_to_word_array");
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
            my_puts_2(strsignal(WTERMSIG(status)));
            my_puts_2(" (core dumped) ");
            my_puts_2("\n");
            exit(EXIT_FAILURE);
        }
        my_puts_2(strsignal(WTERMSIG(status)));
        my_puts_2("\n");
        exit(EXIT_FAILURE);
    }
}

int get_pid(char **tab, char **env)
{
    int a = fork();
    int pid[2] = {0, 0};
    int status;

    if (a == -1)
        exit(84);
    if (a != 0) {
        pid[0] = getpid();
    } else
        (my_execve(tab, env) == 0);
    waitpid(pid[1], &status, 0);
    if (WIFEXITED(status)) {
    } else if (WIFSIGNALED(status)) {
        affiche(status, tab[0]);
    }
}
