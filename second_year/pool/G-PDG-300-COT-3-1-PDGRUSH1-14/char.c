/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "char.h"

typedef struct
{
    Class base;
    char c;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!args) {
        raise("Construction failled. The system can not find any arguments.");
    }
    this->c = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    if (this != NULL)
        return;
    return;
}

static char *to_str_Char(Object *ptr)
{
    CharClass *object = (CharClass *)ptr;
    int size = snprintf(NULL, 0, "<Char (%c)>", object->c);
    char *str = malloc(sizeof(char) * size+1);
    snprintf(str, size+1, "<Char (%c)>", object->c);
    return str;
}

static Object *addition_function_Char(Object *ptr1, Object *ptr2)
{
    CharClass *first = (CharClass *)ptr1;
    CharClass *second = (CharClass *)ptr2;
    Object *three = new(Char, (first->c + second->c));

    return three;
}

static Object *substraction_function_Char(Object *ptr1, Object *ptr2)
{
    CharClass *first = (CharClass *)ptr1;
    CharClass *second = (CharClass *)ptr2;
    Object *three = new(Char, (first->c - second->c));
 
    return three;
}


static Object *multiplication_function_Char(Object *ptr1, Object *ptr2)
{
    CharClass *first = (CharClass *)ptr1;
    CharClass *second = (CharClass *)ptr2;
    Object *three = new(Char, (first->c * second->c));

    return three;
}

static Object *division_function_Char(Object *ptr1, Object *ptr2)
{
    CharClass *first = (CharClass *)ptr1;
    CharClass *second = (CharClass *)ptr2;
    Object *three = new(Char, (first->c / second->c));
 
    return three;
}
// Create additional functions here

static bool char_eq(const Object *a, const Object *b)
{
    if (!a || !b) {
        raise("Invalid argument");
    }
    return (((CharClass *)a)->c == (((CharClass *)b)->c));
}

static bool char_gt(const Object *a, const Object *b)
{
    if (!a || !b) {
        raise("Invalid argument");
    }
    return (((CharClass *)a)->c > (((CharClass *)b)->c));
}

static bool char_lt(const Object *a, const Object *b)
{

    if (!a || !b) {
        raise("Invalid argument");
    }
    return (((CharClass *)a)->c < (((CharClass *)b)->c));
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(_description),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&to_str_Char,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&addition_function_Char,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&substraction_function_Char,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&multiplication_function_Char,
        .__div__ = (binary_operator_t)&division_function_Char,
        .__eq__ = (binary_comparator_t)&char_eq,
        .__gt__ = (binary_comparator_t)&char_gt,
        .__lt__ = (binary_comparator_t)&char_lt
    },
    .c = 0,
};

const Class *Char = (const Class *)&_description;