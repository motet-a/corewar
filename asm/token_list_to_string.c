/*
** token_list_to_string.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 11 14:22:55 2016 antoine
** Last update Fri Mar 11 14:22:55 2016 antoine
*/

#include <stdlib.h>
#include "token.h"
#include "../libcw/string.h"
#include "../libcw/print.h"

void            token_list_print(const t_token_list *list,
                                 const char *separator,
                                 int output_file)
{
  if (!list)
    return ;
  token_print(list->token, output_file);
  print_string_file(separator, output_file);
  token_list_print(list->next, separator, output_file);
}

char            *token_list_to_string(const t_token_list *list)
{
  char          *token;
  char          *right;
  char          *s;

  if (!list)
    return (string_duplicate(""));
  token = token_to_string(list->token);
  right = token_list_to_string(list->next);
  if (!token || !right)
    return (NULL);
  s = malloc(string_get_length(token) + string_get_length(right) + 1);
  if (!s)
    return (NULL);
  string_copy(s, token);
  string_concat(s, right);
  free(token);
  free(right);
  return (s);
}
