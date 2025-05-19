/*
** EPITECH PROJECT, 2025
** write
** File description:
** write
*/

#include "include/dataframe.h"

int write_cond(dataframe_t *dataframe, int j, void *value, FILE *file)
{
    if (dataframe->column_types[j] == INT)
        fprintf(file, "%d", *(int *)value);
    if (dataframe->column_types[j] == FLOAT)
        fprintf(file, "%.2f", *(float *)value);
    if (dataframe->column_types[j] == STRING)
        fprintf(file, "%s", (char *)value);
    if (dataframe->column_types[j] == BOOL)
        fprintf(file, "%s", *(bool *)value ? "true" : "false");
    if (dataframe->column_types[j] != FLOAT &&
        dataframe->column_types[j] != INT &&
        dataframe->column_types[j] != STRING &&
        dataframe->column_types[j] != BOOL) {
        fclose(file);
        return 84;
    }
    if (j < dataframe->nb_columns - 1)
        fprintf(file, ",");
}

int error_case(dataframe_t *dataframe, const char *filename)
{
    if (dataframe == NULL || filename == NULL)
        exit(84);
}

int df_write_csv(dataframe_t *dataframe, const char *filename)
{
    void *value;
    FILE *file;

    error_case(dataframe, filename);
    file = fopen(filename, "w");
    for (int i = 0; i < dataframe->nb_columns; i++) {
        fprintf(file, "%s", dataframe->column_names[i]);
        if (i < dataframe->nb_columns - 1) {
            fprintf(file, ",");
        }
    }
    fprintf(file, "\n");
    for (int i = 0; i < dataframe->nb_rows; i++) {
        for (int j = 0; j < dataframe->nb_columns; j++) {
            value = dataframe->data[i][j];
            write_cond(dataframe, j, value, file);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    return 0;
}
