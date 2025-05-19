/*
** EPITECH PROJECT, 2025
** print_dir.c
** File description:
** just a file
*/

#include "../../include/mysh.h"


void inter1(char *str1, char *str3, char *str)
{
    my_puts("\033[1;91m", 1);
    my_puts("♠(", 1);
    my_puts("\033[3;96m", 1);
    my_puts(str1, 1);
    my_puts(" 🐾 ", 1);
    my_puts(str3, 1);
    my_puts("\033[1;91m", 1);
    my_puts(")[", 1);
    my_puts("\033[1;37m", 1);
    my_puts(str, 1);
    my_puts("\033[1;37m", 1);
    my_puts("\033[1;91m", 1);
    my_puts("]\n: ̗̀➛ ", 1);
    my_puts("\033[0;37m", 1);
}

void print_dir(env_t *list)
{
    char *str5;
    char src[UCHAR_MAX];
    char *str;
    char *str1 = my_getenv_list(list, "USERNAME");
    char *str2 = my_hostname("/etc/hostname");
    int a = my_strlen(str2);
    char *str3 = my_strndup(str2, 0, (a - 1));

    if (str1 == NULL) {
        str1 = my_strdup("user", 0);
        str3 = my_strdup("laptop", 0);
    }
    if (isatty(0)) {
        str = getcwd(src, UCHAR_MAX);
        if (str == NULL)
            exit(84);
        inter1(str1, str3, str);
    }
    free(str2);
    free(str3);
}

void handle_signal(int sig)
{
    my_puts("\n", 1);
    print_dir((env_t *)data);
}

void handle_signal_2(int sig)
{
    my_puts("\n", 1);
    my_puts("> ", 1);
}

void handle_signal_3(int sig)
{
    my_puts("\n", 1);
}
