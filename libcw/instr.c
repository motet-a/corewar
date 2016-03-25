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

static void     init_lld(t_instr_info *i)
{
  i->name = "lld";
  i->argument_count = 2;
  i->argument_types[0] = ARGUMENT_TYPE_DIRECT;
  i->argument_types[1] = ARGUMENT_TYPE_REGISTER;
  i->code = 13;
  i->cycle_count = 10;
  i->has_argument_descriptor = 1;
  i->comment = "long load";
}

static void     init_lldi(t_instr_info *i)
{
  i->name = "lldi";
  i->argument_count = 3;
  i->argument_types[0] = ARGUMENT_TYPE_DIRECT;
  i->argument_types[1] = ARGUMENT_TYPE_REGISTER;
  i->argument_types[2] = ARGUMENT_TYPE_INDIRECT;
  i->code = 14;
  i->cycle_count = 50;
  i->has_argument_descriptor = 1;
  i->comment = "long load index";
}

static void     init_lfork(t_instr_info *i)
{
  i->name = "lfork";
  i->argument_count = 1;
  i->argument_types[0] = ARGUMENT_TYPE_DIRECT;
  i->code = 15;
  i->cycle_count = 1000;
  i->has_argument_descriptor = 1;
  i->comment = "long fork";
}

static void     init_aff(t_instr_info *i)
{
  i->name = "aff";
  i->argument_count = 1;
  i->argument_types[0] = ARGUMENT_TYPE_REGISTER;
  i->code = 16;
  i->cycle_count = 2;
  i->has_argument_descriptor = 1;
  i->comment = "aff";
}

static void     init_nothing(t_instr_info *i)
{
  i->name = 0;
  i->argument_count = 0;
  i->argument_types[0] = 0;
  i->code = 0;
  i->cycle_count = 0;
  i->has_argument_descriptor = 0;
  i->comment = 0;
}

void            instr_info_get_list(t_instr_info *list)
{
  init_live(list++);
  init_ld(list++);
  init_st(list++);
  init_add(list++);
  init_sub(list++);
  init_and(list++);
  init_or(list++);
  init_xor(list++);
  init_zjmp(list++);
  init_ldi(list++);
  init_sti(list++);
  init_fork(list++);
  init_lldi(list++);
  init_lfork(list++);
  init_aff(list++);
  init_nothing(list++);
  init_lld(list++);
  list->name = NULL;
}
