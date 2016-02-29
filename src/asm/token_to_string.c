/*
** token_to_string.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 29 19:01:42 2016 antoine
** Last update Mon Feb 29 19:01:42 2016 antoine
*/

#include <stdlib.h>
#include "token.h"
#include "../libcw/string.h"

static int      value_to_string(char *buffer, int max_length,
                                const t_token *token)
{
  if (token_has_string_value(token))
    string_concat_n(buffer, token->string_value, max_length);
  else if (token->type == TOKEN_TYPE_INTEGER)
    string_concat_n(buffer, "<TODO: integer conversion>", max_length);
  else
    return (-1);
  return (0);
}

char            *token_to_string(const t_token *token)
{
  char          buffer[200];
  const char    *type_string;

  buffer[0] = '\0';
  string_concat(buffer, "{");
  type_string = token_type_to_string(token->type);
  if (!type_string)
    return (NULL);
  string_concat(buffer, type_string);
  if (token_has_value(token))
    {
      string_concat(buffer, " value: ");
      if (value_to_string(buffer, 190 - string_get_length(buffer), token))
        return (NULL);
    }
  string_concat(buffer, "}");
  return (string_duplicate(buffer));
}
