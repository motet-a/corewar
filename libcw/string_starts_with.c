/*
** string_starts_with.c for corewar in /home/antoine/corewar/libcw
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  Thu Feb 25 23:10:41 2016 Antoine Baudrand
** Last update Thu Feb 25 23:13:09 2016 Antoine Baudrand
*/

#include "string.h"
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

int             string_ends_with(const char *string, const char *end)
{
  int           string_i;
  int           end_i;

  string_i = string_get_length(string);
  end_i = string_get_length(end);
  while (--string_i && --end_i)
    {
      if (string[string_i] != end[end_i])
        return (0);
    }
  return (end_i == 0);
}
