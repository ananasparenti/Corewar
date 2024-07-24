/*
** EPITECH PROJECT, 2023
** unit test for flag e
** File description:
** unit test for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../lib/my/my.h"

Test(my_strcat, concatenates_two_strings)
{
    char dest[50] = "Hello";
    char src[] = " World!";
    char expected[] = "Hello World!";
    
    my_strcat(dest, src);
    cr_assert_str_eq(dest, expected);
}

Test(my_putstr, prints_string_to_stdout)
{
    char str[] = "Hello, world!";
    cr_redirect_stdout();
    my_putstr(str);
    cr_assert_stdout_eq_str(str);
}

Test(my_strcmp, compares_two_strings)
{
    char str1[] = "Hello";
    char str2[] = "Hello";
    int result = my_strcmp(str1, str2);
    cr_assert_eq(result, 0);
    
    char str3[] = "Hello";
    char str4[] = "World";
    result = my_strcmp(str3, str4);
    cr_assert_lt(result, 0);
    
    char str5[] = "World";
    char str6[] = "Hello";
    result = my_strcmp(str5, str6);
    cr_assert_gt(result, 0);
}
 Test(my_getnbr, converts_string_to_int)
{
    char str[] = "123";
    int result = my_getnbr(str);
    cr_assert_eq(result, 123);
    
    char str2[] = "-123";
    result = my_getnbr(str2);
    cr_assert_eq(result, -123);
    
    char str3[] = "123abc";
    result = my_getnbr(str3);
    cr_assert_eq(result, 123);
    
    char str4[] = "abc123";
    result = my_getnbr(str4);
    cr_assert_eq(result, 0);
}
