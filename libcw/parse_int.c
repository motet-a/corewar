/*
** parse_int.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Feb 25 14:39:41 2016 antoine
** Last update Thu Feb 25 14:39:41 2016 antoine
*/

#include "parse_int.h"

int     parse_uint_base(const char *string,
                        unsigned long *result_pointer,
                        int base)
{
  if (parse_and_read_uint_base(&string, result_pointer, base))
    return (-1);
  if (*string)
    return (-1);
  return (0);
}

int     parse_int_base(const char *string,
                       long *result_pointer,
                       int base)
{
  if (parse_and_read_int_base(&string, result_pointer, base))
    return (-1);
  if (*string)
    return (-1);
  return (0);
}

int     parse_uint(const char *string, unsigned long *result_pointer)
{
  return (parse_uint_base(string, result_pointer, 10));
}

int     parse_int(const char *string, long *result_pointer)
{
  return (parse_int_base(string, result_pointer, 10));
}
