/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** compt the number of column
*/

int my_strlen(char *str)
{
    int a = 0;
    int b = 0;

    for (a = 0; str[a] != '\0'; a++) {
        b++;
    }
    return b;
}
