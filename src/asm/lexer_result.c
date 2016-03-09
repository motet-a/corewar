/*
** lexer_result.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar  9 13:05:37 2016 antoine
** Last update Wed Mar  9 13:05:37 2016 antoine
*/

#include <stdlib.h>
#include "lexer_private.h"

static t_lexer_result   lexer_result_create_tokens(t_token_list *tokens)
{
  t_lexer_result        r;

  r.tokens = tokens;
  r.error = NULL;
  return (r);
}

static t_lexer_result   lexer_result_create_error(t_syntax_error *error)
{
  t_lexer_result        r;

  r.tokens = NULL;
  r.error = error;
  return (r);
}

static t_result create_error_result(const char *message,
                                    const t_position *position)
{
  t_result      r;

  r.error = syntax_error_new(position, message);
  r.token = NULL;
  return (r);
}

static t_result create_token_result(t_token *token)
{
  t_result      r;

  r.error = NULL;
  r.token = token;
  return (r);
}

static t_result create_null_result(void)
{
  t_result      r;

  r.error = NULL;
  r.token = NULL;
  return (r);
}