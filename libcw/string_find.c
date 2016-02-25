/*
** string_find.c for corewar in /home/antoine/corewar/libcw
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  Thu Feb 25 21:26:28 2016 Antoine Baudrand
** Last update Thu Feb 25 22:19:41 2016 Antoine Baudrand
*/

#include <stdlib.h>
#include "str.h"
#include "char_type.h"

int             string_starts_with(const char *string, const char *begin)
{
  while (*string && *string == *begin)
    {
      string++;
      begin++;
    }
  return (!*begin);
}

int             string_starts_with_no_case(const char *string,
                                           const char *begin)
{
  while (*string && char_to_lowercase(*string) == char_to_lowercase(*begin))
    {
      string++;
      begin++;
    }
  return (!*begin);
}

const char      *string_find(const char *string, const char *needle)
{
  while (*string)
    {
      if (string_starts_with(string, needle))
        return (string);
      string++;
    }
  return (NULL);
}

const char      *string_find_no_case(const char *string, const char *needle)
{
  while (*string)
    {
      if (string_starts_with(string, needle))
        return (string);
      string++;
    }
  return (NULL);
}
