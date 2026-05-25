/*
** EPITECH PROJECT, 2025
** character frequency
** File description:
** frequent character
*/

#include "../include/stumper.h"

int frequenc_char(char *str, char c)
{
    int count = 0;
    int i;
    int j;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}

int verify(occur_t **data, char *str1, char *str2)
{
    int b = 0;

    for (int a = 0; str2[a] != '\0'; a++) {
        b = frequenc_char(str1, str2[a]);
        add_in(data, b, str2[a]);
    }
}

void flag_t(occur_t **data, int ac, char **av)
{
    if (ac == 3 && strcmp(av[1], "-t") == 0) {
        verify(data, av[2], av[2]);
        *data = mergesort_id(data);
    }
    if (ac == 4 && strcmp(av[1], "-t") == 0) {
        verify(data, av[2], av[3]);
        *data = mergesort_id(data);
    }
}

int main(int ac, char **av)
{
    occur_t *data = NULL;

    if (ac == 1 || ac > 5)
	exit(84);
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        print("stdout", ".text_count [-r] [-t]");
        print("stdout", " STR [SEARCHED_CHARACTERS]");
        exit(0);
    }
    if (ac == 2 && strcmp(av[1], "-h") != 0) {
        verify(&data, av[1], av[1]);
    }
    if (ac == 3 && strcmp(av[1], "-r") != 0 && strcmp(av[1], "-t") != 0) {
        verify(&data, av[1], av[2]);
    }
    flag_t(&data, ac, av);
    print_list(&data);
}
