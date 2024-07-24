/*
** EPITECH PROJECT, 2023
** unit test for flag e
** File description:
** unit test for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../lib/my/my.h"

Test(my_printf, flag_E1, .init = cr_redirect_stdout)
{
    double n = 123.456;
    my_printf("%E", n);
    cr_assert_stdout_eq_str("1.234560E+02");
}

Test(my_printf, flag_E2, .init = cr_redirect_stdout)
{
    double a = 0.00456;
    my_printf("%E", a);
    cr_assert_stdout_eq_str("4.560000E-03");
}

Test(my_printf, flag_E3, .init = cr_redirect_stdout)
{
    double c = 12345678912.12;
    my_printf("%E", c);
    cr_assert_stdout_eq_str("1.234567E+10");
}

Test(my_printf, flag_E4, .init = cr_redirect_stdout)
{
    double d = 0.0;
    my_printf("%E", d);
    cr_assert_stdout_eq_str("0.000000E+00");
}
