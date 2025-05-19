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
    #define MAX_CMD 1000

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

extern const env_t *data;

typedef struct history_s {
    char *command;
    struct history_s *next;
} history_t;

typedef struct left_s {
    char *line;
    struct left_s *next;
} left_t;

void display_2(left_t *head);
left_t *add_2(left_t **head, char *line);
int e_w_pipe(char *line, char **env);
void create_file(char **str, int start, int end);
void handle_signal(int sig);
void handle_signal_2(int sig);
void handle_signal_3(int sig);
int advenced_error(char *line, char c);
int simple_error(char *line, char c);
int pipe_error(char *line, char c);
int simple_l_error(char *line, char c, int fd);
char *cleanstr(char *input);
int error_exec(char *path);
void recup_func(char **tab, char **content, env_t *list, char **env);
history_t *add_history(history_t **list, char *command);
int verify_setenv(char *name);
void free_line(char *line, char *buffer, char **content, char **tab);
void is_builtins_cmd(char **tab, env_t **list, char **env, char *line);
char *my_getenv(char *name, char **env);
char *my_getenv_list(env_t *list, char *name);
void print_env(env_t *list);
env_t *find_var(env_t *list, char *name);
env_t *copy_env(char **env);
env_t *my_setenv(env_t *list, char *name, char *value);
env_t *add(env_t **head, char *name, char *value);
env_t *my_unsetenv(env_t *list, char *name);
int count_arg(char **str, int e);
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
void print_dir(env_t *list);
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
void my_putchar(char c, int fd);
void my_puts(char *str, int fd);
int right_simple_redirection(char *line, char **env);
int right_double_redirection(char *line, char **env);
int left_simple_redirection(char *line, char **env);
int left_double_redirection(char *line, char **env);
int left_redirection(char *cmd, char **env, char *filename);
void decoup(int fd[2], left_t *list, char **env, char **red[2]);
void close_fd(int *fd, int b);

#endif
