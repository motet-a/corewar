/*
** lexer_result.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar  9 13:05:37 2016 antoine
** Last update Wed Mar  9 13:05:37 2016 antoine
*/

#include <assert.h>
#include <stdlib.h>
#include "lexer_private.h"
#include "../libcw/string.h"

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

static t_result create_string_token_result(const t_position *begin,
                                           t_string_reader *reader,
                                           t_token_type type)
{
  t_token       *token;
  char          *string;
  int           length;
  int           begin_index;

  assert(token_type_has_string_value(type));;
  begin_index = (int)begin->index;
  length = (int)reader->position.index - begin_index;
  assert(length > 0);
  string = string_duplicate_n(reader->file->content + begin_index, length);
  token = token_new_string(type, begin, string);
  free(string);
  return (create_token_result_2(token));
}

static t_result create_null_result(void)
{
  t_result      r;

  r.error = NULL;
  r.token = NULL;
  return (r);
}
