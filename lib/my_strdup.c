/*
** my_strdup.c for  in /Users/westery/Documents/tek1/CPE/corewar/lib/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Tue Feb 23 01:23:21 2016 Valentin Pichard
** Last update Tue Feb 23 01:23:41 2016 Valentin Pichard
*/

#include "corewar_lib.h"

char		*my_strdup(char *src)
{
  int	i;
  char	*dest;

  i = 0;
  if ((dest = malloc(my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}
