/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "int.h"

typedef struct
{
    Class base;
    int value;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (!args) {
        raise("Construction failled. The system can not find any arguments.");
    }
    this->value = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    if (this != NULL)
        return;
    return;
}

static char *to_str_Int(Object *ptr)
{
    IntClass *object = (IntClass *)ptr;
    int size = snprintf (NULL, 0, "<Int (%d)>", object->value);
    char *str = malloc(sizeof (char)* size + 1);
    snprintf (str, size + 1, "<Int (%d)>", object->value);
    return str;
}

static Object *addition_function_Int (Object *ptr1, Object *ptr2)
{
    IntClass *first = (IntClass *)ptr1;
    IntClass *second = (IntClass *)ptr2;
    Object *three = new(Int,(first->value + second->value));
    return three;
}

static Object *substraction_function_Int (Object *ptr1, Object *ptr2)
{
    IntClass *first = (IntClass *)ptr1;
    IntClass *second = (IntClass *)ptr2;
    Object *three = new(Int,(first->value - second->value));
    return three;
}

static Object *multiplication_function_Int (Object *ptr1, Object *ptr2)
{
    IntClass *first = (IntClass *)ptr1;
    IntClass *second = (IntClass *)ptr2;
    Object *three = new(Int,(first->value * second->value));
    return three;
}

static Object *division_function_Int (Object *ptr1, Object *ptr2)
{
    IntClass *first = (IntClass *)ptr1;
    IntClass *second = (IntClass *)ptr2;
    Object *three = new(Int,(first->value / second->value));
    return three;
}

static bool int_eq(const Object *a, const Object *b)
{
    if (!a || !b) {
        raise("Invalid argument");
    }
    return (((IntClass *)a)->value == (((IntClass *)b)->value));
}

static bool int_gt(const Object *a, const Object *b)
{
    if (!a || !b) {
        raise("Invalid argument");
    }
    return (((IntClass *)a)->value > (((IntClass *)b)->value));
}

static bool int_lt(const Object *a, const Object *b)
{

    if (!a || !b) {
        raise("Invalid argument");
    }
    return (((IntClass *)a)->value < (((IntClass *)b)->value));
}

//Create additional functions here

static const IntClass _description = 
{
    {   /* Class struct */
        .__size__ = sizeof(_description), 
        .__name__ = "Point", 
        .__ctor__ = (ctor_t)&Int_ctor, 
        .__dtor__ = (dtor_t)&Int_dtor, 
        .__str__ = (to_string_t)&to_str_Int,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&addition_function_Int,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&substraction_function_Int,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&multiplication_function_Int, 
        .__div__ = (binary_operator_t)&division_function_Int, 
        .__eq__ = (binary_comparator_t)&int_eq, 
        .__gt__ = (binary_comparator_t)&int_gt, 
        .__lt__ = (binary_comparator_t)&int_lt
    }, 
    .value = 0
};

const Class *Int = (const Class *)&_description;
