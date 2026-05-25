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
        for (b = 0; to_find[b] == str[a + b]; b++) {
        }
    }
    return (0);
}
