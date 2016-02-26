/*
** test_string_find.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Feb 25 22:53:12 2016 antoine
** Last update Thu Feb 25 22:53:12 2016 antoine
*/

#include <stdlib.h>
#include "test.h"
#include "../libcw/string.h"

static void     test_string_find(void)
{
  const char    *s;

  ASSERT(string_find("", "") == NULL);
  ASSERT(string_find("", "foo") == NULL);
  ASSERT(string_find("bar", "foo") == NULL);
  s = "bar";
  ASSERT(string_find(s, "") == s);
  s = "bar";
  ASSERT(string_find(s, "a") == s + 1);
  s = "bar";
  ASSERT(string_find(s, "ar") == s + 1);
  ASSERT(string_find("bar", "arlol") == NULL);
  s = "bar";
  ASSERT(string_find(s, "bar") == s);
}

static void     test_string_find_no_case(void)
{
  const char    *s;

  s = "bar";
  ASSERT(string_find_no_case(s, "bar") == s);
  s = "bar";
  ASSERT(string_find_no_case(s, "bAr") == s);
  s = "BAR";
  ASSERT(string_find_no_case(s, "BAR") == s);
}

void            test_suite_string_find(void)
{
  test_string_find();
  test_string_find_no_case();
}
