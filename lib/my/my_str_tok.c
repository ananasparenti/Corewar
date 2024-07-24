/*
** EPITECH PROJECT, 2024
** my_str_to_word_array_second
** File description:
** for minishell1
*/

#include "my.h"

char **my_str_tok(char *str, char *delim)
{
    char **tab;
    char *token;
    int nb = 0;
    char *tmp = my_strdup(str);

    tab = malloc(sizeof(char *) * (my_strlen(str) + 1));
    token = strtok(tmp, delim);
    while (token != NULL) {
        tab[nb] = my_strdup(token);
        nb++;
        token = strtok(NULL, delim);
    }
    tab[nb] = NULL;
    return tab;
    free(tab);
}
