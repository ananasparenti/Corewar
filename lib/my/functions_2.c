/*
** EPITECH PROJECT, 2023
** functions 2
** File description:
** miniprintf
*/

#include "my.h"

int symbol_x(va_list list)
{
    return my_mini_hexa(va_arg(list, int));
}

int symbol_upperx(va_list list)
{
    return my_hexa(va_arg(list, int));
}

int symbol_o(va_list list)
{
    return my_put_nbr_o(va_arg(list, int));
}

int symbol_f(va_list list)
{
    return my_put_float(va_arg(list, double), 6);
}

int symbol_p(va_list list)
{
    return my_pointer(va_arg(list, void *));
}
