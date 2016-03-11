/*
** test_lexer.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 10 23:39:40 2016 antoine
** Last update Thu Mar 10 23:39:40 2016 antoine
*/

#include <stdlib.h>
#include "test.h"
#include "../asm/lexer.h"
#include "../libcw/string.h"

static void             test_lex(void)
{
  t_lexer_result        r;

  r = lex_from_string("");
  ASSERT(r.error == NULL);
  ASSERT(r.tokens == NULL);
  r = lex_from_string("level down \tgagnera  \t");
  ASSERT(r.error == NULL);
  ASSERT(r.tokens != NULL);
  assert_tokens_equals("{instruction value: level}"
                       "{instruction value: down}"
                       "{instruction value: gagnera}",
                       r.tokens);
  token_list_delete(r.tokens, 1);
  r = lex_from_string("\n");
  ASSERT(r.error == NULL);
  ASSERT(r.tokens != NULL);
  assert_tokens_equals("{new line}", r.tokens);
  token_list_delete(r.tokens, 1);
  r = lex_from_string("~");
  ASSERT(string_equals("Unexpected '~'", r.error->message));
  syntax_error_delete(r.error);
}

void            test_suite_lexer(void)
{
  test_lex();
}
