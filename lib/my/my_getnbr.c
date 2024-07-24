/*
** EPITECH PROJECT, 2023
** my_mini_hexa
** File description:
** printf
*/

#include "my.h"

int my_getnbr(const char *str)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            break;
        }
        i++;
    }
    result *= sign;
    return result;
}
