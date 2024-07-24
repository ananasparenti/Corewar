/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef MY_H
    #define MY_H

int my_printf(const char *format, ...);

int my_getnbr(const char *str);
char *trim_space(char *str);
char *my_strstr(char *str, char const *to_find);
char *my_strcpy(char *dest, char const *src);
char **my_str_tok(char *str, char *delim);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char *str);
int my_isalpha(char c);
char **my_str_to_word_array(char *str, int *nb);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strchr(const char *str, int c);
int my_put_nbr_u(unsigned int nb);
int my_hexa(int nb);
int my_mini_hexa(int nb);
int my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_put_nbr_o(int nb);
int my_put_float(double dec, int decimal);
int my_connv(long long unsigned nb);
int my_put_exp(double n);
int my_hexia(long long unsigned nb);
int my_pointer(int *ptr);
int my_put_exp(double n);
int my_put_upper_exp(double n);
int my_put_upper_float(double dec, int decimal);

int symbol_upperx(va_list list);
int symbol_uppere(va_list list);
int symbol_upperf(va_list list);
int symbol_e(va_list list);
int symbol_p(va_list list);
int symbol_f(va_list list);
int symbol_o(va_list list);
int symbol_x(va_list list);
int symbol_u(va_list list);
int symbol_d(va_list list);
int symbol_s(va_list list);
int symbol_c(va_list list);
int symbol_i(va_list list);

void file_reader(char *file_name);

#endif
