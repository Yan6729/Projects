#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string.h>

#include "my.h"
int my_strlen(char const *str) {
    int a = 0;
    int b = 0;

    for (a = 0; str[a] != '\0'; a++) {
        b++;
    }
    return b;
}

int my_cmpword(char *str)
{
    int a = 0;
    int b = 1;

    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] == ' ')
            b++;
        else
            continue;
    }
    return b;
}

char **my_strwrdarray(char *str)
{
    int c = 0;
    int a = 0;
    int b = 0;
    char **tableau;

    tableau = my_malloc(str);
    for (c = 0; str[c] != '\0'; c++) {
        tableau[a][b] = str[c];
        b++;
        if (str[c + 1] == ' ' && str[c + 1] != '\0') {
	    c++;
            tableau[a][b] = '\0';
            b = 0;
            a++;
        }
    }
    tableau[a][b] = '\0';
    return tableau;
}

//int main(int ac, char **av)
//{
//    char **tab = my_strwrdarray(av[1]); //my_strwrldarray("....o....\n....o....\n....o....\n....o....\n");

//    printf("%d",my_str(tab, 0, 3, 3));
//    for (int a = 0; tab[a] != NULL; a++)
//	printf("%s\n", tab[a]);
//    return 0;
//}
