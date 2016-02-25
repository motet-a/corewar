/*
** char_type.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Feb 25 20:45:17 2016 antoine
** Last update Thu Feb 25 20:45:17 2016 antoine
*/

#include "char_type.h"

int     char_is_digit(char c)
{
  return (c >= '0' && c <= '9');
}

int     char_is_uppercase(char c)
{
  return (c >= 'A' && c <= 'Z');
}

int     char_is_lowercase(char c)
{
  return (c >= 'a' && c <= 'z');
}
