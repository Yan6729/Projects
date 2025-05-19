/*
** EPITECH PROJECT, 2024
** getnbr
** File description:
** get number
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

int mygetnbr(int result, int i, char *str)
{
    if (result > ((2147483647 - (str[i] - '0')) / 10))
        return 0;
    else if (result > ((2147483648 - (str[i] - '0')) / 10))
        return 0;
}

int my_getnbr(char *str)
{
    int i = 0;
    int signe = 1;
    int result = 0;

    if ((str[i] < '0' || str[i] > '9'))
        return 84;
    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            mygetnbr(result, i, str);
            result = result * 10 + (str[i] - '0');
        } else
            break;
    }
    return (result);
}
