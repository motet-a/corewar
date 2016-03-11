/*
** parse_and_read_int_base.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Feb 25 21:09:28 2016 antoine
** Last update Thu Feb 25 21:09:28 2016 antoine
*/

#include "parse_int.h"
#include "char_type.h"

static int      char_to_digit_alpha(char c, int base)
{
  int           digit;

  if (char_is_uppercase(c))
    digit = c - 'A';
  else if (char_is_lowercase(c))
    digit = c - 'a';
  else
    return (-1);
  digit += 10;
  if (digit < base)
    return (digit);
  else
    return (-1);
}

static int      char_to_digit(char c, int base)
{
  if (char_is_digit(c))
    {
      if (((int)c - (int)'0') < base)
        return (c - '0');
      else
        return (-1);
    }
  if (base > 10)
    return (char_to_digit_alpha(c, base));
  return (-1);
}

int             mul_and_add(unsigned long *result, int base, int digit)
{
  unsigned long r;

  r = *result;
  *result *= base;
  if (*result / base != r)
    return (-1);
  r = *result;
  *result += digit;
  if (*result - digit != r)
    return (-1);
  return (0);
}

int             parse_and_read_uint_base(const char **string_pointer,
                                         unsigned long *result_pointer,
                                         int base)
{
  int           digit;
  const char    *begin;

  begin = *string_pointer;
  *result_pointer = 0;
  while (**string_pointer)
    {
      digit = char_to_digit(**string_pointer, base);
      if (digit == -1)
        break;
      if (mul_and_add(result_pointer, base, digit))
        return (-1);
      (*string_pointer)++;
    }
  if (begin == *string_pointer)
    return (-1);
  return (0);
}

int             parse_and_read_int_base(const char **string_pointer,
                                        long *result_pointer,
                                        int base)
{
  unsigned long uint_result;
  const char    *begin;
  int           r;

  begin = *string_pointer;
  if (**string_pointer == '-')
    {
      (*string_pointer)++;
      r = parse_and_read_int_base(string_pointer, result_pointer, base);
      *result_pointer = -*result_pointer;
      return (r);
    }
  r = parse_and_read_uint_base(string_pointer, &uint_result, base);
  *result_pointer = uint_result;
  if (*result_pointer < 0)
    {
      *string_pointer = begin;
      return (-1);
    }
  return (r);
}
