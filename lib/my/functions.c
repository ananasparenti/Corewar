/*
** EPITECH PROJECT, 2023
** functions
** File description:
** miniprintf
*/

#include "my.h"

int symbol_u(va_list list)
{
    return my_put_nbr_u(va_arg(list, int));
}

int symbol_i(va_list list)
{
    return my_put_nbr(va_arg(list, int));
}

int symbol_s(va_list list)
{
    return my_putstr(va_arg(list, char *));
}

int symbol_c(va_list list)
{
    return my_putchar(va_arg(list, int));
}

int symbol_d(va_list list)
{
    return my_put_nbr(va_arg(list, int));
}
