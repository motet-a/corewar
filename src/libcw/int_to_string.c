/*
** int_to_string.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar  4 13:12:22 2016 antoine
** Last update Fri Mar  4 13:12:22 2016 antoine
*/

#include "to_string.h"

int             uint_to_string_base(unsigned long integer,
                                    char *buffer,
                                    size_t max_size,
                                    unsigned base)
{
  size_t        i;
  unsigned      digit;

  i = uint_to_string_base_get_length(integer, base);
  if (i >= max_size)
    return (-1);
  buffer[i] = '\0';
  while (i-- > 0)
    {
      digit = integer % base;
      buffer[i] = digit < 10 ? digit + '0' : digit - 10 + 'a';
      integer /= base;
    }
  return (0);
}

int             int_to_string_base(long integer,
                                   char *buffer,
                                   size_t max_size,
                                   unsigned base)
{
  if (max_size <= 1)
    return (-1);
  if (integer < 0)
    {
      *buffer = '-';
      return (uint_to_string_base(-integer, buffer + 1, max_size - 1, base));
    }
  return (uint_to_string_base(integer, buffer, max_size, base));
}
