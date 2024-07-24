/*
** EPITECH PROJECT, 2024
** is alpha
** File description:
** is alpha
*/

#include "my.h"

int my_isalpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}
