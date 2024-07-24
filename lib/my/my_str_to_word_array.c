/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** lib
*/

#include "../../include/my.h"

char **my_str_to_word_array(char *str, int *nb)
{
    char **tab = malloc(sizeof(char *) * (my_strlen(str) + 1));
    char *token = strtok(str, " \t");

    *nb = 0;
    while (token != NULL) {
        tab[*nb] = my_strdup(token);
        (*nb)++;
        token = strtok(NULL, " \t");
    }
    return tab;
    free(tab);
}
