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
#include "str.h"

const char      *string_find_char(const char *string, char c)
{
  while (*string)
    {
      if (*string == c)
	return (string);
      else
	string += 1;
    }
  return (NULL);
}

const char      *string_find_char_no_case(const char *string, char c)
{
  const char	*res;

  res = string_find_char(string, c);
  if (res)
    return (res);
  else if (c >= 'a' && c <= 'z')
    return (string_find_char(string, c - 32));
  else if (c >= 'A' && c <= 'Z')
    return (string_find_char(string, c + 32));
  else
    return (NULL);
}
