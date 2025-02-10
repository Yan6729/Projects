/*
** EPITECH PROJECT, 2024
** command to take memory info
** File description:
** just a test
*/

#include "mytop.h"

char *my_getmeminfo(void)
{
    double *loadavg;
    char *buffer;
    int lire;
    int ouv;

    buffer = malloc(sizeof(char) * (728 + 1));
    ouv = open("/proc/meminfo", O_RDONLY);
    lire = read(ouv, buffer, 728);
    close(lire);
    return buffer;
}

char **read_meminfo(char **map, int i, int c)
{
    char *src = my_getmeminfo();
    int a = 0;
    int b = 0;

    map = malloc(sizeof(char *) * (120 + 2));
    for (i = 0; i < 120; i++)
        map[i] = malloc(sizeof(char) * (728 + 1));
    for (c = 0; c < 728; c++) {
        map[a][b] = src[c];
        b++;
        if (src[c] == '\n') {
            map[a][b] = '\0';
            b = 0;
            a++;
        }
    }
    map[a][b] = '\0';
    free(src);
    return map;
}

double *memory(int c, int i)
{
    int a;
    char **mem = read_meminfo(mem, c, i);
    double *memo = malloc(sizeof(double) * 8);

    memo[0] = convert(mem[0]);
    memo[1] = convert(mem[1]);
    memo[2] = convert(mem[2]);
    memo[3] = convert(mem[3]) + convert(mem[4]) + convert(mem[25]);
    memo[4] = convert(mem[0]) - convert(mem[2]);
    memo[5] = convert(mem[14]);
    memo[6] = convert(mem[15]);
    memo[7] = convert(mem[14]) - convert(mem[15]);
    for (a = 0; mem[a] != NULL; a++)
        free(mem[a]);
    free(mem);
    return memo;
}

double *convertion(int a, int c)
{
    double *mem = memory(a, c);
    double *memo = malloc(sizeof(double) * 8);

    memo[0] = (mem[0] / 1024);
    memo[1] = (mem[1] / 1024);
    memo[2] = (mem[2] / 1024);
    memo[3] = (mem[3] / 1024);
    memo[4] = (mem[4] / 1024);
    memo[5] = (mem[5] / 1024);
    memo[6] = (mem[6] / 1024);
    memo[7] = (mem[7] / 1024);
    free(mem);
    return memo;
}
