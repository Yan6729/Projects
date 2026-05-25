/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 01
*/

#include "new.h"
#include "int.h"
#include "float.h"
#include "char.h"
#include "point.h"
#include "vertex.h"

void compareAndDivide(Object *a , Object *b)
{
    if (gt(a, b))
        printf ("a > b \n");
    else if (lt(a, b))
        printf ("a < b \n");
    else
        printf ("a == b\n");
    printf ("b / a = %s\n" , str(addition(b , a)));
}

int main(void)
{
    Object *int_1 = new(Char, '&');
    Object *int_2 = new(Char, '7');

    compareAndDivide(int_1, int_2);
    delete(int_1);
    delete(int_2);
    return (0);
}
