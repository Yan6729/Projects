/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** my_getnbr.c
*/
#include <stdio.h>

int my_getnbr(char const *str)
{
    int b = 0;
    int a;
    int nombre = 0;
    int signe = 1;

    for (a = 0; str[a] == '-' || str[a] == '+'; a++) {
        if (str[a] == '-') {
	    signe = signe * (-1);
	}
    }
    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] >= '0' && str[a] <= '9') {
            b = b * 10 + (str[a] - '0');
        }
        if (str[a] == '-' || str[a] == '+') {
	    continue;
	}
    }
    return (b * signe);
}
int main(void)
{
    char *str = "-+-+-288Bonjour";
    printf("%d", my_getnbr(str));
}
