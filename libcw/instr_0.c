/*
** instr_0.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 10:18:33 2016 antoine
** Last update Fri Mar 25 10:18:33 2016 antoine
*/

#include "instr.h"

static void     init_live(t_instr_info *i)
{
  i->name = "live";
  i->argument_count = 1;
  i->argument_types[0] = ARGUMENT_TYPE_DIRECT;
  i->code = 1;
  i->cycle_count = 10;
  i->has_argument_descriptor = 1;
  i->comment = "alive";
}

static void     init_ld(t_instr_info *i)
{
  i->name = "ld";
  i->argument_count = 2;
  i->argument_types[0] = ARGUMENT_TYPE_DIRECT;
  i->argument_types[1] = ARGUMENT_TYPE_REGISTER;
  i->code = 2;
  i->cycle_count = 5;
  i->has_argument_descriptor = 1;
  i->comment = "load";
}

static void     init_st(t_instr_info *i)
{
  i->name = "st";
  i->argument_count = 2;
  i->argument_types[0] = ARGUMENT_TYPE_DIRECT;
  i->argument_types[1] = ARGUMENT_TYPE_REGISTER;
  i->code = 3;
  i->cycle_count = 5;
  i->has_argument_descriptor = 1;
  i->comment = "store";
}

static void     init_add(t_instr_info *i)
{
  i->name = "add";
  i->argument_count = 3;
  i->argument_types[0] = ARGUMENT_TYPE_REGISTER;
  i->argument_types[1] = ARGUMENT_TYPE_REGISTER;
  i->argument_types[2] = ARGUMENT_TYPE_REGISTER;
  i->code = 4;
  i->cycle_count = 10;
  i->has_argument_descriptor = 1;
  i->comment = "addition";
}

t_instr_info    *instr_info_get_list_0(t_instr_info *list)
{
  init_live(list++);
  init_ld(list++);
  init_st(list++);
  init_add(list++);
  return (list);
}
