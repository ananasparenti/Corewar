/*
** EPITECH PROJECT, 2023
** my_putnbr_o
** File description:
** my_putnbr_octal
*/

#include "my.h"

int my_convv(int nb)
{
    int quotient = 0;
    int divisor = 8;

    quotient = nb % divisor;
    my_putchar(quotient + 48);
    return 1;
}

int my_put_nbr_o(int nb)
{
    int cpt = 0;

    if (nb >= 8) {
        cpt += my_put_nbr_o(nb / 8);
    }
    cpt += my_convv(nb);
    return cpt;
}
