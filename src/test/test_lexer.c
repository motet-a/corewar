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

static void             test_lex_2(void)
{
  t_lexer_result        r;

  r = lex_from_string("babar le roi des elephants 123 viens au bde gro ~");
  ASSERT(string_equals("Unexpected '~'", r.error->message));
  syntax_error_delete(r.error);
}

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

static void             test_lex_label(void)
{
  t_lexer_result        r;

  r = lex_from_string(":");
  ASSERT(string_equals("Expected a label name", r.error->message));
  syntax_error_delete(r.error);
  r = lex_from_string(":123soleil");
  assert_tokens_equals("{label reference value: 123soleil}", r.tokens);
  token_list_delete(r.tokens, 1);
  r = lex_from_string("123soleil:");
  assert_tokens_equals("{label definition value: 123soleil}", r.tokens);
  token_list_delete(r.tokens, 1);
  r = lex_from_string("123soleil:\n");
  assert_tokens_equals("{label definition value: 123soleil}"
                       "{new line}", r.tokens);
  token_list_delete(r.tokens, 1);
  r = lex_from_string("lol:lol");
  ASSERT(string_equals("Expected a space after label name",
                       r.error->message));
  syntax_error_delete(r.error);
}

static void             test_lex_int(void)
{
  t_lexer_result        r;

  r = lex_from_string("0 z 0z");
  assert_tokens_equals("{integer value: 0}"
                       "{instruction value: z}"
                       "{instruction value: 0z}", r.tokens);
  token_list_delete(r.tokens, 1);
  r = lex_from_string("9999999999999999999999999999999999999999999999999");
  ASSERT(string_equals("Invalid integer", r.error->message));
  syntax_error_delete(r.error);
}

void            test_suite_lexer(void)
{
  test_lex();
  test_lex_2();
  test_lex_label();
  test_lex_int();
}
