/*
** string_find.c for corewar in /home/antoine/corewar/libcw
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  Thu Feb 25 21:26:28 2016 Antoine Baudrand
** Last update Thu Feb 25 23:10:53 2016 Antoine Baudrand
*/

#include <stdlib.h>
#include "str.h"
#include "char_type.h"

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
      if (string_starts_with_no_case(string, needle))
        return (string);
      string++;
    }
  return (NULL);
}
