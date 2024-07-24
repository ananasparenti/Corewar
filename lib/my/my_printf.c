/*
** EPITECH PROJECT, 2023
** project printf
** File description:
** printf
*/

#include "my.h"

int symbol(char format, va_list list)
{
    int x = 0;
    int nb = 0;
    char *flags = "dsciuXxofFpeEg";
    int (*variable[13])(va_list) = {&symbol_d, &symbol_s, &symbol_c, &symbol_i,
        &symbol_u, &symbol_upperx, &symbol_x, &symbol_o, &symbol_f,
        &symbol_upperf, &symbol_p, &symbol_e, &symbol_uppere};

    while (flags[x] != '\0') {
        if (flags[x] == format) {
            nb = (*variable[x])(list);
            return nb;
        }
        x++;
    }
    nb = my_putchar('%');
    return nb;
}

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;
    int nb = 0;

    va_start(list, *format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            nb = nb + symbol(format[i], list);
        } else {
            my_putchar(format[i]);
            nb++;
        }
        i++;
    }
    va_end(list);
    return nb;
}
