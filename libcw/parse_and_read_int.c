/*
** parse_and_read_int.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Feb 25 21:07:39 2016 antoine
** Last update Thu Feb 25 21:07:39 2016 antoine
*/

#include "parse_int.h"

int     parse_and_read_uint(const char **string_pointer,
                            unsigned long *result_pointer)
{
  return (parse_and_read_uint_base(string_pointer, result_pointer, 10));
}

int     parse_and_read_int(const char **string_pointer,
                           long *result_pointer)
{
  return (parse_and_read_int_base(string_pointer, result_pointer, 10));
}
