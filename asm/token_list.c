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
