/*
** char_type_convert.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Feb 25 21:48:32 2016 antoine
** Last update Thu Feb 25 21:48:32 2016 antoine
*/

#include "char_type.h"

char    char_to_lowercase(char c)
{
  if (char_is_uppercase(c))
    return (c + ('a' - 'A'));
  return (c);
}

char    char_to_uppercase(char c)
{
  if (char_is_lowercase(c))
    return (c - ('a' - 'A'));
  return (c);
}
