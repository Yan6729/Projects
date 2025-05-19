/*
** EPITECH PROJECT, 2025
** header_transcript.c
** File description:
** just a file
*/

#include "../B-CPE-200_op/op.h"
#include "../include/robot.h"

int swap_endians(int value)
{
    int leftmost_byte;
    int left_middle_byle;
    int right_middle_byte;
    int rightmost_byte;
    int result;

    leftmost_byte = (value & 0x000000FF) >> 0;
    left_middle_byle = (value & 0x0000FF00) >> 8;
    right_middle_byte = (value & 0x00FF0000) >> 16;
    rightmost_byte = (value & 0xFF000000) >> 24;
    leftmost_byte <<= 24;
    left_middle_byle <<= 16;
    right_middle_byte <<= 8;
    rightmost_byte <<= 0;
    result = (leftmost_byte | left_middle_byle
        | right_middle_byte | rightmost_byte);
    return result;
}

int prog_size(char **tab)
{
    int b = 0;

    for (int a = 2; tab[a] != NULL; a++) {
        b += recup(tab[a]);
    }
    return b;
}

header_t *header_transcript(char *filename)
{
    char *buffer = parsing(filename);
    char *stock = clean(buffer);
    char **tab = my_split(stock, "\t");
    header_t *val = malloc(sizeof(*val));

    val->magic = swap_endians(COREWAR_EXEC_MAGIC);
    my_strcpy(val->prog_name, my_strndup(tab[0], (my_strlen(NAME_CMD_STRING)
        + 2), my_strlen(tab[0]) - 2));
    val->prog_size = swap_endians(prog_size(tab));
    my_strcpy(val->comment, my_strndup(tab[1], (my_strlen(COMMENT_CMD_STRING)
        + 2), my_strlen(tab[1]) - 4));
    return val;
}

void transcrip(char *filename)
{
    FILE *file;
    char *str = my_strndup(filename, 0, my_strlen(filename) - 2);
    char *src = my_strcat(str, ".cor");
    header_t *struc = header_transcript(filename);

    if (src == NULL)
        return;
    file = fopen(src, "wb");
    fwrite(struc, 1, sizeof(header_t), file);
    fclose(file);
    return;
}
