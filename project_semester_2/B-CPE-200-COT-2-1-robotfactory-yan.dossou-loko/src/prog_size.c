/*
** EPITECH PROJECT, 2025
** prog_size.c
** File description:
** just a file
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/robot.h"

int label(char *str)
{
    int b = 0;

    if (my_strcmp(str, "live") == 0 ||
        my_strcmp(str, "zjmp") == 0 ||
        my_strcmp(str, "fork") == 0 ||
        my_strcmp(str, "lfork") == 0) {
        b = 1;
    } else {
        b = 2;
    }
    return b;
}

int instruction_1(char *str)
{
    int b = 0;

    if (str[0] == 'r') {
        b = 1;
    }
    if (str[0] == '%') {
        b = 4;
    }
    if (str[0] >= 48 && str[0] <= 57) {
        b = 2;
    }
    return b;
}

int instruction_2(char *str)
{
    int b = 0;

    if (str[0] == 'r') {
        b = 1;
    }
    if (str[0] == '%') {
        b = 2;
    }
    if (str[0] >= 48 && str[0] <= 57) {
        b = 2;
    }
    return b;
}

int know_label(char *label, char *instruction)
{
    int b = 0;

    if (my_strcmp(label, "ldi") == 0 ||
        my_strcmp(label, "sti") == 0 ||
        my_strcmp(label, "zjmp") == 0 ||
        my_strcmp(label, "fork") == 0 ||
        my_strcmp(label, "lfork") == 0) {
        b += instruction_2(instruction);
    } else {
        b += instruction_1(instruction);
    }
    return b;
}

int recup(char *str)
{
    char *token;
    int b = 0;
    char **tab = my_split(str, " ");

    b = label(tab[0]);
    for (int a = 1; tab[a] != NULL; a++) {
        b += know_label(tab[0], tab[a]);
    }
    return b;
}
