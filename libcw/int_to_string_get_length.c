/*
** int_to_string_get_length.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar  4 14:27:55 2016 antoine
** Last update Fri Mar  4 14:27:55 2016 antoine
*/

#include "to_string.h"

size_t          uint_to_string_base_get_length(unsigned long integer,
                                               unsigned base)
{
  size_t        length;

  length = 1;
  while (integer >= base)
    {
      integer /= base;
      length++;
    }
  return (length);
}

size_t          int_to_string_base_get_length(long integer, unsigned base)
{
  if (integer < 0)
    return (1 + uint_to_string_base_get_length(-integer, base));
  return (uint_to_string_base_get_length(integer, base));
}

size_t          int_to_string_get_length(long integer)
{
  return (int_to_string_base_get_length(integer, 10));
}
