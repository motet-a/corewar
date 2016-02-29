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

void            token_list_add(t_token_list **list, t_token *token)
{
  *list = token_list_new(token, *list);
}

void            token_list_free(t_token_list *list, int delete_tokens)
{
  if (!list)
    return ;
  if (delete_tokens)
    token_delete(list->token);
  token_list_free(list->next, delete_tokens);
  free(list);
}

void            token_list_print(const t_token_list *list, int output_file)
{
  if (!list)
    return ;
  token_print(list->token, output_file);
  token_list_print(list->next, output_file);
}
