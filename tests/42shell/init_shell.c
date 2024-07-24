/*
** EPITECH PROJECT, 2024
** init shell
** File description:
** for 42sh
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../lib/my/my.h"
#include "../../include/my.h"

typedef struct mysh_s {
    char *line;
    char **env;
} mysh_t;

linked_list_t *init_shell(char **env)
{
    linked_list_t *init_shell = malloc(sizeof(linked_list_t));
    
    setenv("PATH", "/bin:/usr/bin", 1);
    setenv("PWD", "/home", 1);
    setenv("OLDPWD", "/home", 1);
    return init_shell;
}
