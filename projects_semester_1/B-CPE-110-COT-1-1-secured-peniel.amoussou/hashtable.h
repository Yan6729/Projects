/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <ncurses.h>
    #include <time.h>

typedef struct h_list_s {
    int hash_num;
    char *val;
    struct h_list_s *next;
} content_t;

typedef struct hashtable_s {
    int len;
    content_t **head;
    int (*hash)(char *, int);
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destro table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strdup(char const *src);
void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
void limit_breaker(void);
int convert(char *ch);
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

#endif /* HASHTABLE_H */
