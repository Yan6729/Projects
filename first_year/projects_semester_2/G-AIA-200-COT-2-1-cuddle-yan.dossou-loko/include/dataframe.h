/*
** EPITECH PROJECT, 2025
** dataframe.h
** File description:
** just the ".h" file of cuddle
*/

#ifndef DATAFRAME_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <math.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <limits.h>
    #include <stdbool.h>
    #define DATAFRAME_H

typedef struct index_s {
    int k;
    int i;
    int j;
    int lig;
} index_t;

typedef enum column_type_s {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED,
} column_type_t;

typedef struct element_s {
    char **element;
    struct element_s *next;
} element_t;

typedef struct dataframe_s {
    int nb_rows;
    int nb_columns;
    element_t *list;
    char **column_names;
    column_type_t *column_types;
    void ***data;
} dataframe_t;

typedef struct value_s {
    int boolean;
    int integer;
    int uinteger;
    int string;
    int floating;
} value_t;

typedef struct dataframe_shape_s {
    int nb_rows;
    int nb_columns;
} dataframe_shape_t;

char **parsing(char const *filepath);
char **my_split(char *str, const char *delim);
int is_int(char *str);
int is_int_2(char *str);
int check_digit(char *str);
int check_num_of_point(char *str);
int check_alpha_other(char *str);
int is_string(char *str);
int is_boal(char *str);
int is_float(char *str);
int check_num_of_point(char *str);
dataframe_shape_t df_shape(dataframe_t *dataframe);
dataframe_t *df_read_csv(const char *filename, const char *separator);
int df_write_csv(dataframe_t *dataframe, const char *filename);
dataframe_t *df_head(dataframe_t *dataframe, int nb_rows);
dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows);
void df_info(dataframe_t *dataframe);
void df_describe(dataframe_t *dataframe);
dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool (*filter_func)(void *value));
bool filter_func(void *value);
dataframe_t *df_sort(dataframe_t *dataframe, const char *column,
    bool (*sort_func)(void *value1, void *value2));
bool sort_func(void *value1, void *value2);
dataframe_t *df_groupby(dataframe_t *dataframe, const char *aggregate_by, const
    char **to_aggregate, void *(*agg_func)(void **values, int nb_values));
void *agg_func(void **values, int nb_values);
dataframe_t *df_apply(dataframe_t *dataframe, const char *column,
    void *(*apply_func)(void *value));
void *apply_func(void *value);
dataframe_t *df_to_type(dataframe_t *dataframe, const char *column,
    column_type_t downcast);
void *apply_func(void *value);
void *df_get_value(dataframe_t *dataframe, int row, const char *column);
void **df_get_values(dataframe_t *dataframe, const char *column);
void df_free(dataframe_t *dataframe);
void **df_get_unique_values(dataframe_t *dataframe, const char *column);

#endif
