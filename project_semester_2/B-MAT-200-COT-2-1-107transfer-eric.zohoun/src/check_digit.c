/*
** EPITECH PROJECT, 2025
** check_digit
** File description:
** check if it's a number or not
*/

#include "../include/math.h"

int check_digit(int ac, char **av)
{
    for (int j = 1; av[j] != NULL; j++) {
        for (int i = 0; av[j][i] != '\0'; i++) {
            if ((av[j][i] >= 48 && av[j][i] <= 57) ||
		(av[j][i] == '.' &&
		(av[j][i + 1] >= 48 && av[j][i + 1] <= 57)) ||
                (av[j][i] == '-' &&
                (av[j][i + 1] >= 48 && av[j][i + 1] <= 57)) ||
                (av[j][i] == '*' && av[j][0] != '*' &&
		((av[j][i + 1] >= 48 && av[j][i + 1] <= 57) || (av[j][i + 1] == '-' &&
		(av[j][i + 2] >= 48 && av[j][i + 2] <= 57))))) {
                continue;
            } else {
                exit(84);
            }
        }
    }
    return 0;
}
