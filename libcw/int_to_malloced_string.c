/*
** int_to_malloced_string.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar  4 13:52:46 2016 antoine
** Last update Fri Mar  4 13:52:46 2016 antoine
*/

#include <stdlib.h>
#include "to_string.h"

char            *int_to_malloced_string_base(long integer, unsigned base)
{
  char          *s;
  size_t        max_length;

  max_length = int_to_string_base_get_length(integer, base) + 1;
  s = malloc(max_length);
  if (!s)
    return (NULL);
  if (int_to_string_base(integer, s, max_length, base))
    {
      free(s);
      return (NULL);
    }
  return (s);
}

char    *int_to_malloced_string(long integer)
{
  return (int_to_malloced_string_base(integer, 10));
}
