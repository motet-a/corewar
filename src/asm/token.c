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
  if (token_type_has_string_value(token->type))
    free(token->string_value);
  free(token);
}

void            token_print(const t_token *token, int file)
{
  char          *string;

  string = token_to_string(token);
  if (!string)
    print_string_file("token_to_string() error", file);
  print_string_file(string, file);
  free(string);
}
