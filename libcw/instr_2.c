/*
** instr_2.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 10:21:29 2016 antoine
** Last update Fri Mar 25 10:21:29 2016 antoine
*/

#include "instr.h"

static void     init_zjmp(t_instr_info *i)
{
  i->name = "zjmp";
  i->argument_count = 1;
  i->argument_types[0] = ARGUMENT_TYPE_DIRECT;
  i->code = 9;
  i->cycle_count = 20;
  i->has_argument_descriptor = 1;
  i->comment = "jump if zero";
}

static void     init_ldi(t_instr_info *i)
{
  i->name = "ldi";
  i->argument_count = 3;
  i->argument_types[0] = ARGUMENT_TYPE_DIRECT;
  i->argument_types[1] = ARGUMENT_TYPE_REGISTER;
  i->argument_types[2] = ARGUMENT_TYPE_INDIRECT;
  i->code = 10;
  i->cycle_count = 25;
  i->has_argument_descriptor = 1;
  i->comment = "load index";
}

static void     init_sti(t_instr_info *i)
{
  i->name = "sti";
  i->argument_count = 3;
  i->argument_types[0] = ARGUMENT_TYPE_DIRECT;
  i->argument_types[1] = ARGUMENT_TYPE_REGISTER;
  i->argument_types[2] = ARGUMENT_TYPE_INDIRECT;
  i->code = 11;
  i->cycle_count = 25;
  i->has_argument_descriptor = 1;
  i->comment = "store index";
}

static void     init_fork(t_instr_info *i)
{
  i->name = "fork";
  i->argument_count = 1;
  i->argument_types[0] = ARGUMENT_TYPE_DIRECT;
  i->code = 12;
  i->cycle_count = 800;
  i->has_argument_descriptor = 1;
  i->comment = "fork";
}

t_instr_info    *instr_info_get_list_2(t_instr_info *list)
{
  init_zjmp(list++);
  init_ldi(list++);
  init_sti(list++);
  init_fork(list++);
  return (list);
}
