/*
** EPITECH PROJECT, 2025
** edition
** File description:
** edition
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include "../include/shell.h"

int process_keypress(editor_t *editor)
{
    int c = read_key();

    if (c == 4) {
        printf("exit\n");
        exit(1);
    }
    if (c == 13) {
        if (editor->line_len > 0) {
            return 1;
        } else {
            return 1;
        }
    }
    key_press_interpretor(c, editor);
    return 0;
}

void char_insertion(editor_t *editor, char c)
{
    if (editor->line_len >= MAX_LINE_SIZE - 1)
        return;
    if (editor->cursor_pos < editor->line_len) {
        memmove(&editor->line[editor->cursor_pos + 1],
                &editor->line[editor->cursor_pos],
                editor->line_len - editor->cursor_pos);
    }
    editor->line[editor->cursor_pos] = c;
    editor->cursor_pos++;
    editor->line_len++;
    editor->line[editor->line_len] = '\0';
}

void backspace_char(editor_t *editor)
{
    if (editor->cursor_pos == 0 || editor->line_len == 0)
        return;
    if (editor->cursor_pos < editor->line_len) {
        memmove(&editor->line[editor->cursor_pos - 1],
                &editor->line[editor->cursor_pos],
                editor->line_len - editor->cursor_pos);
    }
    editor->cursor_pos--;
    editor->line_len--;
    editor->line[editor->line_len] = '\0';
}
