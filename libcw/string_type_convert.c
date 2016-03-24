/*
** string_type_convert.c for  in /Users/westery/Documents/tek1/CPE/corewar/src/libcw/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Wed Mar  9 01:19:06 2016 Valentin Pichard
** Last update Wed Mar  9 01:30:11 2016 Valentin Pichard
*/

#include <stddef.h>
#include "string_type.h"
#include "char_type.h"
#include "string.h"

char            *string_to_lowercase(const char *source)
{
  char          *copy;
  size_t        i;

  copy = string_duplicate(source);
  i = 0;
  while (source[i])
    {
      copy[i] = char_to_lowercase(source[i]);
      i++;
    }
  return (copy);
}

char    *string_to_uppercase(const char *source)
{
  char          *copy;
  size_t        i;

  copy = string_duplicate(source);
  i = 0;
  while (source[i])
    {
      copy[i] = char_to_uppercase(source[i]);
      i++;
    }
  return (copy);
}
