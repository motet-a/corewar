/*
** test_token.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 10 22:06:08 2016 antoine
** Last update Thu Mar 10 22:06:08 2016 antoine
*/

#include <stdlib.h>
#include "../libcw/string.h"
#include "../libcw/print.h"
#include "test.h"

void     assert_token_equals(const char *expected, const t_token *token)
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

void    assert_tokens_equals(const char *expected,
                             const t_token_list *tokens)
{
  char          *string;
  int           r;

  string = token_list_to_string(tokens);
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
