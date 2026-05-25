/*
** EPITECH PROJECT, 2024
** my_rush.c
** File description:
** my_rush.c
*/

#include <stdio.h>
#include <unistd.h>
void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_rush(int x, int y) {
    int i;
    int j;
    for (i = 1; i <= x; i++) {
	for (j = 1; j <= y; j++) {
	    if (i == 1 || i == x|| j == y || j == 1) {
		if (i == 1 && j == 1) {
		    my_putchar('A');
		}
		if (i == x && j == 1) {
		    my_putchar('A');
		}
		if (i == 1 && j == y) {
		    my_putchar('A');
		}
		if (i == x && j == y) {
		    my_putchar('A');
		}
	    } else { 
	    if (j != 1 && i == 1 || j != y && i == x) {
		    my_putchar('B');
		    } else {
		    if (j == 1 || i == 1 || j == y || i == x) {
		    my_putchar('B');
		    } else {
		    my_putchar('-');
		}
	    }
	}
	}
	my_putchar('\n');
    }
}

int main(void) {
    my_rush(5, 5);
    return 0;
}
