/*
** EPITECH PROJECT, 2023
** unit test for flag e
** File description:
** unit test for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../lib/my/my.h"

Test(my_printf, flag_p, .init = cr_redirect_stdout)
{
    int k = 17;
    int *p = &k;
    
    my_printf("%p", p);
    cr_assert(printf("%p", p));
}
