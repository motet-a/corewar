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
#include "lex_new_line.c"
#include "lex_label_ref.c"
#include "lex_integer.c"

t_lexer_result          lex_from_string(const char *string)
{
  t_string_reader       reader;
  t_lexer_result        r;

  string_reader_init_from_string(&reader, string);
  assert(reader.file->content);
  r = lex(&reader);
  source_file_free(reader.file);
  free(reader.file);
  return (r);
}

static void             get_functions(t_lexer_function *functions)
{
  functions[0] = lex_instruction;
  functions[1] = lex_new_line;
  functions[2] = lex_label_ref;
  functions[3] = lex_integer;
  functions[4] = NULL;
}

static t_result         lex_token_function(t_string_reader *reader,
                                           t_lexer_function function)
{
  t_position            begin;
  t_result              result;

  assert(has_more(reader));
  begin = reader->position;
  result = function(reader);
  if (result.token || result.error)
    return (result);
  assert(begin.index == reader->position.index);
  return (result);
}

t_result                lex_token(t_string_reader *reader)
{
  t_lexer_function      functions[9];
  t_result              result;
  size_t                i;

  get_functions(functions);
  i = 0;
  while (functions[i])
    {
      result = lex_token_function(reader, functions[i]);
      if (result.error || result.token)
        return (result);
      i++;
    }
  return (create_null_result());
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

t_lexer_result          lex(t_string_reader *reader)
{
  t_token_list          *tokens;
  t_result              result;

  assert(reader->file->content);
  tokens = NULL;
  while (has_more(reader))
    {
      string_reader_skip(reader, " \t");
      if (!has_more(reader))
        break;
      result = lex_token(reader);
      if (result.error)
        return (lexer_result_create_error(result.error));
      if (!result.token)
        return (create_new_unexpected_error(reader));
      token_list_add(&tokens, result.token);
    }
  return (lexer_result_create_tokens(tokens));
}
