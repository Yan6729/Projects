/*
** EPITECH PROJECT, 2025
** type general
** File description:
** type general
*/

#include "include/dataframe.h"

value_t type_var(char *val)
{
    value_t type = {-1, -1, -1, -1, -1};

    if (strcmp(val, "true") != 0 && strcmp(val, "false") != 0) {
        type.boolean = 0;
    }
    if (!(is_int(val))) {
        type.integer = 0;
        type.uinteger = 0;
    }
    if (!(is_int_2(val))) {
        type.integer = 0;
        type.uinteger = 0;
    }
    if (!(is_string(val))) {
        type.string = 0;
    }
    if (!(is_float(val))) {
        type.floating = 0;
    }
    return type;
}

column_type_t determine_type(char **values, int nb_val)
{
    value_t type;
    char *val = NULL;

    for (int i = 0; i < nb_val; i++) {
        val = values[i];
        type = type_var(val);
    }
    if (type.integer)
        return INT;
    if (type.string)
        return STRING;
    if (type.floating)
        return FLOAT;
    if (type.boolean)
        return BOOL;
    if (type.uinteger)
        return UINT;
}
