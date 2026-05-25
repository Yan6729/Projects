/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"

typedef struct
{
    Class base;
    int x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{   
    if (!args) {
        raise("Construction failled. The system can not find any arguments.");
    }
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    if (this != NULL)
        return;
    return;
}

static char *to_str_point(Object *ptr)
{
    PointClass *object = (PointClass *)ptr;
    int size = snprintf(NULL, 0, "<Point (%d, %d)>", object->x, object->y);
    char *str = malloc(sizeof(char) * size+1);
    snprintf(str, size+1, "<Point (%d, %d)>", object->x, object->y);
    return str;
}

static Object *addition_funtion_point(Object *ptr1, Object *ptr2)
{
    PointClass *first = (PointClass *)ptr1;
    PointClass *second = (PointClass *)ptr2;
    Object *three = new(Point, (first->x + second->x), (first->y + second->y));

    return three;
}

static Object *substraction_function_point(Object *ptr1, Object *ptr2)
{
    PointClass *first = (PointClass *)ptr1;
    PointClass *second = (PointClass *)ptr2;
    Object *three = new(Point, (first->x - second->x), (first->y - second->y));

    return three;
}

static Object *multiplication_function_point(Object *ptr1, Object *ptr2)
{
    PointClass *first = (PointClass *)ptr1;
    PointClass *second = (PointClass *)ptr2;
    Object *three = new(Point, (first->x * second->x), (first->y * second->y));

    return three;
}

static Object *division_function_point(Object *ptr1, Object *ptr2)
{
    PointClass *first = (PointClass *)ptr1;
    PointClass *second = (PointClass *)ptr2;
    Object *three = new(Point, (first->x / second->x), (first->y / second->y));

    return three;
}

static bool point_eq(const Object *a, const Object *b)
{
    PointClass *one = (PointClass *)a;
    PointClass *two = (PointClass *)b;

    if (!a || !b) {
        raise("Invalid argument");
    }
    return (one->x == two->x) && (one->y == two->y);
}

static bool point_gt(const Object *a, const Object *b)
{
    PointClass *one = (PointClass *)a;
    PointClass *two = (PointClass *)b;

    if (!a || !b) {
        raise("Invalid argument");
    }
    return (one->x > two->x) && (one->y > two->y);
}

static bool point_lt(const Object *a, const Object *b)
{
    PointClass *one = (PointClass *)a;
    PointClass *two = (PointClass *)b;

    if (!a || !b) {
        raise("Invalid argument");
    }
    return (one->x < two->x) && (one->y < two->y);
}

// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(_description),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&to_str_point,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&addition_funtion_point,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&substraction_function_point,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&multiplication_function_point,
        .__div__ = (binary_operator_t)&division_function_point,
        .__eq__ = (binary_comparator_t)&point_eq,
        .__gt__ = (binary_comparator_t)&point_gt,
        .__lt__ = (binary_comparator_t)&point_lt
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;
