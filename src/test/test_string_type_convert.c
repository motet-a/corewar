/*
** test_string_type_convert.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar  9 12:37:21 2016 antoine
** Last update Wed Mar  9 12:37:21 2016 antoine
*/

#include <stdlib.h>
#include "test.h"
#include "../libcw/string.h"
#include "../libcw/string_type.h"

static void     test_string_to_uppercase(void)
{
  char          *s;

  s = string_to_uppercase("");
  ASSERT(string_equals("", s));
  free(s);
  s = string_to_uppercase(".#$'");
  ASSERT(string_equals(".#$'", s));
  free(s);
  s = string_to_uppercase("The Quick Brown foX jumps over the Lazy dog");
  ASSERT(string_equals("THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", s));
  free(s);
}

static void     test_string_to_lowercase(void)
{
  char          *s;

  s = string_to_lowercase("");
  ASSERT(string_equals("", s));
  free(s);
  s = string_to_lowercase(".#$'");
  ASSERT(string_equals(".#$'", s));
  free(s);
  s = string_to_lowercase("The Quick Brown foX jumps over the Lazy dog");
  ASSERT(string_equals("the quick brown fox jumps over the lazy dog", s));
  free(s);
}

void            test_suite_string_type_convert(void)
{
  test_string_to_uppercase();
  test_string_to_lowercase();
}
