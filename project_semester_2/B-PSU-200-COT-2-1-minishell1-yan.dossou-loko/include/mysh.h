/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#ifndef MY_H
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
    #define MY_H

typedef struct index_s {
    int k;
    int i;
    int j;
    int lig;
}index_t;

typedef struct env_s {
    char *name;
    char *value;
    struct env_s *next;
} env_t;

int verify_setenv(char *name);
void free_line(char *line, char *buffer, char **content);
void is_builtins_cmd(char **tab, env_t **list, char **env);
char *my_getenv(char *name, char **env);
char *my_getenv_list(env_t *list, char *name);
void print_env(env_t *list);
env_t *find_var(env_t *list, char *name);
env_t *copy_env(char **env);
env_t *my_setenv(env_t *list, char *name, char *value);
env_t *add(env_t **head, char *name, char *value);
env_t *my_unsetenv(env_t *list, char *name);
int count_arg(char **str);
void error(int b, char *str);
env_t *change_directory(env_t *list, char *path, char **env);
int check_build_command(char **content);
void display(env_t *head);
void free_list(env_t *list);
void exit_status(char *str, char **env);
int style4(char **tab, char **env);
char *getline_shell(char *line, size_t len, ssize_t read);
char *stdin_rec(env_t **list);
void free_tab(char **tab);
int signal_handle(int status, pid_t pid);
int get_pid(char **tab, char **env);
char *my_strncpy(char *dest, char const *src, int size);
char *my_strcpy(char *dest, char const *src);
void print_dir(int ac, char **av, char **env);
int my_execve(char **tab, char **envp);
char *my_hostname(char *filepath);
char *my_strndup(char const *src, int lim, int size);
char **strtowordarray(char *str, const char *delim);
int change_dir(char *str, char **env);
char *my_strcat(char *dest, char const *src);
int loop_1(int ac, char **av, char **env);
int loop_2(int ac, char **av, char **env);
int loop_3(int ac, char **av, char **env);
int loop_4(int ac, char **av, char **env);
int my_cmpworld_2(char *str);
char *my_strdup(char const *src, int lim);
char *my_strstr(char *str, char *to_find);
int my_strlen(char const *str);
int my_strcmp(char *str1, char *str2);
int my_strncmp(char *str1, char *str2, size_t lim);
int my_put_nbr(int nbr);
void my_putchar(char c);
void my_putchar_2(char c);
void my_puts(char *str);
void my_puts_2(char *str);

#endif
