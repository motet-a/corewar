/*
** str.c for  in /home/pichar_v/Documents/tek1/CPE/corewar/libcw/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Thu Feb 25 16:14:18 2016 Valentin Pichard
** Last update Thu Feb 25 16:47:02 2016 Valentin Pichard
*/

#include <stdlib.h>
#include "str.h"

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

/*
** TODO: Rewrite this using string_copy()
*/
char            *string_duplicate(const char *source)
{
  int	i;
  char	*dest;

  i = 0;
  if ((dest = malloc(string_get_length(source) + 1)) == NULL)
    return (NULL);
  while (source[i])
    {
      dest[i] = source[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

/*
** TODO: Rewrite this using string_copy_n()
*/
char            *string_duplicate_n(const char *source, int n)
{
  int	i;
  char	*dest;

  i = 0;
  if ((dest = malloc(n + 1)) == NULL)
    return (NULL);
  while (i != n)
    {
      dest[i] = source[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

void            string_concat(char *dest, const char *source)
{
  int   i;
  int   i2;

  i = 0;
  i2 = 0;
  while (dest[i])
    i++;
  while (source[i])
    {
      dest[i + 1] = source[i2];
      i++;
      i2++;
    }
  dest[i] = 0;
}
