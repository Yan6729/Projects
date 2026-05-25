/*
** EPITECH PROJECT, 2024
** Elementary
** File description:
** Map from file.
*/

#include "../../include/shell.h"

char *open_file(char *file)
{
    int fd = open(file, O_RDONLY | O_CREAT, 0640);
    struct stat sb;
    char *buf;
    int rd;
    int b = 0;

    if (fd == -1) {
        exit(0);
    }
    stat(file, &sb);
    b = sb.st_size;
    buf = malloc(sizeof(char) * (b + 1));
    rd = read(fd, buf, b);
    close(fd);
    buf[b] = '\0';
    return buf;
}

hist_t *copie_file(char *filename, int nb)
{
    char *buffer = open_file(filename);
    char **line = NULL;
    char **tab = NULL;
    hist_t *cmp = malloc(sizeof(hist_t));

    cmp->hist = NULL;
    if (buffer == NULL)
        return NULL;
    line = strtowordarray(buffer, "\n");
    cmp->count = count_arg(line, 0);
    for (int a = 0; line[a] != NULL; a++) {
        tab = my_split(line[a], " ");
        add_h(&cmp->hist, my_strdup(line[a],
        strlen(tab[0]) + 1), atoi(tab[0]));
    }
    free_line(buffer, NULL, line, tab);
    return cmp;
}

void write_list(char *filename, history_t *hist)
{
    FILE *file;
    history_t *tmp;

    if (filename == NULL)
        return;
    file = fopen(filename, "rw+");
    for (tmp = hist; tmp != NULL; tmp = tmp->next)
        fprintf(file, "%d %s\n", tmp->cmp->num, tmp->cmp->command);
    return;
}

char *file_histor(char *filename, char **env)
{
    char *name = my_getenv("HOME", env);
    char path[1024];
    char *file;

    if (!name)
        name = get_home_directory();
    strcpy(path, name);
    strcat(path, "/");
    strcat(path, filename);
    file = strdup(path);
    return file;
}

shell_t *rempli_struct(int ac, char **av, char **env)
{
    shell_t *strc = malloc(sizeof(shell_t));

    write_bash(".42shrc", env);
    strc->buffer = NULL;
    strc->list = copy_env(env);
    strc->tab = NULL;
    strc->num = 1;
    strc->cmp = copie_file(file_histor(".history_save", env), 0);
    strc->al = NULL;
    strc->env = env;
    strc->clone = NULL;
    return strc;
}
