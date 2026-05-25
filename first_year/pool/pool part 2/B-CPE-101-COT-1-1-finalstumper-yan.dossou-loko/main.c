/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** just a main file
*/

#include <unistd.h>
#include "rush3.h"
int main(void)
{
    int BUFF_SIZE = 30000;
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len;

    len = read(0, buff + offset, BUFF_SIZE - offset;
    while (len > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    rush3(buff);
    return (0);
}
