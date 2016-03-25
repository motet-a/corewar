/*
** lex_symbol.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 09:25:46 2016 antoine
** Last update Fri Mar 25 09:25:46 2016 antoine
*/

#include <stdlib.h>
#include "lexer_private.h"

static t_result         lex_symbol(t_string_reader *reader)
{
  t_position            begin;
  char                  c;

  begin = reader->position;
  c = next(reader);
  if (c == ',')
    return (create_token_result(&begin, TOKEN_TYPE_COMMA));
  if (c == '%')
    return (create_token_result(&begin, TOKEN_TYPE_PERCENT));
  reader->position = begin;
  return (create_null_result());
}
