/*
** string_concat.c for libcw in /home/bailly_j/rendu/corewar/libcw
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Fri Feb 26 16:02:33 2016 Jamy Bailly
** Last update Fri Feb 26 16:47:59 2016 Jamy Bailly
*/

#include <sys/types.h>
#include "str.h"

void		string_concat_char(char *dest, char source)
{
  size_t	dest_len;

  dest_len = string_get_length(dest);
  dest[dest_len + 1] = source;
}

void		string_concat(char *dest, const char *source)
{
  size_t	dest_len;
  int		i;

  dest_len = string_get_length(dest);
  i = 0;
  while (source[i] != '\0')
    {
      dest[dest_len + i] = source[i];
      i++;
    }
}

void		string_concat_n(char *dest, const char *source, int n)
{
  size_t	dest_len;
  int		i;

  dest_len = string_get_length(dest);
  i = 0;
  while (source[i] != '\0' && i < n)
    {
      dest[dest_len + i] = source[i];
      i++;
    }
}
