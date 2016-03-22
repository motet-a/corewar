/*
** lex_instruction.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 10 10:00:06 2016 antoine
** Last update Thu Mar 10 10:00:06 2016 antoine
*/

#include <stdlib.h>
#include "lexer_private.h"
#include "../libcw/char_type.h"

static t_result         lex_label_def_2(t_string_reader *reader,
                                        const t_position *begin,
                                        const char *string)
{
  t_position            end;
  char                  c;
  t_token               *token;

  if (reader->position.index == begin->index)
    return (create_error_result("Expected a label name", &end));
  end = reader->position;
  if (has_more(reader))
    {
      c = next(reader);
      if (c != ' ' && c != '\n' && c != '\t')
        return (create_error_result("Expected a space after label name",
                                    &end));
    }
  reader->position = end;
  token = token_new_string(TOKEN_TYPE_LABEL_DEF, begin, string);
  return (create_token_result_2(token));
}

static t_result         lex_label_def(t_string_reader *reader,
                                      const t_position *begin,
                                      const t_position *end)
{
  t_result              result;
  char                  *string;
  t_position            current;

  current = reader->position;
  reader->position = *end;
  string = get_string(begin, reader);
  reader->position = current;
  result = lex_label_def_2(reader, begin, string);
  free(string);
  return (result);
}

static t_result         lex_instruction_end(t_string_reader *reader,
                                            const t_position *begin)
{
  t_position            previous;
  char                  c;

  while (has_more(reader))
    {
      previous = reader->position;
      c = next(reader);
      if (c == ':')
        return (lex_label_def(reader, begin, &previous));
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
  if (char_is_alphanumeric(c))
    return (lex_instruction_end(reader, &begin));
  reader->position = begin;
  return (create_null_result());
}
