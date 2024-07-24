/*
** EPITECH PROJECT, 2023
** put_float
** File description:
** my_put_float
*/

#include "my.h"

int my_put_float(double dec, int decimal)
{
    int cpt = 0;
    int entier = (int) dec;
    int ent2 = (int) dec;

    cpt += my_put_nbr(entier);
    if (dec < 0) {
        dec *= -1;
        entier *= -1;
    }
    if (entier != 0)
        dec -= entier;
    cpt += my_putchar('.');
    for (int i = 1; i <= decimal; i++) {
        dec *= 10;
        ent2 = (int) dec;
        cpt += my_put_nbr(ent2);
        dec -= ent2;
    }
    return cpt;
}
