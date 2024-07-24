/*
** EPITECH PROJECT, 2023
** unit test for flag e
** File description:
** unit test for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../lib/my/my.h"

Test(my_printf, flag_o, .init = cr_redirect_stdout)
{
    my_printf("%o", 300);
    cr_assert_stdout_eq_str("454");
}
