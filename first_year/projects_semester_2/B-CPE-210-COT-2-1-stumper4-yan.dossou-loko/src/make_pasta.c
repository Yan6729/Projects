/*
** EPITECH PROJECT, 2025
** make_pizza.c
** File description:
** just a file
*/

#include "../include/my.h"

void error_message(char *name)
{
    my_puts("'make pasta': not enough ", 2);
    my_puts(name, 2);
    my_puts("\n", 2);
}

int error_case_pasta_2(ign_t *frigide)
{
    int b = 0;

    if (frigide[6].qut < 4) {
        error_message(frigide[6].name);
        b = 4;
    }
    if (frigide[7].qut < 3) {
        error_message(frigide[7].name);
        b = 5;
    }
    return b;
}

int error_case_pasta_1(ign_t *frigide)
{
    int b = 0;

    if (frigide[0].qut < 5) {
        error_message(frigide[0].name);
        b = 1;
    }
    if (frigide[3].qut < 2) {
        error_message(frigide[3].name);
        b = 2;
    }
    if (frigide[4].qut < 6) {
        error_message(frigide[4].name);
        b = 3;
    }
    return b;
}

ign_t *make_pasta(ign_t *frigide)
{
    if (frigide == NULL)
        exit(84);
    if (error_case_pasta_1(frigide) != 0 || error_case_pasta_2(frigide) != 0)
        return frigide;
    frigide[0].qut -= 5;
    frigide[3].qut -= 2;
    frigide[4].qut -= 6;
    frigide[7].qut -= 3;
    frigide[6].qut -= 4;
    return frigide;
}
