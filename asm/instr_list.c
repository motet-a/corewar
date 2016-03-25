/*
** instr_list.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 09:46:07 2016 antoine
** Last update Fri Mar 25 09:46:07 2016 antoine
*/

#include <stdlib.h>
#include "asm.h"

t_instr_list            *instr_list_new(const t_instr *instr,
                                        t_instr_list *next)
{
  t_instr_list          *list;

  list = malloc(sizeof(t_instr_list));
  if (!list)
    return (NULL);
  list->instr = *instr;
  list->next = next;
  return (list);
}

void                    instr_list_add(t_instr_list **list_pointer,
                                       const t_instr *instr)
{
  t_instr_list          *new;

  new = instr_list_new(instr, NULL);
  if (!new)
    return ;
  if (!*list_pointer)
    *list_pointer = new;
  else
    instr_list_get_last(*list_pointer)->next = new;
}

void                    instr_list_delete(t_instr_list *list)
{
  if (!list)
    return ;
  instr_list_delete(list->next);
  free(list);
}

t_instr_list            *instr_list_get_last(t_instr_list *list)
{
  if (!list)
    return (NULL);
  if (!list->next)
    return (list);
  return (instr_list_get_last(list->next));
}

void                    instr_list_print(const t_instr_list *list)
{
  if (!list)
    return ;
  instr_print(&list->instr);
  instr_list_print(list->next);
}
