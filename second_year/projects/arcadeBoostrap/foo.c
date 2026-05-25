/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** foo
*/

#include <stdio.h>

__attribute__((constructor))
void init(void)
{
    printf("[libfoo] Loading foo library...");
}

__attribute__((destructor))
void close(void)
{
    printf("[libfoo] foo closing...");
}

void myEntryPoint(void)
{
    printf("[libfoo] Entry point for foo!");
}