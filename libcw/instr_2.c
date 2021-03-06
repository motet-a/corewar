/*
** instr_2.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 10:21:29 2016 antoine
** Last update Fri Mar 25 10:21:29 2016 antoine
*/

#include "instr_private.h"

static void     init_zjmp(t_instr_info *i)
{
  i->name = "zjmp";
  i->argument_count = 1;
  i->argument_types[0] = T_DIR;
  i->code = 9;
  i->cycle_count = 20;
  i->has_argument_descriptor = 0;
  i->comment = "jump if zero";
}

static void     init_ldi(t_instr_info *i)
{
  i->name = "ldi";
  i->argument_count = 3;
  i->argument_types[0] = T_REG | T_DIR | T_IND;
  i->argument_types[1] = T_DIR | T_REG;
  i->argument_types[2] = T_REG;
  i->code = 10;
  i->cycle_count = 25;
  i->has_argument_descriptor = 1;
  i->comment = "load index";
}

static void     init_sti(t_instr_info *i)
{
  i->name = "sti";
  i->argument_count = 3;
  i->argument_types[0] = T_REG;
  i->argument_types[1] = T_REG | T_DIR | T_IND;
  i->argument_types[2] = T_DIR | T_REG;
  i->code = 11;
  i->cycle_count = 25;
  i->has_argument_descriptor = 1;
  i->comment = "store index";
}

static void     init_fork(t_instr_info *i)
{
  i->name = "fork";
  i->argument_count = 1;
  i->argument_types[0] = T_DIR;
  i->code = 12;
  i->cycle_count = 800;
  i->has_argument_descriptor = 0;
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
