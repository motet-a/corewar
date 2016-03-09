/*
** string_type.c for  in /Users/westery/Documents/tek1/CPE/corewar/src/libcw/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Wed Mar  9 00:51:11 2016 Valentin Pichard
** Last update Wed Mar  9 18:38:56 2016 Valentin Pichard
*/

#include "string_type.h"
#include "char_type.h"
#include "string.h"

int     string_is_digit(const char *str)
{
  if (string_get_length(str) == 0)
    return (0);
  while (*str)
    {
      if (!char_is_digit(*str++))
	return (0);
    }
  return (1);
}

int     string_is_uppercase(const char *str)
{
  if (string_get_length(str) == 0)
    return (0);
  while (*str)
    {
      if (!char_is_uppercase(*str++))
	return (0);
    }
  return (1);
}

int     string_is_lowercase(const char *str)
{
  if (string_get_length(str) == 0)
    return (0);
  while (*str)
    {
      if (!char_is_lowercase(*str++))
	return (0);
    }
  return (1);
}

int     string_is_letter(const char *str)
{
  if (string_get_length(str) == 0)
    return (0);
  while (*str)
    {
      if (!char_is_letter(*str++))
	return (0);
    }
  return (1);
}

int     string_is_alphanumeric(const char *str)
{
  if (string_get_length(str) == 0)
    return (0);
  while (*str)
    {
      if (!char_is_alphanumeric(*str++))
	return (0);
    }
  return (1);
}
