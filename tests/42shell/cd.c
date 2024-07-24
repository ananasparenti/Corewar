/*
** EPITECH PROJECT, 2023
** unit test for flag e
** File description:
** unit test for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../lib/my/my.h"
#include "../../include/my.h"

Test(first_check, full_gcorv)
{
    char **env = my_strtok("PATH=/bin:/usr/bin:./, HOME=/home, OLDPWD=/home", ",");
    linked_list_t *env = create_ll(env);

    my_printf("%s\n", mysh->env);
    mysh->line = my_strdup("ls -l");
    search_if_exist(mysh, mysh->line);
}

Test(test1, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "pwd\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}
