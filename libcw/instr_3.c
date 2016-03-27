/*
** instr_3.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 10:22:43 2016 antoine
** Last update Fri Mar 25 10:22:43 2016 antoine
*/

#include "instr_private.h"

static void     init_lld(t_instr_info *i)
{
  i->name = "lld";
  i->argument_count = 2;
  i->argument_types[0] = T_DIR | T_IND;
  i->argument_types[1] = T_REG;
  i->code = 13;
  i->cycle_count = 10;
  i->has_argument_descriptor = 1;
  i->comment = "long load";
}

static void     init_lldi(t_instr_info *i)
{
  i->name = "lldi";
  i->argument_count = 3;
  i->argument_types[0] = T_REG | T_DIR | T_IND;
  i->argument_types[1] = T_DIR | T_REG;
  i->argument_types[2] = T_REG;
  i->code = 14;
  i->cycle_count = 50;
  i->has_argument_descriptor = 1;
  i->comment = "long load index";
}

static void     init_lfork(t_instr_info *i)
{
  i->name = "lfork";
  i->argument_count = 1;
  i->argument_types[0] = T_DIR;
  i->code = 15;
  i->cycle_count = 1000;
  i->has_argument_descriptor = 0;
  i->comment = "long fork";
}

static void     init_aff(t_instr_info *i)
{
  i->name = "aff";
  i->argument_count = 1;
  i->argument_types[0] = T_REG;
  i->code = 16;
  i->cycle_count = 2;
  i->has_argument_descriptor = 1;
  i->comment = "aff";
}

t_instr_info    *instr_info_get_list_3(t_instr_info *list)
{
  init_lldi(list++);
  init_lfork(list++);
  init_aff(list++);
  init_lld(list++);
  return (list);
}
