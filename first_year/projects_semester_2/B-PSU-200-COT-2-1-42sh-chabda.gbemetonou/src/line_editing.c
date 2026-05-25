/*
** EPITECH PROJECT, 2025
** line edition
** File description:
** line edition
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include "../include/shell.h"

editor_t *init_line_editor(hist_t *history)
{
    editor_t *editor = malloc(sizeof(editor_t));

    if (!editor)
        return NULL;
    editor->line = malloc(MAX_LINE_SIZE);
    if (!editor->line) {
        free(editor);
        return NULL;
    }
    editor->line[0] = '\0';
    editor->cursor_pos = 0;
    editor->line_len = 0;
    editor->current_history = NULL;
    editor->history_data = history;
    return editor;
}

int return_key_process(char *seq, char c)
{
    if (seq[0] == '[') {
        if (seq[1] == 'A')
            return 200;
        if (seq[1] == 'B')
            return 201;
        if (seq[1] == 'C')
            return 202;
        if (seq[1] == 'D')
            return 203;
        return '\x1b';
    } else {
        return c;
    }
}

int read_key()
{
    int reader;
    char c;
    char seq[3];

    reader = read(STDIN_FILENO, &c, 1);
    while (reader != 1) {
        if (reader == -1)
            exit(84);
        reader = read(STDIN_FILENO, &c, 1);
    }
    if (c == '\x1b') {
        if (read(STDIN_FILENO, &seq[0], 1) != 1)
            return '\x1b';
        if (read(STDIN_FILENO, &seq[1], 1) != 1)
            return '\x1b';
        return_key_process(seq, c);
    }
}

int key_press_interpretor(int c, editor_t *editor)
{
    if (c == 127) {
        backspace_char(editor);
        return 0;
    }
    if (c == 202) {
        if (editor->cursor_pos < editor->line_len)
            editor->cursor_pos++;
        return 0;
    }
    if (c == 203) {
        if (editor->cursor_pos > 0)
            editor->cursor_pos--;
        return 0;
    }
    if (!iscntrl(c))
        char_insertion(editor, c);
}

void refresh_line(editor_t *editor)
{
    const char *prompt = ": ̗̀➛ ";
    int prompt_len = 4;
    char cursor_cmd[32];
    int cursor_pos;

    write(STDOUT_FILENO, "\r\033[2K", 5);
    write(STDOUT_FILENO, "\033[3;91m", 7);
    write(STDOUT_FILENO, prompt, strlen(prompt));
    write(STDOUT_FILENO, "\033[0m", 4);
    write(STDOUT_FILENO, editor->line, editor->line_len);
    cursor_pos = prompt_len + editor->cursor_pos;
    snprintf(cursor_cmd, sizeof(cursor_cmd), "\r\033[%dC", cursor_pos);
    write(STDOUT_FILENO, cursor_cmd, strlen(cursor_cmd));
}
