/*
** argparser_arg_list.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 12:20:52 2016 antoine
** Last update Fri Feb 26 12:20:52 2016 antoine
*/

#include <stdlib.h>
#include "argparser_private.h"

t_arg_list      *argparser_arg_list_new(const t_arg *arg,
                                        t_arg_list *next)
{
  t_arg_list    *list;

  list = malloc(sizeof(t_arg_list));
  if (!list)
    return (NULL);
  list->arg = *arg;
  list->next = next;
  return (list);
}
void            argparser_arg_list_delete(t_arg_list *list)
{
  if (!list)
    return ;
  argparser_arg_list_delete(list->next);
  free(list);
}

void            argparser_arg_list_add(t_arg_list **list,
                                       const t_arg *arg)
{
  *list = argparser_arg_list_new(arg, *list);
}
