/*
** EPITECH PROJECT, 2024
** delete space from string
** File description:
** for lib
*/

#include "my.h"

char *trim_space(char *str)
{
    int i = 0;
    int j = 0;
    char *new_str = malloc(sizeof(char) * my_strlen(str) + 1);

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            new_str[j] = str[i];
            j++;
        }
        i++;
    }
    new_str[j] = '\0';
    return new_str;
}

char *del_end_space(char *str)
{
    int i = my_strlen(str) - 1;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
        str[i] = '\0';
        i--;
    }
    return str;
}
