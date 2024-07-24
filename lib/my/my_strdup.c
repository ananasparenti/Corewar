/*
** EPITECH PROJECT, 2023
** lib my_strdup
** File description:
** for malloc
*/

#include "my.h"

char *my_strdup(char *str)
{
    int i = 0;
    char *new_str = malloc(sizeof(char) * my_strlen(str) + 1);

    while (str[i] != '\0') {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return new_str;
}
