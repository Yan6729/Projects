/*
** EPITECH PROJECT, 2024
** my_strstr.c
** File description:
** my_strstr.c
*/

char *my_strstr(char *str, char const *to_find)
{
    int a;
    int b;

    for (a = 0; str[a] != '\0'; a++) {
        b = 0;
        while (to_find[b] == str[a + b]) {
            if (to_find[b + 1] == '\0') {
                return (str + a);
            }
            b++;
        }
    }
    return (0);
}
