/*
** string_type_convert.c for  in /Users/westery/Documents/tek1/CPE/corewar/src/libcw/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Wed Mar  9 01:19:06 2016 Valentin Pichard
** Last update Wed Mar  9 01:30:11 2016 Valentin Pichard
*/

#include "string_type.h"
#include "char_type.h"
#include "string.h"

char    *string_to_lowercase(const char *str)
{
  char  *str_copy;

  str_copy = string_duplicate(str);
  while (*str_copy)
    {
      char_to_lowercase(*str_copy);
      str_copy++;
    }
  return (str_copy);
}

char    *string_to_uppercase(const char *str)
{
  char  *str_copy;

  str_copy = string_duplicate(str);
  while (*str_copy)
    {
      char_to_uppercase(*str_copy);
      str_copy++;
    }
  return (str_copy);
}
