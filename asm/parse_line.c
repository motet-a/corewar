/*
** parse_line.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 14:00:57 2016 antoine
** Last update Fri Mar 25 14:00:57 2016 antoine
*/

#include <stdlib.h>
#include "asm.h"

static t_token          *try_to_read_token(t_token_list **list_pointer,
                                           t_token_type type)
{
  t_token               *token;

  if (!*list_pointer)
    return (NULL);
  token = (*list_pointer)->token;
  if (token->type == type)
    {
      *list_pointer = (*list_pointer)->next;
      return (token);
    }
  else
    return (NULL);
}

static t_syntax_error   *parse_label_def(t_program *program,
                                         t_token_list **list_pointer,
                                         t_token **last_token_pointer)
{
  t_token               *token;

  token = try_to_read_token(list_pointer, TOKEN_TYPE_LABEL_DEF);
  if (token)
    {
      *last_token_pointer = token;
      label_list_add(&program->labels, token);
    }
  return (NULL);
}

t_syntax_error          *parse_line(t_program *program,
                                    t_token_list **list_pointer)
{
  t_syntax_error        *error;
  t_token               *last;
  t_token               *token;

  last = NULL;
  error = parse_label_def(program, list_pointer, &last);
  if (error)
    return (error);
  try_to_read_token(list_pointer, TOKEN_TYPE_INSTRUCTION);
  token = (*list_pointer)->token;
  if (token)
    {
      last = token;
    }
  if (!*list_pointer)
    return (NULL);
  if (try_to_read_token(list_pointer, TOKEN_TYPE_NEW_LINE))
    return (syntax_error_new(&last->position, "Expected end of line"));
  return (NULL);
}
