/*
** EPITECH PROJECT, 2025
** error case
** File description:
** managment of error_case
*/

#include "../B-CPE-200_op/op.h"
#include "../include/robot.h"

int check(char *filename, char **tab)
{
    int i = my_strlen(filename);
    char *str = check_name(tab[0], tab);

    if (str == NULL)
        return 84;
    if (my_strncmp(tab[1], COMMENT_CMD_STRING, 8) != 0) {
            my_puts_2("asm, ");
            my_puts_2(filename);
            my_puts_2(", line 2: Invalid instruction\n");
            return 84;
        }
    if (my_strlen(str) > PROG_NAME_LENGTH) {
        my_puts_2("asm, ");
        my_puts_2(filename);
        my_puts_2(", line 1: The program name is too long.\n");
        return 84;
    }
    return 0;
}

int cond_error(char **tab, char *str)
{
    if (my_strncmp(tab[0], NAME_CMD_STRING, 5) != 0) {
        my_puts_2("asm, ");
        my_puts_2(str);
        my_puts_2(", line 1: Invalid instruction\n");
        return 84;
    }
}

char *check_name(char *str, char **tab)
{
    int i = 7;
    int x = 0;
    char *name = NULL;

    if (str[6] != '"')
        return NULL;
    for (; str[i] != '"'; i++) {
        x++;
    }
    name = malloc(sizeof(char) * (x + 1));
    i = 7;
    x = 0;
    for (; str[i] != '"'; i++) {
        name[x] = str[i];
        x++;
    }
    name[i] = '\0';
    if (cond_error(tab, str) == 84)
        return NULL;
    return name;
}
