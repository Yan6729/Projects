#include "../include/shell.h"

int is_delim(char c, const char *delim) {
    for (int i = 0; delim[i] != '\0'; i++) {
        if (c == delim[i])
            return 1;
    }
    return 0;
}

tab_t *create_new(const char *word, int is_sep, int len) {
    tab_t *node = malloc(sizeof(tab_t));
    if (!node)
        return NULL;
    node->word = strndup(word, len);
    node->is_sep = is_sep;
    node->next = NULL;
    return node;
}

void add_tab(tab_t **list, tab_t *new_node) {
    if (!*list) {
        *list = new_node;
        return;
    }
    tab_t *tmp = *list;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_node;
}

void decoup_tab(ind_t *cmp, char *str, const char *delim)
{
    if (str[cmp->i] == '\'' || str[cmp->i] == '"') {
        cmp->is_sep = 1;
        cmp->quote = str[cmp->i];
        cmp->i++;
        cmp->start = cmp->i;
        while (str[cmp->i] && str[cmp->i] != cmp->quote)
            cmp->i++;
    } else {
        cmp->quote = 0;
        cmp->start = cmp->i;
        while (str[cmp->i] && !is_delim(str[cmp->i], delim)
        && str[cmp->i] != '\'' && str[cmp->i] != '"')
            cmp->i++;
    }
}

tab_t *str_to_list(char *str, const char *delim) {
    ind_t cmp = {0};

    while (str[cmp.i]) {
        cmp.is_sep = 0;
        while (str[cmp.i] && is_delim(str[cmp.i], delim)) {
            cmp.i++;
        }
        if (!str[cmp.i])
            break;
        decoup_tab(&cmp, str, delim);
        cmp.len = cmp.i - cmp.start;
        if (cmp.len > 0)
            add_tab(&cmp.list, create_new(&str[cmp.start],
            cmp.is_sep, cmp.len));
        if (cmp.quote && str[cmp.i] == cmp.quote)
            cmp.i++;
    }
    return cmp.list;
}

void free_litb(tab_t *list) {
    tab_t *tmp;
    while (list) {
        tmp = list->next;
        free(list->word);
        free(list);
        list = tmp;
    }
}

int size_lis(tab_t **list)
{
    int size = 0;
    tab_t *tmp = NULL;

    for (tmp = *list; tmp != NULL; tmp = tmp->next) {
        size++;
    }
    return size;
}

char **my_split(char *str, const char *delim)
{
    tab_t *list = str_to_list(str, delim);
    tab_t *tmp = NULL;
    int a = 0;
    int size = size_lis(&list);
    char **tab = malloc(sizeof(char *) * (size + 1));

    for (tmp = list; tmp != NULL; tmp = tmp->next) {
        tab[a] = tmp->word;
        a++;
    }
    tab[a] = NULL;
    for (list; list != NULL; list = list->next) {
        printf("%s -> %d\n", list->word, list->is_sep);
    }
    free_litb(list);
}

int main(int ac, char **av) {
    my_split(av[1], av[2]);
    return 0;
}
