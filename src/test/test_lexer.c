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

static void             test_lex(void)
{
  t_lexer_result        r;

  r = lex_from_string("");
  ASSERT(r.error == NULL);
  ASSERT(r.tokens == NULL);
  r = lex_from_string("level down gagnera");
  ASSERT(r.error == NULL);
  ASSERT(r.tokens != NULL);
  assert_tokens_equals("{instruction value: level}"
                       "{instruction value: down}"
                       "{instruction value: gagnera}",
                       r.tokens);
  token_list_delete(r.tokens, 1);
}

void            test_suite_lexer(void)
{
  test_lex();
}
