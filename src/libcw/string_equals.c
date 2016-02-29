/*
** string_equals.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Feb 25 22:34:55 2016 antoine
** Last update Thu Feb 25 22:34:55 2016 antoine
*/

#include "string.h"
#include "char_type.h"

int             string_equals(const char *a, const char *b)
{
  while (*a == *b)
    {
      if (!*a)
        return (1);
      a++;
      b++;
    }
  return (0);
}

int             string_equals_no_case(const char *a, const char *b)
{
  while (char_to_lowercase(*a) == char_to_lowercase(*b))
    {
      if (!*a)
        return (1);
      a++;
      b++;
    }
  return (0);
}
