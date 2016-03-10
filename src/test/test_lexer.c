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
}

void            test_suite_lexer(void)
{
  test_lex();
}
