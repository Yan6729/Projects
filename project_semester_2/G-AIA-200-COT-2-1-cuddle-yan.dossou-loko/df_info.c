/*
** EPITECH PROJECT, 2025
** info
** File description:
** info
*/

#include "include/dataframe.h"

void info_cond(dataframe_t *dataframe, int i)
{
    if (dataframe->column_types[i] == BOOL) {
        printf("bool\n");
    }
    if (dataframe->column_types[i] == INT) {
        printf("int\n");
    }
    if (dataframe->column_types[i] == UINT) {
        printf("unsigned int\n");
    }
    if (dataframe->column_types[i] == FLOAT) {
        printf("float\n");
    }
    if (dataframe->column_types[i] == STRING) {
        printf("string\n");
    }
    if (dataframe->column_types[i] == UNDEFINED) {
        printf("undefined\n");
    }
}

void df_info(dataframe_t *dataframe)
{
    if (dataframe == NULL)
        return;
    printf("%d columns:\n", dataframe->nb_columns);
    for (int i = 0; i < dataframe->nb_columns; i++) {
        printf("- %s: ", dataframe->column_names[i]);
        info_cond(dataframe, i);
        if (dataframe->column_types[i] != BOOL
            && dataframe->column_types[i] != INT
            && dataframe->column_types[i] != STRING
            && dataframe->column_types[i] != FLOAT
            && dataframe->column_types[i] != UNDEFINED
            && dataframe->column_types[i] != UINT) {
            exit(84);
        }
    }
}
