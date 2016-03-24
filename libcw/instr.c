/*
** instr.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 24 21:29:46 2016 antoine
** Last update Thu Mar 24 21:29:46 2016 antoine
*/

#include <stdlib.h>
#include "instr.h"
#include "print.h"

void                    instr_info_print(const t_instr_info *self)
{
  print_string("name: ");
  print_string(self->name);
  print_string("\ncode: ");
  print_int(self->code);
  print_string("\nhas_argument_descriptor: ");
  print_int(self->has_argument_descriptor);
  print_string("\n");
}

void                    instr_info_print_all(const t_instr_info *list)
{
  int                   i;

  i = -1;
  while (++i < instr_info_get_count(list))
    {
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

static void     init_live(t_instr_info *i)
{
  i->name = "live";
  i->code = 1;
  i->argument_count = 1;
  i->argument_types[0] = ARGUMENT_TYPE_DIRECT;
  i->cycle_count = 5;
}

static void     init_ld(t_instr_info *i)
{
  i->name = "ld";
  i->code = 2;
  i->argument_count = 2;
  i->argument_types[0] = ARGUMENT_TYPE_DIRECT;
  i->argument_types[1] = ARGUMENT_TYPE_REGISTER;
  i->cycle_count = 5;
}

void            instr_info_get_list(t_instr_info *list)
{
  init_live(list++);
  init_ld(list++);
  list->name = NULL;
}
