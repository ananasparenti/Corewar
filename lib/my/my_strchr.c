/*
** EPITECH PROJECT, 2024
** my strchr
** File description:
** strchr
*/

#include "my.h"

char *my_strchr(const char *str, int c)
{
    while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }
    if (c == '\0') {
        return (char *)str;
    }
    return NULL;
}
