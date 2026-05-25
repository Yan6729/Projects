/*
** EPITECH PROJECT, 2024
** my_cmpworld.c
** File description:
** compt the number of line
*/

int my_cmpworld(char *str)
{
    int a = 0;
    int b = 1;

    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] == '\n')
            b++;
        else
            continue;
    }
    return b;
}
