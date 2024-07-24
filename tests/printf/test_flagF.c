/*
** EPITECH PROJECT, 2023
** unit test for flag e
** File description:
** unit test for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../lib/my/my.h"

Test(my_printf, flag_F1, .init = cr_redirect_stdout)
{
    my_printf("%F", 23.45);
    cr_assert_stdout_eq_str("23.449999");
}

Test(my_printf, flag_F2, .init = cr_redirect_stdout)
{
    my_printf("%F", -1.5);
    cr_assert_stdout_eq_str("-1.500000");
}

Test(my_printf, flag_F3, .init = cr_redirect_stdout)
{
    my_printf("%F", 0.0);
    cr_assert_stdout_eq_str("0.000000");
}

Test(my_printf, flag_F4, .init = cr_redirect_stdout)
{
    my_printf("%F", 0.004560);
    cr_assert_stdout_eq_str("0.004560");
}
