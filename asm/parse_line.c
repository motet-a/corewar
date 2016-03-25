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

static t_syntax_error   *parse_label_def(t_program *program,
                                         t_token_list **list_pointer)
{
  t_token *token = (*list_pointer)->token;
  if (token->type == TOKEN_TYPE_LABEL_DEF)
    {

    }
}

t_syntax_error          *parse_line(t_program *program,
                                    t_token_list **list_pointer)
{
  t_syntax_error        *error;

  if (!*list_pointer)
    return (NULL);
  error = parse_label_def(program, list_pointer);
  if (error)
    return (error);
}
