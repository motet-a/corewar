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

void            test_parse_int(void)
{
  const char    *string;
  unsigned long n;

  string = "";
  ASSERT(parse_and_read_uint_base(&string, &n, 10) == -1);
}
