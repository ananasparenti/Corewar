/*
** EPITECH PROJECT, 2023
** add_ptr
** File description:
** add_ptr
*/

#include "my.h"

int my_connv(long long unsigned nb)
{
    int quotient = 0;
    int divisor = 16;

    quotient = nb % divisor;
    if (quotient >= 10) {
        my_putchar(quotient + 87);
        return 1;
    }
    my_putchar(quotient + 48);
    return 1;
}

int my_hexia(long long unsigned nb)
{
    int cpt = 0;

    if (nb >= 16) {
        cpt += my_hexia(nb / 16);
    }
    cpt += my_connv(nb);
    return cpt;
}

int my_pointer(int *ptr)
{
    int cpt;

    my_putstr("0x");
    cpt = my_hexia((long long unsigned)ptr);
    return cpt;
}
