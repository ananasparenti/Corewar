/*
** EPITECH PROJECT, 2023
** function 3
** File description:
** for return
*/

#include "my.h"

int symbol_e(va_list list)
{
    return my_put_exp(va_arg(list, double));
}

int symbol_uppere(va_list list)
{
    return my_put_upper_exp(va_arg(list, double));
}

int symbol_upperf(va_list list)
{
    return my_put_upper_float(va_arg(list, double), 6);
}
