/*
** test_parse_int.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Feb 24 21:28:06 2016 antoine
** Last update Wed Feb 24 21:28:06 2016 antoine
*/

#include "test.h"
#include "../libcw/parse_int.h"

static void     test_parse_and_read_uint_base(void)
{
  const char    *string;
  unsigned long n;

  string = "";
  ASSERT(parse_and_read_uint_base(&string, &n, 10) == -1);
  string = "+1";
  ASSERT(parse_and_read_uint_base(&string, &n, 10) == -1);
  string = "hello";
  ASSERT(parse_and_read_uint_base(&string, &n, 10) == -1);
  string = "123a";
  ASSERT(parse_and_read_uint_base(&string, &n, 10) == 0);
  ASSERT(*string == 'a');
  ASSERT(n == 123);
  string = "012";
  ASSERT(parse_and_read_uint_base(&string, &n, 2) == 0);
  ASSERT(n == 1);
  string = "CafeBAbE";
  ASSERT(parse_and_read_uint_base(&string, &n, 16) == 0);
  ASSERT(!*string);
  ASSERT(n == 0xcafebabe);
  string = "f0F1";
  ASSERT(parse_and_read_uint_base(&string, &n, 16) == 0);
  ASSERT(!*string);
  ASSERT(n == 0xf0f1);
}

static void     test_parse_and_read_int_base(void)
{
  const char    *string;
  long          n;

  string = "";
  ASSERT(parse_and_read_int_base(&string, &n, 10) == 1);
  string = "-01234a";
  ASSERT(parse_and_read_int_base(&string, &n, 10) == 0);
  ASSERT(n == -01234);
  ASSERT(*string == 'a');
  string = "+123";
  ASSERT(parse_and_read_int_base(&string, &n, 10) == -1);
  string = "--123";
  ASSERT(parse_and_read_int_base(&string, &n, 10) == 0);
  ASSERT(n == 123);
  string = "---123";
  ASSERT(parse_and_read_int_base(&string, &n, 10) == 0);
  ASSERT(n == -123);
}

static void     test_parse_uint(void)
{
  unsigned long n;

  ASSERT(parse_uint("", &n) == -1);
  ASSERT(parse_uint("+123", &n) == -1);
  ASSERT(parse_uint("-123", &n) == -1);
  ASSERT(parse_uint("a", &n) == -1);
  ASSERT(parse_uint("001234abcdlol", &n) == -1);
  ASSERT(parse_uint("001234", &n) == 0);
  ASSERT(n == 1234);
}

static void     test_parse_int(void)
{
  long          n;

  ASSERT(parse_int("", &n) == -1);
  ASSERT(parse_int("pichou nik ta mer", &n) == -1);
  ASSERT(parse_int("123", &n) == 0);
  ASSERT(n == 123);
  ASSERT(parse_int("123a", &n) == -1);
  ASSERT(parse_int("-123", &n) == 0);
  ASSERT(n == -123);
  ASSERT(parse_int("--123", &n) == 0);
  ASSERT(n == 123);
  ASSERT(parse_int("--123", &n) == 0);
  ASSERT(n == 123);
}

void            test_suite_parse_int(void)
{
  test_parse_and_read_uint_base();
  test_parse_and_read_int_base();
  test_parse_uint();
  test_parse_int();
}
