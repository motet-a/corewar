/*
** token_list.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 29 10:40:00 2016 antoine
** Last update Mon Feb 29 10:40:00 2016 antoine
*/

#include <stdlib.h>
#include "token.h"
#include "../libcw/string.h"

t_token_list    *token_list_new(t_token *token, t_token_list *next)
{
  t_token_list  *list;

  list = malloc(sizeof(t_token_list));
  if (!list)
    return (NULL);
  list->token = token;
  list->next = next;
  return (list);
}

t_token_list    *token_list_get_last(t_token_list *list)
{
  if (!list)
    return (NULL);
  if (!list->next)
    return (list);
  return (token_list_get_last(list->next));
}

void            token_list_add(t_token_list **list, t_token *token)
{
  t_token_list  *last;

  last = token_list_get_last(*list);
  if (!last)
    *list = token_list_new(token, NULL);
  else
    last->next = token_list_new(token, NULL);
}

void            token_list_delete(t_token_list *list, int delete_tokens)
{
  if (!list)
    return ;
  if (delete_tokens)
    token_delete(list->token);
  token_list_delete(list->next, delete_tokens);
  free(list);
}

void            token_list_print(const t_token_list *list, int output_file)
{
  if (!list)
    return ;
  token_print(list->token, output_file);
  token_list_print(list->next, output_file);
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
