/*
** EPITECH PROJECT, 2024
** my_strncat
** File description:
** Write a function that concatenates two strings
*/
int my_strlen4(char *str)
{
    int n;

    n = 0;
    while (str[n] != '\0')
        n++;
    return (n);
}

char *my_strncat(char *dest, char *src, int nb)
{
    int b;
    int a;

    a = 0;
    b = my_strlen4(dest);
    while (a < nb) {
        dest[b] = src[a];
        a++;
        b++;
    }
    dest[b] = '\0';
    return (dest);
}
