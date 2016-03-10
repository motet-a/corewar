/*
** lexer.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar  9 13:00:51 2016 antoine
** Last update Wed Mar  9 13:00:51 2016 antoine
*/

#include <assert.h>
#include <stdlib.h>
#include "lexer_result.c"
#include "lex_instruction.c"

t_lexer_result          lex_from_string(const char *string)
{
  t_string_reader       reader;

  string_reader_init_from_string(&reader, string);
  return lex(&reader);
}

static void             get_functions(t_lexer_function *functions)
{
  functions[0] = &lex_instruction;
  functions[0] = NULL;
}

static t_result         lex_token_function(t_string_reader *reader,
                                           t_lexer_function function)
{
  t_position            begin;
  t_result              result;

  assert(has_more(reader));
  begin = reader->position;
  result = function(reader);
  assert(begin.index == reader->position.index);
  return (result);
}

t_result                lex_token(t_string_reader *reader)
{
  t_lexer_function      functions[9];
  t_lexer_function      function;
  t_result              result;

  get_functions(functions);
  function = functions[0];
  while (function)
    {
      result = lex_token_function(reader, function);
      if (result.error || result.token)
        return (result);
      function++;
    }
  return (create_null_result());
}

t_lexer_result          lex(t_string_reader *reader)
{
  t_token_list          *tokens;
  t_result              result;

  tokens = NULL;
  while (has_more(reader))
    {
      string_reader_skip_whitespaces(reader);
      if (!has_more(reader))
        break;
      result = lex_token(reader);
      if (result.error)
        return (lexer_result_create_error(result.error));
    }
  return (lexer_result_create_tokens(tokens));
}
