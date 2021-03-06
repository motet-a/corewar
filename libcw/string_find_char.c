/*
** string_find_char.c for corewar in /home/antoine/corewar/libcw
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  Thu Feb 25 21:03:11 2016 Antoine Baudrand
** Last update Thu Feb 25 21:19:05 2016 Antoine Baudrand
*/

#include <stdlib.h>
#include "string.h"
#include "char_type.h"

const char      *string_find_char(const char *string, char c)
{
  while (*string)
    {
      if (*string == c)
	return (string);
      string++;
    }
  return (NULL);
}

const char      *string_find_char_no_case(const char *string, char c)
{
  c = char_to_lowercase(c);
  while (*string)
    {
      if (char_to_lowercase(*string) == c)
	return (string);
      string++;
    }
  return (NULL);
}
