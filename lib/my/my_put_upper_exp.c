/*
** EPITECH PROJECT, 2023
** my_put_exp
** File description:
** fonction my_put_exp
*/

#include "my.h"

int my_eechec_exp(double n, int cpt, int i)
{
    cpt += my_put_float(n, 6);
    cpt += my_putstr("E+");
    if (i < 10) {
        cpt += my_putchar('0');
    }
    cpt += my_put_nbr(i);
    return cpt;
}

int my_under_upper_exp(double n, int cpt)
{
    int i = 0;

    if (n > 0) {
        while (n < 1) {
            n = n * 10;
            i++;
        }
    }
    cpt += my_put_float(n, 6);
    cpt += my_putstr("E-");
    if (i < 10) {
        cpt += my_putchar('0');
    }
    cpt += my_put_nbr(i);
    return cpt;
}

int my_put_upper_exp(double n)
{
    int cpt = 0;
    int i = 0;

    if (n == 0.0) {
        cpt += my_putstr("0.000000E+00");
        return cpt;
    }
    if (n > 9) {
        while (n >= 10) {
            n = n / 10;
            i++;
        }
        cpt += my_eechec_exp(n, 0, i);
    }
    if (n < 1) {
        cpt = my_under_upper_exp(n, cpt);
    }
    return cpt;
}
