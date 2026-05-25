/*
** EPITECH PROJECT, 2025
** shell.h
** File description:
** shell.h
*/

#ifndef SHELL_H
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <limits.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <glob.h>
    #include <termios.h>
    #include <pwd.h>
    #include <ctype.h>
    #define SHELL_H
    #define MAX_CMD 1000
    #define MAX_LINE_SIZE 1024

typedef struct globbing_s {
    glob_t globbuf;
    int flags;
    char **mapcmd2;
    char **mapcmd;
    int f;
    int d;
    int h;
    int state;
    pid_t pid;
    int y;
} globbing_t;

typedef struct tab_s {
    char *string;
    int is_sep;
    struct tab_s *next;
} tab_t;

typedef struct ind_s {
    tab_t *list;
    int i;
    int start;
    int len;
    int is_sep;
    char quote;
} ind_t;

typedef struct index_s {
    int k;
    int i;
    int j;
    int lig;
}index_t;

typedef struct split_s {
    index_t sep;
    char **tab;
    int is_sep;
} split_t;

typedef struct env_s {
    char *name;
    char *value;
    struct env_s *next;
} env_t;

extern const env_t *data;

typedef struct val_s {
    char *command;
    int num;
} val_t;

typedef struct history_s {
    val_t *cmp;
    struct history_s *next;
    struct history_s *prev;
} history_t;

typedef struct d_hist_s {
    int lenght;
    history_t *first;
    history_t *last;
}*d_hist_t;

typedef struct hist_s {
    history_t *hist;
    int count;
} hist_t;

typedef struct left_s {
    char *line;
    struct left_s *next;
} left_t;

typedef struct alias_s {
    char *alias;
    char *value;
    char *illusion;
    struct alias_s *next;
} alias_t;

typedef struct shell_s {
    int num;
    int status;
    int a;
    char *buffer;
    char *clone;
    char **tab;
    char **env;
    env_t *list;
    hist_t *cmp;
    alias_t *al;
} shell_t;

typedef struct dec_s {
    char *line;
    int ret;
} dec_t;

typedef struct editor_s {
    char *line;
    int cursor_pos;
    int line_len;
    char **history;
    history_t *current_history;
    hist_t *history_data;
    //    int *history_count;
    //int *history_index;
    struct termios orig_termios;
} editor_t;

