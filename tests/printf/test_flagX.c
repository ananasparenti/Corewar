/*
** EPITECH PROJECT, 2023
** unit test for flag e
** File description:
** unit test for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../lib/my/my.h"

Test(my_printf, flag_X, .init = cr_redirect_stdout)
{
    my_printf("%X", 300);
    cr_assert_stdout_eq_str("12C");
}
