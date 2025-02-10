/*
** EPITECH PROJECT, 2025
** fizzbuzz.c
** File description:
** solo function
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void part1(int a, int b)
{
    if (a % 3 == 0)
        printf("Fizz\n");
    else if (a % 5 == 0)
        printf("Buzz\n");
    else
        printf("%d\n", a);
}

int fizzbuzz(int ac, char **av)
{
    int a = atoi(av[1]);
    int b = atoi(av[2]);

    while (a <= b) {
        if ((a % 3 == 0) && (a % 5 == 0))
            printf("FizzBuzz\n");
        else {
            part1(a, b);
        }
        a++;
    }
}

int main(int ac, char **av)
{
    int a = 58;

    if (ac <= 2 || ac > 3)
        return 84;
    if (av[1][0] == '\0' || av[2][0] == '\0')
        return 84;
    else if (atoi(av[2]) < atoi(av[1])) {
        write(1, "the second parameter must be greater than the first one.\n",
        a);
        return 84;
    }
    fizzbuzz(ac, av);
}
