/*
** EPITECH PROJECT, 2023
** my_mini_hexa
** File description:
** printf
*/

#include "my.h"

int my_convert(int nb)
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

int my_mini_hexa(int nb)
{
    int cpt = 0;

    if (nb >= 16) {
        cpt += my_mini_hexa(nb / 16);
    }
    cpt += my_convert(nb);
    return cpt;
}
