/*
** lex_directive.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 09:00:08 2016 antoine
** Last update Fri Mar 25 09:00:08 2016 antoine
*/

#include <stdlib.h>
#include "lexer_private.h"
#include "../libcw/char_type.h"

static t_result         lex_directive_end(t_string_reader *reader,
                                          const t_position *dot)
{
  t_position            begin;
  t_position            previous;
  t_token               *token;
  char                  *string;
  char                  c;

  begin = reader->position;
  while (has_more(reader))
    {
      previous = reader->position;
      c = next(reader);
      if (!char_is_letter(c))
        {
          reader->position = previous;
          break;
        }
    }
  if (reader->position.index == begin.index)
    return (create_error_result("Expected a directive name", &begin));
  string = get_string(&begin, reader);
  token = token_new_string(TOKEN_TYPE_DIRECTIVE, dot, string);
  free(string);
  return (create_token_result_2(token));
}

static t_result         lex_directive(t_string_reader *reader)
{
  t_position            begin;
  char                  c;

  begin = reader->position;
  c = next(reader);
  if (c == '.')
    return (lex_directive_end(reader, &begin));
  reader->position = begin;
  return (create_null_result());
}
