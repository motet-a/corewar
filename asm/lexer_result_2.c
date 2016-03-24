/*
** lexer_result_2.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 11 14:27:48 2016 antoine
** Last update Fri Mar 11 14:27:48 2016 antoine
*/

#include <assert.h>
#include <stdlib.h>
#include "lexer_private.h"
#include "../libcw/string.h"

static t_result create_error_result(const char *message,
                                    const t_position *position)
{
  t_result      r;

  r.error = syntax_error_new(position, message);
  r.token = NULL;
  return (r);
}

static t_result create_token_result_2(t_token *token)
{
  t_result      r;

  r.error = NULL;
  r.token = token;
  return (r);
}

static t_result create_token_result(const t_position *begin,
                                    t_token_type type)
{
  t_token       *token;

  token = token_new(type, begin);
  return (create_token_result_2(token));
}

static t_result create_null_result(void)
{
  t_result      r;

  r.error = NULL;
  r.token = NULL;
  return (r);
}
