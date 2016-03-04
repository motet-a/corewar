/*
** test_int_to_string.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar  4 14:02:12 2016 antoine
** Last update Fri Mar  4 14:02:12 2016 antoine
*/

#include <stdlib.h>
#include "test.h"
#include "../libcw/to_string.h"
#include "../libcw/string.h"

static void     test_int_to_string_get_length(void)
{
  ASSERT(int_to_string_get_length(0) == 1);
  ASSERT(int_to_string_get_length(-1) == 2);
  ASSERT(int_to_string_get_length(-9) == 2);
  ASSERT(int_to_string_get_length(-10) == 3);
  ASSERT(int_to_string_get_length(9) == 1);
  ASSERT(int_to_string_get_length(10) == 2);
  ASSERT(int_to_string_get_length(999) == 3);
  ASSERT(int_to_string_get_length(1000) == 4);
}

static void     test_int_to_string_base(void)
{
  char          buffer[100];

  ASSERT(int_to_string_base(0, buffer, 2, 10) == 0);
  ASSERT(string_equals(buffer, "0"));
  ASSERT(int_to_string_base(0, buffer, 1, 10) == -1);
  ASSERT(int_to_string_base(123, buffer, 3, 10) == -1);
  ASSERT(int_to_string_base(123, buffer, 4, 10) == 0);
  ASSERT(string_equals(buffer, "123"));
  ASSERT(int_to_string_base(0xdeadbeef, buffer, 8, 16) == -1);
  ASSERT(int_to_string_base(0xdeadbeef, buffer, 9, 16) == 0);
  ASSERT(string_equals(buffer, "deadbeef"));
}

static void     test_int_to_malloced_string_base(void)
{
  char          *s;

  s = int_to_malloced_string_base(0xdeadbeef, 16);
  ASSERT(s != NULL);
  ASSERT(string_equals("deadbeef", s));
  free(s);
  s = int_to_malloced_string_base(0xff, 2);
  ASSERT(s != NULL);
  ASSERT(string_equals("1111" "1111", s));
  free(s);
}

void    test_suite_int_to_string(void)
{
  test_int_to_string_get_length();
  test_int_to_string_base();
  test_int_to_malloced_string_base();
}
