/*
** EPITECH PROJECT, 2026
** G-PDG-300-COT-3-1-PDGRUSH1-14
** File description:
** new
*/

#include <stdlib.h>
#include "new.h"
#include "raise.h"
#include "object.h"
#include "point.h"
#include "vertex.h"
#include "int.h"
#include "float.h"
#include "char.h"

Object *va_new(const Class *class, va_list *ap)
{
    Object *obj;

    if (!class)
        raise("Class is NULL");

    obj = malloc(class->__size__);
    if (!obj)
        raise("Out of memory");

    memcpy(obj, class, class->__size__);

    if (class->__ctor__)
	    class->__ctor__(obj, ap);
    return obj;
}

Object *new(const Class *class, ...)
{
    Object *obj;
    va_list ap;

    va_start(ap, class);
    obj = va_new(class, &ap);
    va_end(ap);

    return obj;
}

void delete(Object *ptr)
{
    Class *class;

    if (!ptr) {
        return;
    }
    class = (Class *)ptr;
    if (class->__dtor__) {
        class->__dtor__(ptr);
    }
    free(ptr);
}
