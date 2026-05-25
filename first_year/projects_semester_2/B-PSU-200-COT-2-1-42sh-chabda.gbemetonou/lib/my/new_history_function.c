/*
** EPITECH PROJECT, 2024
** Elementary
** File description:
** Map from file.
*/

#include "../../include/shell.h"

d_hist_t new_dlist(void)
{
    return NULL;
}

int is_empty(d_hist_t list)
{
    if (list == NULL)
        return 1;
    return 0;
}

int lenght_li(d_hist_t list)
{
    if (is_empty(list))
        return 0;
    return list->lenght;
}
