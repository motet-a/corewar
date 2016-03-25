/*
** instr_1.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 10:20:40 2016 antoine
** Last update Fri Mar 25 10:20:40 2016 antoine
*/

#include "instr.h"

static void     init_sub(t_instr_info *i)
{
  i->name = "sub";
  i->argument_count = 3;
  i->argument_types[0] = ARGUMENT_TYPE_REGISTER;
  i->argument_types[1] = ARGUMENT_TYPE_REGISTER;
  i->argument_types[2] = ARGUMENT_TYPE_REGISTER;
  i->code = 5;
  i->cycle_count = 10;
  i->has_argument_descriptor = 1;
  i->comment = "soustraction";
}

static void     init_and(t_instr_info *i)
{
  i->name = "and";
  i->argument_count = 3;
  i->argument_types[0] = ARGUMENT_TYPE_DIRECT;
  i->argument_types[1] = ARGUMENT_TYPE_REGISTER;
  i->argument_types[2] = ARGUMENT_TYPE_INDIRECT;
  i->code = 6;
  i->cycle_count = 6;
  i->has_argument_descriptor = 1;
  i->comment = "et (and  r1, r2, r3   r1&r2 -> r3";
}

static void     init_or(t_instr_info *i)
{
  i->name = "or";
  i->argument_count = 3;
  i->argument_types[0] = ARGUMENT_TYPE_DIRECT;
  i->argument_types[1] = ARGUMENT_TYPE_REGISTER;
  i->argument_types[2] = ARGUMENT_TYPE_INDIRECT;
  i->code = 7;
  i->cycle_count = 6;
  i->has_argument_descriptor = 1;
  i->comment = "ou  (or   r1, r2, r3   r1 | r2 -> r3";
}

static void     init_xor(t_instr_info *i)
{
  i->name = "xor";
  i->argument_count = 3;
  i->argument_types[0] = ARGUMENT_TYPE_DIRECT;
  i->argument_types[1] = ARGUMENT_TYPE_REGISTER;
  i->argument_types[2] = ARGUMENT_TYPE_INDIRECT;
  i->code = 8;
  i->cycle_count = 6;
  i->has_argument_descriptor = 1;
  i->comment = "ou (xor  r1, r2, r3   r1^r2 -> r3";
}

t_instr_info    *instr_info_get_list_1(t_instr_info *list)
{
  init_sub(list++);
  init_and(list++);
  init_or(list++);
  init_xor(list++);
  return (list);
}
