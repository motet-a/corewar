/*
** parse_arg.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Mar 26 18:13:34 2016 antoine
** Last update Sat Mar 26 18:13:34 2016 antoine
*/

#include <stdlib.h>
#include "../libcw/string.h"
#include "../libcw/parse_int.h"
#include "asm.h"

static t_syntax_error   *parse_register(t_argument *arg,
                                        const t_token *token)
{
  const char            *s;
  long                  number;

  arg->type = ARGUMENT_TYPE_REGISTER;
  s = token->string_value;
  if (string_get_length(s) < 2 || string_get_length(s) > 3 || s[0] != 'r')
    return (syntax_error_new(&token->position, "Unknown identifier"));
  s++;
  if (parse_int(s, &number))
    return (syntax_error_new(&token->position, "Invalid register name"));
  if (!(number >= 1 && number <= VM_REGISTER_COUNT))
    return (syntax_error_new(&token->position, "Invalid register number"));
  arg->value = number;
  return (NULL);
}

static t_syntax_error   *parse_arg_indirect(t_argument *arg,
                                            t_token_list **list_pointer,
                                            const t_token *previous)
{
  t_token               *token;

  token = try_to_read_token(list_pointer, TOKEN_TYPE_INTEGER);
  if (token)
    {
      arg->value = token->integer_value;
      return (NULL);
    }
  token = try_to_read_token(list_pointer, TOKEN_TYPE_LABEL_REF);
  if (token)
    {
      arg->label = string_duplicate(token->string_value);
      return (NULL);
    }
  token = try_to_read_token(list_pointer, TOKEN_TYPE_INSTRUCTION);
  if (token)
    return (parse_register(arg, token));
  return (syntax_error_new(&previous->position, "Expected value"));
}

static t_syntax_error   *parse_arg_direct(t_argument *arg,
                                          t_token_list **list_pointer,
                                          const t_token *percent)
{
  t_token               *token;

  token = try_to_read_token(list_pointer, TOKEN_TYPE_INTEGER);
  if (token)
    {
      arg->value = token->integer_value;
      return (NULL);
    }
  token = try_to_read_token(list_pointer, TOKEN_TYPE_LABEL_REF);
  if (token)
    {
      arg->label = string_duplicate(token->string_value);
      return (NULL);
    }
  return (syntax_error_new(&percent->position, "Expected value"));
}

t_syntax_error          *parse_arg(t_argument *arg,
                                   t_token_list **list_pointer,
                                   const t_token *previous)
{
  t_token               *percent;

  arg->value = 0;
  arg->label = NULL;
  percent = try_to_read_token(list_pointer, TOKEN_TYPE_PERCENT);
  if (percent)
    {
      arg->type = ARGUMENT_TYPE_DIRECT;
      return (parse_arg_direct(arg, list_pointer, percent));
    }
  else
    {
      arg->type = ARGUMENT_TYPE_INDIRECT;
      return (parse_arg_indirect(arg, list_pointer, previous));
    }
}
