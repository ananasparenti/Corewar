/*
** EPITECH PROJECT, 2023
** function
** File description:
** my_put_nbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int cpt = 1;

    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
        cpt++;
    }
    if (nb >= 10) {
        cpt += my_put_nbr(nb / 10);
    }
    if (nb == -2147483648) {
        cpt += my_putstr("2147483648");
    }
    if (nb != -2147483648) {
        my_putchar((nb % 10) + 48);
    }
    return cpt;
}
