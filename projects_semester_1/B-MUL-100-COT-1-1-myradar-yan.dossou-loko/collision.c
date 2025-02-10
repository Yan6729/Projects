/*
** EPITECH PROJECT, 2025
** collision.c
** File description:
** function who made collision
*/

#include "struct.h"

int aircraft_detection(plane_t *box1, plane_t *box2)
{
    if (box1 == NULL || box2 == NULL)
        return (84);
    if (((box2->Xi >= box1->Xi + 20)
        || (box2->Xi + 20 <= box1->Xi)
        || (box2->Yi >= box1->Yi + 20)
        || (box2->Yi + 20 <= box1->Yi)) && box1->id != box2->id)
        return 0;
    else
        return 1;
}
