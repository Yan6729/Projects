/*
** EPITECH PROJECT, 2025
** authentication
** File description:
** username and password
*/

#include "my.h"
#include <crypt.h>
#include <unistd.h>

void print(char **str)
{
    for (int i = 0; str[i] != NULL; i++) {
        printf("%s\n", str[i]);
    }
}

char *open_file(char const *filepath, char *username)
{
    char *str = NULL;
    size_t len = 0;
    char **line = NULL;
    char *hash = NULL;
    FILE *file = fopen(filepath, "r");

    if (!file)
        return NULL;
    while (getline(&str, &len, file) != -1) {
        if (strncmp(str, username, strlen(username)) == 0) {
            line = spe_str_to_word_array(str);
            hash = line[1];
            return hash;
        }
    }
    return NULL;
}

char *get_name(void)
{
    char *str = NULL;
    size_t len = 0;
    char **line = NULL;
    char *username = NULL;
    char id[10];
    FILE *file = fopen("/etc/passwd", "r");

    if (!file)
        return NULL;
    sprintf(id, "%d", getuid());
    while (getline(&str, &len, file) != -1) {
        if (strstr(str, id) != NULL) {
            line = spe_str_to_word_array(str);
            username = line[0];
            return username;
        }
    }
    return NULL;
}

void style2(int i)
{
    if (i < 2)
        printf("Sorry, try again.\n");
    else {
        printf("sudo: %d incorrect password attempts\n", i + 1);
        exit(1);
    }
}

int get_passwd(void)
{
    char r_passwd[256];
    char *crypt_passwd = NULL;
    char *username = get_name();
    char *passwd = open_file("/etc/shadow", username);

    if (passwd == NULL)
        exit(84);
    for (int i = 0; i < 3; i++) {
        printf("[my_sudo] password for %s :", username);
        scanf("%s", r_passwd);
        crypt_passwd = crypt(r_passwd, passwd);
        if (strcmp(crypt_passwd, passwd) == 0) {
            return 0;
        } else {
            style2(i);
        }
    }
    return -1;
}
