/*
** lex_comment.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 08:52:31 2016 antoine
** Last update Fri Mar 25 08:52:31 2016 antoine
*/

#include <stdlib.h>
#include "lexer_private.h"

static t_result         lex_comment_end(t_string_reader *reader)
{
  t_position            begin;
  char                  c;

  while (has_more(reader))
    {
      begin = reader->position;
      c = next(reader);
      if (c == '\n')
        {
          reader->position = begin;
          break;
        }
    }
  return (create_null_result());
}

static t_result         lex_comment(t_string_reader *reader)
{
  t_position            begin;
  char                  c;

  begin = reader->position;
  c = next(reader);
  if (c == '#')
    return (lex_comment_end(reader));
  reader->position = begin;
  return (create_null_result());
}
