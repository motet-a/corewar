/*
** test_suites.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 11 14:18:14 2016 antoine
** Last update Fri Mar 11 14:18:14 2016 antoine
*/

#include "test.h"

void    run_vm_suites(void)
{
  /* TODO: Put a lot of amazing tests right here */
}

void    run_asm_suites(void)
{
  test_suite_token_list();
  test_suite_lexer();
}

void    run_libcw_suites(void)
{
  test_suite_memory();
  test_suite_parse_int();
  test_suite_string_concat();
  test_suite_string_find();
  test_suite_string_find_char();
  test_suite_int_to_string();
  test_suite_string_type();
  test_suite_string_type_convert();
}
