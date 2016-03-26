/*
** instr.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 24 21:29:46 2016 antoine
** Last update Fri Mar 25 01:38:35 2016 Valentin Pichard
*/

#include <stdlib.h>
#include "instr.h"
#include "print.h"
#include "string.h"

void                    instr_info_print(const t_instr_info *self)
{
  print_string("name: ");
  print_string(self->name);
  print_string("\ncode: ");
  print_int(self->code);
  print_string("\nhas_argument_descriptor: ");
  print_string(self->has_argument_descriptor ? "yes" : "no");
  print_string("\n");
}

void                    instr_info_print_list(const t_instr_info *list)
{
  int                   i;

  i = -1;
  while (++i < instr_info_get_count(list))
    {
      if (i)
        print_string("\n");
      instr_info_print(list + i);
    }
}

int                     instr_info_get_count(const t_instr_info *list)
{
  int                   c;

  c = 0;
  while (list->name)
    {
      list++;
      c++;
    }
  return (c);
}

void            instr_info_get_list(t_instr_info *list)
{
  list = instr_info_get_list_0(list);
  list = instr_info_get_list_1(list);
  list = instr_info_get_list_2(list);
  list = instr_info_get_list_3(list);
  list->name = NULL;
}

const t_instr_info      *instr_info_get_from_name(const t_instr_info *list,
                                                  const char *name)
{
  while (list->name)
    {
      if (string_equals(name, list->name))
        return (list);
      list++;
    }
  return (NULL);
}
