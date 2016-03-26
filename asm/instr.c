/*
** instr.c<asm> for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 15:07:26 2016 antoine
** Last update Fri Mar 25 15:07:26 2016 antoine
*/

#include <unistd.h>
#include "../libcw/string.h"
#include "../libcw/print.h"
#include "asm.h"

void            instr_free(t_instr *instr)
{
  int           i;

  i = -1;
  while (++i < instr->info->argument_count)
    argument_free(instr->arguments + i);
}

void            instr_print(const t_instr *instr)
{
  int           i;

  position_print(&instr->position, STDOUT_FILENO);
  print_string("\t");
  print_int(instr_get_size(instr));
  print_string("\t");
  print_int(instr_get_arg_descr(instr));
  print_string("\t");
  print_string(instr->info->name);
  print_string(" ");
  i = -1;
  while (++i < instr->info->argument_count)
    {
      if (i)
        print_string(", ");
      argument_print(instr->arguments + i);
    }
  print_string("\n");
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

  size = 1;
  if (!instr->info->has_argument_descriptor)
    return (size + get_args_size_special(instr));
  size++;
  i = -1;
  while (++i < instr->info->argument_count)
    size += argument_get_size(instr->arguments + i);
  return (size);
}

unsigned char   instr_get_arg_descr(const t_instr *instr)
{
  int           i;
  unsigned char descr;

  descr = 0;
  i = -1;
  while (++i < instr->info->argument_count)
    {
      descr |= argument_get_descr(instr->arguments + i) << (3 - i) * 2;
    }
  return (descr);
}

int             instr_write(const t_instr *instr, int output_file)
{
  int           i;
  char          descr;

  if (write(output_file, &instr->info->code, 1) != 1)
    return (-1);
  if (instr->info->has_argument_descriptor)
    {
      descr = instr_get_arg_descr(instr);
      if (write(output_file, &instr->info->code, 1) != 1)
        return (-1);
    }
  i = -1;
  while (++i < instr->info->argument_count)
    if (argument_write(instr->arguments + i, output_file))
      return (-1);
  return (0);
}
