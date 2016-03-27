/*
** instr_size.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Mar 27 12:56:09 2016 antoine
** Last update Sun Mar 27 12:56:09 2016 antoine
*/

#include "asm.h"
#include "../libcw/string.h"
#include "../libcw/print.h"

static int      get_sti_size(const t_instr *instr)
{
  int           size;

  size = 2;
  size += argument_get_size(instr->arguments);
  size += (instr->arguments[1].type == ARGUMENT_TYPE_REGISTER) ? 1 : 2;
  size += (instr->arguments[2].type == ARGUMENT_TYPE_REGISTER) ? 1 : 2;
  return (size);
}

static int      get_ldi_size(const t_instr *instr)
{
  int           size;

  size = 2;
  size += (instr->arguments[0].type == ARGUMENT_TYPE_REGISTER) ? 1 : 2;
  size += (instr->arguments[1].type == ARGUMENT_TYPE_REGISTER) ? 1 : 2;
  size += argument_get_size(instr->arguments + 2);
  return (size);
}

static int      get_args_size_special(const t_instr *instr)
{
  const char    *name;

  name = instr->info->name;
  if (string_equals(name, "live"))
    return (4);
  if (string_equals(name, "zjmp"))
    return (VM_INDIRECT_ARGUMENT_SIZE);
  if (string_equals(name, "fork") || string_equals(name, "lfork"))
    return (VM_INDIRECT_ARGUMENT_SIZE);
  print_string_err("get_args_size_special(): error\n");
  return (-1);
}

int             instr_get_size(const t_instr *instr)
{
  int           size;
  int           i;

  if (string_equals(instr->info->name, "sti"))
    return (get_sti_size(instr));
  if (string_equals(instr->info->name, "ldi"))
    return (get_ldi_size(instr));
  size = 1;
  if (!instr->info->has_argument_descriptor)
    return (size + get_args_size_special(instr));
  size++;
  i = -1;
  while (++i < instr->info->argument_count)
    size += argument_get_size(instr->arguments + i);
  return (size);
}
