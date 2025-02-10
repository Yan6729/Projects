/*
** EPITECH PROJECT, 2025
** palindrome.c
** File description:
** function of solo stumper
*/

#include "stumper.h"

int error_case(char *str)
{
    int a = 0;

    if (str[0] == '\0')
        return 84;
    if (str[0] == ' ' && str[1] == '\0')
        return 84;
    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] >= 97 && str[a] <= 122 || str[a] == ' ')
            return 0;
        else
            return 84;
    }
}

int palendrome(char *str)
{
    char *src = my_strlowcase(str);
    int a = my_strlen(src);
    int b = 0;
    int c = 0;

    if (src[0] == src[a - 1] && (a % 2 == 0))
        my_putstr("palendrome!\n");
    else
        my_putstr("not a palendrome.\n");
}

int main(int ac, char **av)
{
    if (ac == 1)
        return 84;
    else if (error_case(my_strlowcase(av[1])) == 84)
        return 84;
    else
        palendrome(av[1]);
}
