/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#include <stdarg.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#ifndef MY_H
    #define MY_H

typedef struct {
    unsigned int us;
    unsigned int ni;
    unsigned int sys;
    unsigned int id;
    unsigned int wa;
    unsigned int hi;
    unsigned int si;
    unsigned int st;
} cpu_t;

char *lecture(char c, char *str, char const *filepath);
int procss_sts(char *str, char c);
int process(char const *filepath);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
double my_getnbr(char const *str);
char *open_file(char const *filepath, char *username);
char **my_str_to_word_array(char const *str);
char **spe_str_to_word_array(char const *str);
int check(char *s1, char *s2);
char *get_hash(char *username);
int get_passwd(void);
char *get_name(void);
int exec(char **av);
void my_free(char **str);
int user_command(char *username, char *command, char **args);
int grp_command(char *grpname, char *command, char **args);
int verify(void);
int verify_g(char *grp);
int do_command(char *command, char **args);
void style(char **av, char *str);
int verify_grp(void);
#endif
