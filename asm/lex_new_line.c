/*
** lex_new_line.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 11 14:56:26 2016 antoine
** Last update Fri Mar 11 14:56:26 2016 antoine
*/

#include "lexer_private.h"

static t_result         lex_new_line_end(t_string_reader *reader,
                                         const t_position *begin)
{
  t_position            prev;
  char                  c;

  while (has_more(reader))
    {
      prev = reader->position;
      c = next(reader);
      if (c != '\n' && c != '\r')
        {
          reader->position = prev;
          break;
        }
    }
  return (create_token_result(begin, TOKEN_TYPE_NEW_LINE));
}

static t_result         lex_new_line(t_string_reader *reader)
{
  t_position            begin;
  char                  c;

  begin = reader->position;
  c = next(reader);
  if (c == '\n' || c == '\r')
    return (lex_new_line_end(reader, &begin));
  reader->position = begin;
  return (create_null_result());
}
