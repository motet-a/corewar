/*
** str.c for  in /home/pichar_v/Documents/tek1/CPE/corewar/libcw/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Thu Feb 25 16:14:18 2016 Valentin Pichard
** Last update Fri Feb 26 16:36:40 2016 Jamy Bailly
*/

#include "str.h"

#include <stdlib.h>

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
