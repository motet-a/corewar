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
#include "lex_comment.c"
#include "lex_directive.c"
#include "lex_string.c"
#include "lex_symbol.c"

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
  int                   i;

  i = 0;
  functions[i++] = lex_comment;
  functions[i++] = lex_new_line;
  functions[i++] = lex_label_ref;
  functions[i++] = lex_integer;
  functions[i++] = lex_instruction;
  functions[i++] = lex_directive;
  functions[i++] = lex_string;
  functions[i++] = lex_symbol;
  functions[i++] = NULL;
}

static t_result         lex_token_function(t_string_reader *reader,
                                           t_lexer_function function)
{
  t_result              result;

  assert(has_more(reader));
  result = function(reader);
  if (result.token || result.error)
    return (result);
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
        {
          token_list_delete(tokens, 1);
          return (lexer_result_create_error(result.error));
        }
      if (!result.token)
        {
          token_list_delete(tokens, 1);
          return (create_new_unexpected_error(reader));
        }
      token_list_add(&tokens, result.token);
    }
  return (lexer_result_create_tokens(tokens));
}
