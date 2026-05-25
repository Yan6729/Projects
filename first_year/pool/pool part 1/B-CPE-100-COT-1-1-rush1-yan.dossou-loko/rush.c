/*
** EPITECH PROJECT, 2024
** rush.c
** File description:
** rush.c
*/

#include <unistd.h>
#include <stdio.h>
void my_putchar(char c)
{
    write (1, &c, 1);
}
int rush(int x, int y)
{
    int i;
    int j;
    for (j=1; j <= y; j++) {
        for(i=1; i <= x; i++) {
            if (j == 1 && i == 1 || j == y && i == x || j == 1 && i == x || j == y && i == 1)  
		my_putchar('o');
	    else if (j != 1 && i == 1 || j != y && i == x)
	       my_putchar('|');
	    else if (j == 1 || j == y || i == 1 || i == x)
                my_putchar('-');
	    else
		my_putchar(' ');
	}
        my_putchar('\n');
    }
}
int main(void) {
    rush(10, 10);
    return 0;
}
