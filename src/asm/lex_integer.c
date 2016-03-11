/*
** lex_integer.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 11 19:06:12 2016 antoine
** Last update Fri Mar 11 19:06:12 2016 antoine
*/

#include <stdlib.h>
#include "lexer_private.h"
#include "../libcw/char_type.h"
#include "../libcw/parse_int.h"

static t_result         lex_integer_2(const char *string,
                                      const t_position *begin)
{
  t_token               *token;
  long                  n;

  token = token_new(TOKEN_TYPE_INTEGER, begin);
  if (parse_int(string, &n))
    return (create_error_result("Invalid integer", begin));
  token->integer_value = n;
  return (create_token_result_2(token));
}

static t_result         lex_integer_end(t_string_reader *reader,
                                        const t_position *begin)
{
  t_position            previous;
  t_result              r;
  char                  *string;
  char                  c;

  while (has_more(reader))
    {
      previous = reader->position;
      c = next(reader);
      if (!char_is_digit(c))
        {
          reader->position = previous;
          break;
        }
    }
  string = get_string(begin, reader);
  r = lex_integer_2(string, begin);
  free(string);
  return (r);
}

static t_result         lex_integer(t_string_reader *reader)
{
  t_position            begin;
  char                  c;

  begin = reader->position;
  c = next(reader);
  if (char_is_digit(c))
    return (lex_integer_end(reader, &begin));
  reader->position = begin;
  return (create_null_result());
}
