/*
** EPITECH PROJECT, 2023
** unit test for flag e
** File description:
** unit test for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../lib/my/my.h"

Test(my_printf, flag_s1, .init = cr_redirect_stdout)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, flag_s2, .init = cr_redirect_stdout)
{
    my_printf("%s", "ha, ha + ha");
    cr_assert_stdout_eq_str("ha, ha + ha");
}
