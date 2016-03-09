/*
** test_string_type_extend.c for  in /Users/westery/Documents/tek1/CPE/corewar/src/test/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Wed Mar  9 18:50:00 2016 Valentin Pichard
** Last update Wed Mar  9 19:04:20 2016 Valentin Pichard
*/

#include <stdlib.h>
#include "test.h"
#include "../libcw/string_type.h"

static void     test_string_is_letter(void)
{
  ASSERT(string_is_lowercase("aaaaa") == 1);
  ASSERT(string_is_lowercase("a8aaaB") == 0);
  ASSERT(string_is_uppercase(".zbehczi") == 0);
  ASSERT(string_is_lowercase("a") == 1);
  ASSERT(string_is_uppercase("") == 0);
  ASSERT(string_is_uppercase("7") == 0);
}

static void     test_string_to_uppercase(void)
{
  ASSERT(string_to_uppercase("a8aaa") == "A8AAA");
  ASSERT(string_to_uppercase("aaaaa9") == "AAAAA9");
  ASSERT(string_to_uppercase("567892") == "567892");
  ASSERT(string_to_uppercase("8") == "8");
  ASSERT(string_to_uppercase("") == "");
  ASSERT(string_to_uppercase("BHEAK") == "BHEAK");
}

static void     test_string_to_lowercase(void)
{
  ASSERT(string_to_lowercase("HHAIHUZ8") == "hhaihuz8");
  ASSERT(string_to_lowercase("AAAAA9") == "aaaaa9");
  ASSERT(string_to_lowercase("567892") == "567892");
  ASSERT(string_to_lowercase("8") == "8");
  ASSERT(string_to_lowercase("") == "");
  ASSERT(string_to_lowercase("abcde") == "abcde");
}

void            test_suite_string_type_extend(void)
{
  test_string_is_letter();
  test_string_to_lowercase();
  test_string_to_uppercase();
}
