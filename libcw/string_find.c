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

const char      *string_find(const char *string, const char *needle)
{
  char		*to_find;
  char		*first_char;
  char		*cursor;

  first_char = (char *) string;
  while (*first_char)
    {
      to_find = (char *) needle;
      first_char = (char *) string_find_char(first_char, to_find[0]);
      cursor = first_char;
      while (string_find_char(cursor, *to_find) == cursor)
	{
	  cursor += 1;
	  to_find += 1;
	  if (!(*to_find))
	    return (first_char);
	}
      first_char += 1;
    }
  return (NULL);
}

const char      *string_find_no_case(const char *string, const char *needle)
{
  char		*to_find;
  char		*first_char;
  char		*cursor;

  first_char = (char *) string;
  while (*first_char)
    {
      to_find = (char *) needle;
      first_char = (char *) string_find_char_no_case(first_char, to_find[0]);
      cursor = first_char;
      while (string_find_char_no_case(cursor, *to_find) == cursor)
	{
	  cursor += 1;
	  to_find += 1;
	  if (!(*to_find))
	    return (first_char);
	}
      first_char += 1;
    }
  return (NULL);
}
