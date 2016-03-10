/*
** lex_instruction.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 10 10:00:06 2016 antoine
** Last update Thu Mar 10 10:00:06 2016 antoine
*/

#include "lexer_private.h"
#include "../libcw/char_type.h"

static t_result         lex_instruction_end(t_string_reader *reader,
                                            const t_position *begin)
{
  t_position            previous;
  char                  c;

  while (has_more(reader))
    {
      previous = reader->position;
      c = next(reader);
      if (!char_is_alphanumeric(c))
        {
          reader->position = previous;
          break;
        }
    }
  return (create_string_token_result(begin, reader, TOKEN_TYPE_INSTRUCTION));
}

static t_result         lex_instruction(t_string_reader *reader)
{
  t_position            begin;
  char                  c;

  begin = reader->position;
  c = next(reader);
  if (char_is_letter(c))
    return (lex_instruction_end(reader, &begin));
  reader->position = begin;
  return (create_null_result());
}
