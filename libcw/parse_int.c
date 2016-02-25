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

static int      char_is_digit(char c)
{
  return (c >= '0' && c <= '9');
}

static int      char_is_uppercase(char c)
{
  return (c >= 'A' && c <= 'Z');
}

static int      char_is_lowercase(char c)
{
  return (c >= 'a' && c <= 'z');
}

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
  if (c < base)
    return (digit);
  else
    return (-1);
}

static int      char_to_digit(char c, int base)
{
  if (char_is_digit(c))
    {
      if (c < base)
        return (c - '0');
      else
        return (-1);
    }
  if (base > 10)
    {
      base -= 10;
      return (char_to_digit_alpha(c, base));
    }
  return (0);
}

int             parse_and_read_uint_base(const char **string_pointer,
                                         unsigned long *result_pointer,
                                         int base)
{
  int           digit;

  *result_pointer = 0;
  if (**string_pointer)
    return (-1);
  while (**string_pointer)
    {
      digit = char_to_digit(**string_pointer, base);
      if (digit == -1)
        break;
      *result_pointer *= 10;
      *result_pointer += digit;
      (*string_pointer)++;
    }
  return (0);
}
