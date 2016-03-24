/*
** test_string_type.c for  in /Users/westery/Documents/tek1/CPE/corewar/src/test/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Wed Mar  9 11:11:00 2016 Valentin Pichard
** Last update Wed Mar  9 19:15:19 2016 Valentin Pichard
*/

#include <stdlib.h>
#include "test.h"
#include "../libcw/string_type.h"

static void     test_string_is_uppercase(void)
{
  ASSERT(string_is_uppercase("aaaaa") == 0);
  ASSERT(string_is_uppercase("aAaaa") == 0);
  ASSERT(string_is_uppercase("ZERTYUIKB") == 1);
  ASSERT(string_is_uppercase("aaaaa9") == 0);
  ASSERT(string_is_uppercase("aaaaB") == 0);
  ASSERT(string_is_uppercase("A") == 1);
  ASSERT(string_is_uppercase("") == 0);
}

static void     test_string_is_lowercase(void)
{
  ASSERT(string_is_lowercase("aaaaa") == 1);
  ASSERT(string_is_lowercase("aAaaa") == 0);
  ASSERT(string_is_lowercase("ZERTYUIKB") == 0);
  ASSERT(string_is_lowercase("aaaaa9") == 0);
  ASSERT(string_is_lowercase("aaaaB") == 0);
  ASSERT(string_is_lowercase("a") == 1);
  ASSERT(string_is_uppercase("") == 0);
}

static void     test_string_is_digit(void)
{
  ASSERT(string_is_digit("a8aaa") == 0);
  ASSERT(string_is_digit("aaaaa9") == 0);
  ASSERT(string_is_digit("567892") == 1);
  ASSERT(string_is_digit("8") == 1);
  ASSERT(string_is_digit("") == 0);
}

static void     test_string_is_alphanumeric(void)
{
  ASSERT(string_is_letter("aaaaa") == 1);
  ASSERT(string_is_letter(".zbehczi") == 0);
  ASSERT(string_is_letter("a") == 1);
  ASSERT(string_is_letter("7") == 0);
  ASSERT(string_is_letter("A8aaa") == 0);
  ASSERT(string_is_letter("jzaHHUaha") == 1);
  ASSERT(string_is_letter("aoozko") == 1);
  ASSERT(string_is_letter("8ahha") == 0);
  ASSERT(string_is_letter("") == 0);
  ASSERT(string_is_alphanumeric("09") == 1);
  ASSERT(string_is_alphanumeric("azAZ") == 1);
  ASSERT(string_is_alphanumeric("09azAZ") == 1);
  ASSERT(string_is_alphanumeric("./~`") == 0);
  ASSERT(string_is_alphanumeric("09.azAZ") == 0);
  ASSERT(string_is_alphanumeric("") == 0);
}

void            test_suite_string_type(void)
{
  test_string_is_digit();
  test_string_is_uppercase();
  test_string_is_lowercase();
  test_string_is_alphanumeric();
}
