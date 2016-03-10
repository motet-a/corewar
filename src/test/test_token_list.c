/*
** test_token_list.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 29 16:45:55 2016 antoine
** Last update Mon Feb 29 16:45:55 2016 antoine
*/

#include <stdlib.h>
#include "../libcw/string.h"
#include "../libcw/print.h"
#include "test.h"

static void     test_token_type_to_string(void)
{
  ASSERT(string_equals("instruction",
                       token_type_to_string(TOKEN_TYPE_INSTRUCTION)));
  ASSERT(string_equals("comment",
                       token_type_to_string(TOKEN_TYPE_COMMENT)));
  ASSERT(string_equals("percent",
                       token_type_to_string(TOKEN_TYPE_PERCENT)));
  ASSERT(string_equals("label definition",
                       token_type_to_string(TOKEN_TYPE_LABEL_DEF)));
}

static void     init_dummy_position(t_position *position)
{
  position->file = NULL;
  position->index = 0;
  position->column = 1;
  position->line = 1;
}

static void     test_token(void)
{
  t_token       *token;
  t_position    position;

  init_dummy_position(&position);
  token = token_new(TOKEN_TYPE_INTEGER, &position);
  ASSERT(token != NULL);
  token->integer_value = 789;
  assert_token_equals("{integer value: 789}", token);
  token_delete(token);
  token = token_new_string(TOKEN_TYPE_STRING, &position, "hello");
  ASSERT(token != NULL);
  assert_token_equals("{string value: hello}", token);
  token_delete(token);
}

static void     test_list(void)
{
  t_token       *token;
  t_token_list  *tokens;
  t_position    position;

  tokens = NULL;
  init_dummy_position(&position);
  token = token_new(TOKEN_TYPE_INTEGER, &position);
  token->integer_value = 789;
  token_list_add(&tokens, token);
  token = token_new_string(TOKEN_TYPE_STRING, &position, "hello");
  token_list_add(&tokens, token);
  token = token_new_string(TOKEN_TYPE_INSTRUCTION, &position, "world");
  token_list_add(&tokens, token);
  token = token_new(TOKEN_TYPE_COMMA, &position);
  token_list_add(&tokens, token);
  assert_tokens_equals("{integer value: 789}"
                       "{string value: hello}"
                       "{instruction value: world}"
                       "{comma}",
                       tokens);
  token_list_delete(tokens, 1);
}

void            test_suite_token_list(void)
{
  test_token();
  test_token_type_to_string();
  test_list();

}
