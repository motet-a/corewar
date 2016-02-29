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
#include "test.h"

static void     init_dummy_position(t_position *position)
{
  position->source_file = NULL;
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
  token_delete(token);
}

void    test_suite_token_list(void)
{
  test_token();
}
