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
#include "lexer_result_2.c"
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

static t_lexer_result   create_new_unexpected_error(t_string_reader *reader)
{
  char                  c;
  char                  message[40];
  t_syntax_error        *e;

  if (has_more(reader))
    c = next(reader);
  else
    c = reader->file->content[reader->position.index - 1];
  string_copy(message, "Unexpected '?'");
  message[12] = c;
  e = syntax_error_new(&reader->position, message);
  return (lexer_result_create_error(e));
}
