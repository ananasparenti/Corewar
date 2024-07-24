/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** for lib
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        while (to_find[j] != '\0' && str[i + j] == to_find[j]) {
            j++;
        }
        if (to_find[j] == '\0') {
            return &str[i];
        }
    }
    return NULL;
}
