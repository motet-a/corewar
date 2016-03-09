/*
** token_type.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 29 18:23:58 2016 antoine
** Last update Mon Feb 29 18:23:58 2016 antoine
*/

#include <stdlib.h>
#include "token.h"

int             token_type_has_string_value(t_token_type type)
{
  return (type == TOKEN_TYPE_IDENTIFIER ||
          type == TOKEN_TYPE_STRING ||
          type == TOKEN_TYPE_DIRECTIVE ||
          type == TOKEN_TYPE_LABEL_DEF ||
          type == TOKEN_TYPE_LABEL_REF);
}

int             token_type_has_value(t_token_type type)
{
  return (token_type_has_string_value(type) || type == TOKEN_TYPE_INTEGER);
}

void            skip_word(const char **string_pointer)
{
  while (**string_pointer)
    (*string_pointer)++;
}

const char      *token_type_to_string(t_token_type type)
{
  const char    *types_string;

  types_string = ("identifier\0"
                  "integer\0string\0"
                  "directive\0comment\0"
                  "label definition\0label reference\0"
                  "comma\0percent\0\0");
  while (*types_string)
    {
      if (!type)
        return (types_string);
      type--;
      skip_word(&types_string);
      types_string++;
    }
  return (NULL);
}
