/*
** EPITECH PROJECT, 2025
** exec_2
** File description:
** additionnal functions fotr checking the sudoers file
*/

#include "my.h"

int verify_grp(void)
{
    char *str = NULL;
    char stock[128];
    size_t len = 0;
    char **line = NULL;
    char buffer[256];
    FILE *file = fopen("/etc/sudoers", "r");

    if (!file)
        return 84;
    while (getline(&str, &len, file) != -1) {
        if (str[0] == '%' && strstr(str, "ALL=(ALL)ALL") != NULL) {
            sscanf(str, "%%%127s", stock);
            if (verify_g(stock) == 1)
                return 1;
        }
    }
    return 0;
}
