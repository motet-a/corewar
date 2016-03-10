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
#include "../asm/token.h"
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
  position->source_file = NULL;
  position->index = 0;
  position->column = 1;
  position->line = 1;
}

static void     assert_token_equals(const char *expected,
                                    const t_token *token)
{
  char          *string;
  int           r;

  string = token_to_string(token);
  r = string_equals(expected, string);
  ASSERT(r);
  if (!r)
    {
      print_string("Expected ");
      print_string(expected);
      print_string(", got ");
      print_string(string);
      print_string("\n");
    }
  free(string);
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

void    test_suite_token_list(void)
{
  test_token();
  test_token_type_to_string();
}
