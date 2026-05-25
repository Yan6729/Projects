/*
** EPITECH PROJECT, 2026
** z.c
** File description:
** main file
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zorglub(void)
{
    write(1, "z\n", 2);
}

int main(void)
{
    zorglub();
    return 0;
}
