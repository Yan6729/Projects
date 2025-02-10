/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a++;
    }
    return (a);
}
