/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"

typedef struct
{
    Class base;
    int x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!args) {
        raise("Construction failled. The system can not find any arguments.");
    }
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    if (this != NULL)
        return;
    return;
}

static char *to_str_vertex(Object *ptr)
{
    VertexClass *object = (VertexClass *)ptr;
    int size = snprintf(NULL, 0, "<Vertex (%d, %d, %d)>", object->x, object->y, object->z);
    char *str = malloc(sizeof(char) * size+1);
    snprintf(str, size+1, "<Vertex (%d, %d, %d)>", object->x, object->y, object->z);
    return str;
}

static Object *addition_function_vertex(Object *ptr1, Object *ptr2)
{
    VertexClass *first = (VertexClass *)ptr1;
    VertexClass *second = (VertexClass *)ptr2;
    Object *three = new(Vertex, (first->x + second->x), (first->y + second->y), (first->z + second->z));

    return three;
}

static Object *substraction_function_vertex(Object *ptr1, Object *ptr2)
{
    VertexClass *first = (VertexClass *)ptr1;
    VertexClass *second = (VertexClass *)ptr2;
    Object *three = new(Vertex, (first->x - second->x), (first->y - second->y), (first->z - second->z));
 
    return three;
}


static Object *multiplication_function_vertex(Object *ptr1, Object *ptr2)
{
    VertexClass *first = (VertexClass *)ptr1;
    VertexClass *second = (VertexClass *)ptr2;
    Object *three = new(Vertex, (first->x * second->x), (first->y * second->y), (first->z * second->z));

    return three;
}

static Object *division_function_vertex(Object *ptr1, Object *ptr2)
{
    VertexClass *first = (VertexClass *)ptr1;
    VertexClass *second = (VertexClass *)ptr2;
    Object *three = new(Vertex, (first->x / second->x), (first->y / second->y), (first->z / second->z));
 
    return three;
}


static bool vertex_eq(const Object *a, const Object *b)
{
    VertexClass *one = (VertexClass *)a;
    VertexClass *two = (VertexClass *)b;

    if (!a || !b) {
        raise("Invalid argument");
    }
    return (one->x == two->x) && (one->y == two->y) && (one->y == two->y);
}

static bool vertex_gt(const Object *a, const Object *b)
{
    VertexClass *one = (VertexClass *)a;
    VertexClass *two = (VertexClass *)b;

    if (!a || !b) {
        raise("Invalid argument");
    }
    return (one->x > two->x) && (one->y > two->y) && (one->z > two->z);
}

static bool vertex_lt(const Object *a, const Object *b)
{
    VertexClass *one = (VertexClass *)a;
    VertexClass *two = (VertexClass *)b;

    if (!a || !b) {
        raise("Invalid argument");
    }
    return (one->x < two->x) && (one->y < two->y) && (one->z < two->z);
}
// Create additional functions here

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(_description),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&to_str_vertex,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&addition_function_vertex,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&substraction_function_vertex,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&multiplication_function_vertex,
        .__div__ = (binary_operator_t)&division_function_vertex,
        .__eq__ = (binary_comparator_t)&vertex_eq,
        .__gt__ = (binary_comparator_t)&vertex_gt,
        .__lt__ = (binary_comparator_t)&vertex_lt
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;
