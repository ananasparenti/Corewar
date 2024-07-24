/*
** EPITECH PROJECT, 2023
** unit test for flag e
** File description:
** unit test for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../lib/my/my.h"

Test(my_strcpy, copy_string_correctly)
{
    char src[] = "Hello, world!";
    char dest[20];

    my_strcpy(dest, src);
    cr_assert_str_eq(dest, src);
}

Test(my_strlen, calculate_string_length)
{
    char str[] = "Hello, world!";
    int length = my_strlen(str);
    cr_assert_eq(length, 13);
}

Test(my_str_tok, split_string_into_words)
{
    char str[] = "Hello, world!";
    char **tab = my_str_tok(str, " ,!");
    cr_assert_str_eq(tab[0], "Hello");
    cr_assert_str_eq(tab[1], "world");
    cr_assert_null(tab[2]);
}
