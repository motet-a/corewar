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
#include "../libcw/string.h"
#include "../libcw/char_type.h"

t_token                 *try_to_read_token(t_token_list **list_pointer,
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
                                         t_token_list **list_pointer)
{
  t_token               *token;

  token = try_to_read_token(list_pointer, TOKEN_TYPE_LABEL_DEF);
  if (token)
    {
      label_list_add(&program->labels, token);
    }
  return (NULL);
}

static t_syntax_error   *parse_directive(t_program *program,
                                         t_token_list **list_pointer,
                                         int *ok)
{
  t_token               *directive;
  t_token               *string;
  char                  type;

  *ok = 0;
  directive = try_to_read_token(list_pointer, TOKEN_TYPE_DIRECTIVE);
  if (!directive)
    return (NULL);
  if (string_equals(directive->string_value, "name"))
    type = 'n';
  else if (string_equals(directive->string_value, "comment"))
    type = 'c';
  else
    return (syntax_error_new(&directive->position, "Invalid directive"));
  string = try_to_read_token(list_pointer, TOKEN_TYPE_STRING);
  if (!string)
    return (syntax_error_new(&directive->position, "Expected a string"));
  if (type == 'n')
    program->name = string_duplicate(string->string_value);
  else
    program->comment = string_duplicate(string->string_value);
  *ok = 1;
  return (NULL);
}

t_syntax_error          *parse_line(t_program *program,
                                    t_token_list **list_pointer)
{
  t_syntax_error        *error;
  t_token               *first;
  int                   ok;

  if (!*list_pointer)
    return (NULL);
  first = (*list_pointer)->token;
  error = parse_directive(program, list_pointer, &ok);
  if (error || ok)
    return (error);
  error = parse_label_def(program, list_pointer);
  if (error)
    return (error);
  error = parse_instr(program, list_pointer);
  if (error)
    return (error);
  if (!*list_pointer)
    return (NULL);
  if (!try_to_read_token(list_pointer, TOKEN_TYPE_NEW_LINE))
    return (syntax_error_new(&first->position, "Expected end of line"));
  return (NULL);
}
