/*
** string_copy.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 29 16:41:33 2016 antoine
** Last update Mon Feb 29 16:41:33 2016 antoine
*/

#include "string.h"

char            *string_copy(char *dest, const char *source)
{
  int	i;

  i = 0;
  while (source[i])
    {
      dest[i] = source[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
 }

char            *string_copy_n(char *dest, const char *source, int n)
{
  int	i;

  i = 0;
  while (i != n)
    {
      dest[i] = source[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}
