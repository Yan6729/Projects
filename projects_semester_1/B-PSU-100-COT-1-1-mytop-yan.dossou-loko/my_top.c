/*
** EPITECH PROJECT, 2024
** my_top.c
** File description:
** function that have the same role than the shell's function
*/

#include "mytop.h"

void line(void)
{
    move(6, 0);
    start_color();
    init_pair(5, COLOR_BLACK, COLOR_WHITE);
    attron(COLOR_PAIR(5));
    printw("    PID USER      NI    VIRT    RES    SHR");
    printw(" %c  %s  %s    ", 'S', "%CPU", "%MEM");
    printw("%s %-92s", "TIME+", "COMMAND");
    attroff(COLOR_PAIR(5));
}

void memoire(void)
{
    double *memo;
    int c;
    int a;

    memo = convertion(a, c);
    printw("\nMiB Mem :  %.1f total,   %.1f free,", memo[0], memo[1]);
    printw("   %.1f used,   %.1f buff/cache", memo[4], memo[3]);
    printw("\nMiB Swap:   %.1f total,   %.1f free,", memo[5], memo[6]);
    printw("      %.1f used,   %.1f avail Mem", memo[7], memo[2]);
    free(memo);
}

void loadavg(void)
{
    double *loadavg = my_getloadavg(0);
    int *time = time_up();

    printw("top - %d:%d:%d up", time[0] + 1, time[1], time[2]);
    print_up();
    printw("  0 user,");
    printw("  load average:");
    printw(" %.2f, %.2f, %.2f", loadavg[0], loadavg[1], (loadavg[2] / 100));
    my_get_pid();
    free(loadavg);
    free(time);
}

int my_top(void)
{
    char c;
    double prev[8] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    initscr();
    timeout(1000);
    line();
    noecho();
    while (c != 'q') {
        move(0, 0);
        loadavg();
        info(prev);
        memoire();
        refresh();
        c = getch();
    }
    endwin();
    return 0;
}

int main(int ac, char **av)
{
    my_top();
    return 0;
}
