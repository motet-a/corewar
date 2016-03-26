/*
** label_list.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 15:44:19 2016 antoine
** Last update Fri Mar 25 15:44:19 2016 antoine
*/

#include <stdlib.h>
#include "asm.h"

t_label_list            *label_list_new(const t_label *label)
{
  t_label_list          *list;

  list = malloc(sizeof(t_label_list));
  if (!list)
    return (NULL);
  list->label = *label;
  list->next = NULL;
  return (list);
}

void                    label_list_delete(t_label_list *list)
{
  if (!list)
    return ;
  label_list_delete(list->next);
  label_free(&list->label);
  free(list);
}

void                    label_list_add(t_label_list **list,
                                       t_token *label_token)
{
  t_label_list          *new;
  t_label               label;

  label_init(&label, label_token);
  new = label_list_new(&label);
  if (!new)
    return ;
  if (!*list)
    *list = new;
  else
    label_list_get_last(*list)->next = new;
}

t_label_list            *label_list_get_last(t_label_list *labels)
{
  if (!labels)
    return (NULL);
  if (!labels->next)
    return (labels);
  return (label_list_get_last(labels->next));
}

void                    label_list_print(const t_label_list *labels)
{
  if (!labels)
    return ;
  label_print(&labels->label);
  label_list_print(labels->next);
}
