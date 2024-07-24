/*
** EPITECH PROJECT, 2023
** my_hexa
** File description:
** printf
*/

#include "my.h"

int my_conv(int nb)
{
    int quotient;
    int divisor = 16;

    quotient = nb % divisor;
    if (quotient >= 10) {
        my_putchar(quotient + 55);
        return 1;
    }
    my_putchar(quotient + 48);
    return 1;
}

int my_hexa(int nb)
{
    int cpt = 0;

    if (nb >= 16) {
        cpt += my_hexa(nb / 16);
    }
    cpt += my_conv(nb);
    return cpt;
}
