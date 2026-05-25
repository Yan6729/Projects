/*
** EPITECH PROJECT, 2025
** print_dir.c
** File description:
** just a file
*/

#include "../../include/shell.h"


void inter1(char *str1, char *str3, char *str, char *home)
{
    print("stdout", "\033[1;91m");
    print("stdout", "♠(", 1);
    print("stdout", "\033[3;96m");
    print("stdout", "%s 🐾 %s", str1, str3);
    print("stdout", "\033[1;91m");
    print("stdout", ")[");
    strstr(str, home) ? ({
        print("stdout", "\033[1;37m~");
        print("stdout", my_strdup(str, strlen(home)));
    }) : ({
        print("stdout", "\033[1;37m");
        print("stdout", str);
    });
    print("stdout", "\033[1;91m");
    print("stdout", "]\n: ̗̀➛ ");
    print("stdout", "\033[0;37m");
}

void print_dir(env_t *list)
{
    char *str5;
    char src[UCHAR_MAX];
    char *str;
    char *str1 = my_getenv_list(list, "USERNAME");
    char *str2 = my_hostname("/etc/hostname");
    char *str3 = my_strndup(str2, 0, (strlen(str2) - 1));
    char *home = my_getenv_list(list, "HOME");

    if (str1 == NULL) {
        str1 = my_strdup("user", 0);
        str3 = my_strdup("laptop", 0);
    }
    if (isatty(0)) {
        str = getcwd(src, UCHAR_MAX);
        if (str == NULL)
            exit(84);
        inter1(str1, str3, str, home);
    }
    free(str2);
    free(str3);
}

void handle_signal(int sig)
{
    print("stdout", "\n");
    print_dir((env_t *)data);
}

void handle_signal_2(int sig)
{
    print("stdout", "\n> ");
}

void handle_signal_3(int sig)
{
    print("stdout", "\n");
}
