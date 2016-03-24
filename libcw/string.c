/*
** str.c for  in /home/pichar_v/Documents/tek1/CPE/corewar/libcw/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Thu Feb 25 16:14:18 2016 Valentin Pichard
** Last update Mon Feb 29 16:56:34 2016 Valentin Pichard
*/

#include <stdlib.h>
#include "string.h"

void            string_set_n_chars(char *string, char c, int n)
{
  while (n--)
    {
      *string = c;
      string++;
    }
}

int             string_get_length(const char *string)
{
  int		i;

  i = 0;
  while (*string != 0)
    {
      string++;
      i++;
    }
  return (i);
}

char            *string_duplicate(const char *source)
{
  char	*dest;

  if ((dest = malloc(string_get_length(source) + 1)) == NULL)
    return (NULL);
  return (string_copy(dest, source));
}

char            *string_duplicate_n(const char *source, int n)
{
  char	*dest;

  if ((dest = malloc(n + 1)) == NULL)
    return (NULL);
  return (string_copy_n(dest, source, n));
}
