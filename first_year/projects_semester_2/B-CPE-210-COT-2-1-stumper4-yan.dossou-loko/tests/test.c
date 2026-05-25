/*
** EPITECH PROJECT, 2025
** Duo stumper
** File description:
** tree.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(pos, pos_test, .init = redirect_all_std)
{
    char *alph = "Papa maman enfant";
    char **tab = str_array(alph, ' ');
    int a = tab_len(tab);

    cr_assert_eq(a, 3);
}

Test(pos2, pos_test, .init = redirect_all_std)
{
    char *alph = "Papa\nmaman\nenfant";
    char **tab = str_array(alph, '\n');
    int a = tab_len(tab);

    cr_assert_eq(a, 3); 
}
