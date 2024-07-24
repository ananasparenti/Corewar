/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** display a char for hunter
*/

#include "my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}
