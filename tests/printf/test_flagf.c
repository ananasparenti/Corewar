/*
** EPITECH PROJECT, 2023
** unit test for flag e
** File description:
** unit test for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../lib/my/my.h"

Test(my_printf, flag_f1, .init = cr_redirect_stdout)
{
    my_printf("%f", 23.45);
    cr_assert_stdout_eq_str("23.449999");
}

Test(my_printf, flag_f2, .init = cr_redirect_stdout)
{
    my_printf("%f", -1.5);
    cr_assert_stdout_eq_str("-1.500000");
}

Test(my_printf, flag_f3, .init = cr_redirect_stdout)
{
    my_printf("%f", 0.0);
    cr_assert_stdout_eq_str("0.000000");
}

Test(my_printf, flag_f4, .init = cr_redirect_stdout)
{
    my_printf("%f", 0.004560);
    cr_assert_stdout_eq_str("0.004560");
}