editor_t *init_line_editor(hist_t *history);
globbing_t complete_mapcmd(shell_t *tmp, char *cmd);
globbing_t stock_var(char *cmd);
tab_t *create_new(char *string, int is_sep, int len);
tab_t *str_to_list(char *str, const char *delim);
alias_t *add_alias(char **tab_2, alias_t *list);
alias_t *unalias(shell_t *list, char *name);
left_t *add_2(left_t **head, char *line);
shell_t *rempli_struct(int ac, char **av, char **env);
hist_t *copie_file(char *filename, int nb);
history_t *verify_h(history_t *list, char *line, int num);
history_t *add_history(history_t **list, char *command);
history_t *find_var_h(history_t *list, char *line);
env_t *find_var(env_t *list, char *name);
env_t *copy_env(char **env);
env_t *my_setenv(env_t *list, char *name, char *value);
env_t *add(env_t **head, char *name, char *value);
env_t *my_unsetenv(env_t **list, char *name);
env_t *change_directory(shell_t *tmp, char *path, char **env);
char *my_getenv(char *name, char **env);
char *my_getenv_list(env_t *list, char *name);
char *getline_shell(char *line, size_t len, ssize_t read);
char *stdin_rec(shell_t *tmp, char *filename);
char *my_hostname(char *filepath);
char *my_strndup(char const *src, int lim, int size);
char *my_strdup(char const *src, int lim);
char *open_file(char *file);
char *file_histor(char *filename, char **env);
char *strcat(char *dest, char const *src);
char *cleanstr(char *input, int choice);
char *putslashzero(char *str);
char *doublecote(char *str);
char *concatenate(char **tab, int ind);
char *get_home_directory(void);
char *verify_value_of_alias(alias_t **list, char *value);
char *backtick(char *filename, char *line, shell_t *tmp);
char **my_strtok(char *str, char *separator);
char **strtowordarray(char *str, const char *delim);
char **my_split(char *str, const char *delim);
char **verify_alias(shell_t *tmp, char **tab);
char **trans_cmd(char *str, char **tab_2, int nb);
void exclamation_point(shell_t *tmp, char *lines);
void write_list(char *filename, history_t *hist);
void recup_func(shell_t *tmp, char **env, char *lines);
void recup_func_2(char *lines, shell_t *tmp, char **env);
void recup_func_3(char *lines, shell_t *tmp, char **env);
void display(env_t *head);
void write_bash(char *filename, char **env);
void disp_b(alias_t **hist);
void add_b(alias_t **list, char *line, char *value, char *real);
void add_bash(alias_t **list, char *line, char *value, char *real);
void create_file(char **str, int start, int end);
void handle_signal(int sig);
void handle_signal_2(int sig);
void handle_signal_3(int sig);
void is_history(char **tab, char **tab_2, shell_t *hist, char **env);
void add_h(history_t **list, char *line, int num);
void disp_h(history_t **list);
void complete_pathv(globbing_t cmp);
void globbings(shell_t *tmp, char *cmd);
void display_2(left_t *head);
void is_alias(char **tab, shell_t *tmp, char **env);
void free_list(env_t *list);
void exit_status(char *str, char **env);
void puts_env(env_t *list);
void free_line(char *line, char *buffer, char **content, char **tab);
void is_builtins_cmd(shell_t *tmp, char **tab, char **tab_2, char **env);
void my_putchar(char c, int fd);
void my_puts(char *str, int fd);
void decoup(shell_t *tmp, left_t *list, char **env, char **red[2]);
void close_fd(int *fd, int b);
void print_dir(env_t *list);
void error(int b, char *str);
void free_litb(tab_t *list);
void free_al(alias_t *al);
void free_hl(history_t *cmp);
void separation_bash(alias_t **al, char *filename, char **env);
void decoup_tab(ind_t *cmp, char *str, const char *delim);
void add_tab(tab_t **list, tab_t *new_node);
void init_history(hist_t *history);
void free_history(hist_t *history);
void refresh_line(editor_t *editor);
void free_editor(editor_t *editor);
void reset_history_navigation(editor_t *editor);
void enable_raw_mode(void);
void disable_raw_mode(void);
void char_insertion(editor_t *editor, char c);
void delete_char(editor_t *editor);
void backspace_char(editor_t *editor);
void repeat(shell_t *tmp, char **tab);
void is_repeat(shell_t *tmp, char **tab);
void boucle_fun(shell_t *tmp);
void change_alias(shell_t *tmp);
void usage(void);
void my_parentheseis(shell_t *tmp, char **env);
void execute_with_envronment(char *lines, shell_t *tmp);
int handle_text_or_elf(char *path, char **tab, char **env);
int verifiparatheseis(char *str);
int is_text(const char *filename);
int verify_setenv(char *name);
int count_arg(char **str, int e);
int check_build_command(char **content, history_t **hist);
int error_exec(char *path);
int print(char *std, const char *format, ...);
int right_simple_redirection(shell_t *tmp, char *line, char **env);
int right_double_redirection(shell_t *tmp, char *line, char **env);
int left_simple_redirection(shell_t *tmp, char *line, char **env);
int left_double_redirection(shell_t *tmp, char *line, char **env);
int left_redirection(shell_t *tmp, char *cmd, char **env, char *filename);
int e_w_pipe(shell_t *tmp, char *line, char **env);
int advenced_error(char *line, char c);
int simple_error(char *line, char c);
int pipe_error(char *line, char c);
int simple_l_error(char *line, char c, int fd);
int loop_1(int ac, char **av, char **env);
int loop_2(int ac, char **av, char **env);
int loop_3(int ac, char **av, char **env);
int loop_4(int ac, char **av, char **env);
int my_cmpworld_2(char *str);
int my_put_nbr(int nbr, int fd);
int change_dir(char *str, char **env);
int my_execve(char **tab, char **envp);
int signal_handle(int status, pid_t pid);
int get_pid(char **tab, char **env);
int style4(char **tab, char **env);
int is_delim(char c, const char *delim);
int size_lis(tab_t **list);
int my_inibitor(shell_t *tmp, char *str, char **env);
int count_line(char *cmd);
int process_keypress(editor_t *editor);
int up_down(editor_t *editor, int key);
int read_key(void);
int and_function(shell_t *tmp, char *line, char **env);
int or_function(shell_t *tmp, char *line, char **env);
int verify_illusion(alias_t **list, char *alias);
int verify_alias_2(alias_t **list, char *illusion);
int verifie(shell_t *tmp, char *lines);
int handle_shebang(char *path, char **tab);
int arr_size(char **tab);
int check_job_control(char **tab);
int process_keypress(editor_t *editor);
void char_insertion(editor_t *editor, char c);
void backspace_char(editor_t *editor);
int key_press_interpretor(int c, editor_t *editor);

#endif
