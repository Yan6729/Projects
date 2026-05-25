/*
** EPITECH PROJECT, 2025
** my_cpuinfo.C
** File description:
** an intermediar function
*/

#include "mytop.h"

char *my_getcpuinfo(char *filepath)
{
    FILE *file = NULL;
    ssize_t len = 0;
    size_t fd;
    char *line = NULL;
    int ouv;

    if (filepath == NULL)
        exit(84);
    file = fopen(filepath, "r");
    if (file == NULL)
        exit(84);
    fd = getline(&line, &len, file);
    if (fd == -1)
        exit(84);
    return line;
}

void print_cpu(double *cpu)
{
    printw("\n%%Cpu(s):  %.1f us,  %.1f sy,", cpu[0], cpu[2]);
    printw(" %.1f ni,  %.1f id,", cpu[1], cpu[3]);
    printw("  %.1f wa,  %.1f hi,", cpu[4], cpu[5]);
    printw("  %.1f si,  %.1f st", cpu[6], cpu[7]);
}

void info(double *prev)
{
    char *src = my_getcpuinfo("/proc/stat");
    double *cpu = malloc(sizeof(double) * 8);
    int b[2] = {0, 0};
    double cpui = 0.0;

    for (int a = 0; a < 50; a++) {
        if (src[a - 1] == ' ' && (src[a] >= 48 && src[a] <= 57)) {
            cpu[b[0]] = atof(&src[a]);
            cpu[b[0]] -= prev[b[0]];
            prev[b[0]] += cpu[b[0]];
            cpui += cpu[b[0]];
            b[0]++;
        }
        if (b[0] == 8)
            break;
    }
    for (; b[1] < 8; b[1]++) {
        cpu[b[1]] = (cpu[b[1]] * 100) / cpui;
    }
    print_cpu(cpu);
}
