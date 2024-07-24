/*
** EPITECH PROJECT, 2023
** len of string
** File description:
** sokoban
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i]) {
        i++;
    }
    return (i);
}
