/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#ifndef ROBOT_H
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <limits.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdio.h>
    #include "../B-CPE-200_op/op.h"
    #define ROBOT_H

typedef struct index_s {
    int k;
    int i;
    int j;
    int lig;
}index_t;

int recup(char *str);
void transcrip(char *filename);
header_t *header_transcript(char *filename);
char *parsing(char const *filepath);
char *clean(char *str);
void exit_status(char *str, char **env);
int style4(char **tab, char **env);
char *getline_shell(char *line, size_t len, ssize_t read);
char *stdin_rec(void);
void free_tab(char **tab);
int signal_handle(int status, pid_t pid);
int get_pid(char **tab, char **env);
char *my_strncpy(char *dest, char const *src, int size);
char *my_strcpy(char *dest, char const *src);
void print_dir(int ac, char **av, char **env);
int my_execve(char **tab, char **envp);
char *my_hostname(char *filepath);
char *my_strndup(char const *src, int lim, int size);
char *my_getenv(char *name, char **env);
char **my_split(char *str, const char *delim);
int change_dir(char *str, char **env);
char *my_strcat(char *dest, char const *src);
char *stdin_rec(void);
int loop_1(int ac, char **av, char **env);
int loop_2(int ac, char **av, char **env);
int loop_3(int ac, char **av, char **env);
int loop_4(int ac, char **av, char **env);
int my_cmpworld_2(char *str);
char *my_strdup(char const *src, int lim);
char *my_strstr(char *str, char *to_find);
void print_env(char *str, char **env);
int my_strlen(char const *str);
int my_strcmp(char *str1, char *str2);
int my_strncmp(char *str1, char *str2, size_t lim);
int my_put_nbr(int nbr);
void my_putchar(char c);
void my_putchar_2(char c);
void my_puts(char *str);
void my_puts_2(char *str);
int check_file(char *filename);
char *check_name(char *str, char **tab);
int check(char *filename, char **tab);
int errors_ca(char **tab);

#endif
