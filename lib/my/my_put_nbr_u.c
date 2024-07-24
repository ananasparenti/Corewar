/*
** EPITECH PROJECT, 2023
** my_put_nbr_u
** File description:
** printf
*/

#include "my.h"

int my_put_nbr_u(unsigned int nb)
{
    int cpt = 1;

    my_putchar((nb % 10) + 48);
    cpt++;
    return cpt;
}
