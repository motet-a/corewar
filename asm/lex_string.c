/*
** lex_string.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 09:07:11 2016 antoine
** Last update Fri Mar 25 09:07:11 2016 antoine
*/

#include <stdlib.h>
#include "lexer_private.h"

static t_result         create_string_result(const t_position *begin_quote,
                                             const t_position *end_quote,
                                             t_string_reader *reader)
{
  t_position            pos;
  char                  *string;
  t_token               *token;

  pos = reader->position;
  reader->position = *end_quote;
  string = get_string(begin_quote, reader);
  token = token_new_string(TOKEN_TYPE_STRING, begin_quote, string);
  free(string);
  reader->position = pos;
  return (create_token_result_2(token));
}

static t_result         lex_string_end(t_string_reader *reader,
                                       const t_position *begin_quote)
{
  t_position            begin;
  t_position            previous;
  char                  c;

  begin = reader->position;
  while (has_more(reader))
    {
      previous = reader->position;
      c = next(reader);
      if (c == '"')
        break;
      if (c == '\n')
        return create_error_result("Expected '\"'", &begin);
    }
  return (create_string_result(begin_quote, &previous, reader));
}

static t_result         lex_string(t_string_reader *reader)
{
  t_position            begin;
  char                  c;

  begin = reader->position;
  c = next(reader);
  if (c == '"')
    return (lex_string_end(reader, &begin));
  reader->position = begin;
  return (create_null_result());
}
