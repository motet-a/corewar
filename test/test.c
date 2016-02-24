/*
** test.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Feb 23 00:12:28 2016 antoine
** Last update Tue Feb 23 00:12:28 2016 antoine
*/

#include <stdlib.h>
#include "libcw/print.h"
#include "test.h"

void            fail_impl(const char *position)
{
  print_string_err(position);
  print_string_err(": Test failed");
  print_string_err("\n");
  exit(1);
}

void            assert_impl(int a, const char *position)
{
  if (!a)
    fail_impl(position);
}

int             main()
{
  ASSERT(0);
  return (0);
}
