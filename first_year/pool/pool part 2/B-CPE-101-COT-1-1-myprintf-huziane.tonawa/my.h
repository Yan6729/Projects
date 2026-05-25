/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/
#include <stdarg.h>
#ifndef MY_BANANA
    #define MY_BANANA
int formatage2(const char *format, va_list list, int x);
int my_convert_min2(unsigned long nb, int base);
int my_convert_min(unsigned int nb, int base);
int my_convert_maj(unsigned int nb, int base);
int formatage1(const char *format, va_list list, int x);
double my_putfloat(double nb);
double my_putfloat2(float nb, int s);
float my_flag_e(float nb);
float my_flag_E(float nb);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_putchar(char c);
int condition1(const char *format, va_list list, int x);
int condition2(const char *format, va_list list, int x);
int condition3(const char *format, va_list list, int x);
int my_printf(const char *format, ...);
int my_swap(int *h, int *s);
double my_first_float_condition(int x, int i, int stock);
double my_second_float_condition(double nb);

#endif
