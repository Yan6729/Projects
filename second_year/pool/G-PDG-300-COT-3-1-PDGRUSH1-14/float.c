/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "float.h"

typedef struct
{
    Class base;
    float flo;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (!args) {
        raise("Construction failled. The system can not find any arguments.");
    }
    this->flo = (float)va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    if (this != NULL)
        return;
    return;
}

static char *to_str_Float(Object *ptr)
{
    FloatClass *object = (FloatClass *)ptr;
    int size = snprintf(NULL, 0, "<Float (%f)>", object->flo);
    char *str = malloc(sizeof(char) * size+1);
    snprintf(str, size+1, "<Float (%f)>", object->flo);
    return str;
}

static Object *addition_function_Float(Object *ptr1, Object *ptr2)
{
    FloatClass *first = (FloatClass *)ptr1;
    FloatClass *second = (FloatClass *)ptr2;
    Object *three = new(Float, (first->flo + second->flo));

    return three;
}

static Object *substraction_function_Float(Object *ptr1, Object *ptr2)
{
    FloatClass *first = (FloatClass *)ptr1;
    FloatClass *second = (FloatClass *)ptr2;
    Object *three = new(Float, (first->flo - second->flo));
 
    return three;
}


static Object *multiplication_function_Float(Object *ptr1, Object *ptr2)
{
    FloatClass *first = (FloatClass *)ptr1;
    FloatClass *second = (FloatClass *)ptr2;
    Object *three = new(Float, (first->flo * second->flo));

    return three;
}

static Object *division_function_Float(Object *ptr1, Object *ptr2)
{
    FloatClass *first = (FloatClass *)ptr1;
    FloatClass *second = (FloatClass *)ptr2;
    Object *three = new(Float, (first->flo / second->flo));
 
    return three;
}
// Create additional functions here

static bool float_eq(const Object *a, const Object *b)
{
    if (!a || !b) {
        raise("Invalid argument");
    }
    return (((FloatClass *)a)->flo == (((FloatClass *)b)->flo));
}

static bool float_gt(const Object *a, const Object *b)
{
    if (!a || !b) {
        raise("Invalid argument");
    }
    return (((FloatClass *)a)->flo > (((FloatClass *)b)->flo));
}

static bool float_lt(const Object *a, const Object *b)
{

    if (!a || !b) {
        raise("Invalid argument");
    }
    return (((FloatClass *)a)->flo < (((FloatClass *)b)->flo));
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(_description),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&to_str_Float,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&addition_function_Float,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&substraction_function_Float,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&multiplication_function_Float,
        .__div__ = (binary_operator_t)&division_function_Float,
        .__eq__ = (binary_comparator_t)&float_eq,
        .__gt__ = (binary_comparator_t)&float_gt,
        .__lt__ = (binary_comparator_t)&float_lt
    },
    .flo = 0
};

const Class *Float = (const Class *)&_description;