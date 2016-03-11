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

static char     *get_string(const t_position *begin, t_string_reader *reader)
{
  int           length;
  int           begin_index;

  begin_index = (int)begin->index;
  length = (int)reader->position.index - begin_index;
  assert(length > 0);
  return (string_duplicate_n(reader->file->content + begin_index, length));
}

static t_result create_string_token_result(const t_position *begin,
                                           t_string_reader *reader,
                                           t_token_type type)
{
  t_token       *token;
  char          *string;

  assert(token_type_has_string_value(type));
  string = get_string(begin, reader);
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
