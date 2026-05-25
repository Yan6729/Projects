/*
** EPITECH PROJECT, 2025
** make_pizza.c
** File description:
** just a file
*/

#include "../include/my.h"

void error_message_2(char *name)
{
    my_puts("'make pizza': not enough ", 2);
    my_puts(name, 2);
    my_puts("\n", 2);
}

int error_case_pizza_2(ign_t *frigide)
{
    int b = 0;

    if (frigide[4].qut < 8) {
        error_message_2(frigide[4].name);
        b = 4;
    }
    if (frigide[5].qut < 8) {
        error_message_2(frigide[5].name);
        b = 5;
    }
    if (frigide[6].qut < 4) {
        error_message_2(frigide[6].name);
        b = 6;
    }
    if (frigide[7].qut < 3) {
        error_message_2(frigide[7].name);
        b = 7;
    }
    return b;
}

int error_case_pizza_1(ign_t *frigide)
{
    int b = 0;

    if (frigide[0].qut < 5) {
        error_message_2(frigide[0].name);
        b = 1;
    }
    if (frigide[1].qut < 1) {
        error_message_2(frigide[1].name);
        b = 2;
    }
    if (frigide[2].qut < 3) {
        error_message_2(frigide[2].name);
        b = 3;
    }
    return b;
}

ign_t *make_pizza(ign_t *frigide)
{
    if (frigide == NULL)
        exit(84);
    if (error_case_pizza_1(frigide) != 0 || error_case_pizza_2(frigide) != 0)
        return frigide;
    frigide[0].qut -= 5;
    frigide[1].qut -= 1;
    frigide[2].qut -= 3;
    frigide[4].qut -= 8;
    frigide[5].qut -= 8;
    frigide[6].qut -= 4;
    frigide[7].qut -= 3;
    return frigide;
}
