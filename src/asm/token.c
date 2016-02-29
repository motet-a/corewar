/*
** token.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 18:21:33 2016 antoine
** Last update Fri Feb 26 18:21:33 2016 antoine
*/

#include <stdlib.h>
#include "token.h"
#include "../libcw/string.h"
#include "../libcw/print.h"

static int      has_string_value(t_token_type type)
{
  return (type == TOKEN_TYPE_IDENTIFIER ||
          type == TOKEN_TYPE_STRING ||
          type == TOKEN_TYPE_DIRECTIVE ||
          type == TOKEN_TYPE_LABEL);
}

t_token         *token_new(t_token_type type,
                           const t_position *position)
{
  t_token       *token;

  token = malloc(sizeof(t_token));
  if (!token)
    return (NULL);
  token->type = type;
  token->position = *position;
  return (token);
}

t_token         *token_new_string(t_token_type type,
                                  const t_position *position,
                                  const char *string)
{
  t_token       *token;
  char          *string_copy;

  string_copy = string_duplicate(string);
  if (!string_copy)
    return (NULL);
  token = token_new(type, position);
  if (!token)
    return (token);
  token->string_value = string_copy;
  return (token);
}

void            token_delete(t_token *token)
{
  if (has_string_value(token->type))
    free(token->string_value);
  free(token);
}

char            *token_to_string(const t_token *token)
{
  char          buffer[200];

  string_concat(buffer, token_type_to_string(token->type));
  return (string_duplicate(buffer));
}

void            token_print(const t_token *token, int file)
{
  print_string_file("type: ", file);
  print_int_file(token->type, file);
  print_string_file("\n", file);
  if (has_string_value(token->type))
    {
      print_string_file("string_value: ", file);
      print_string_file(token->string_value, file);
      print_string_file("\n", file);
    }
}
