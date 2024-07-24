/*
** EPITECH PROJECT, 2023
** unit test for flag pourcent
** File description:
** unit test for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../lib/my/my.h"

Test(my_printf, flag_pourcent, .init = cr_redirect_stdout)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}
