/*
** instr_write.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Mar 27 12:54:09 2016 antoine
** Last update Sun Mar 27 12:54:09 2016 antoine
*/

#include <unistd.h>
#include "asm.h"
#include "../libcw/memory.h"
#include "../libcw/string.h"

static int      write_index_arg(const t_argument *arg, int output_file)
{
  char          buffer[2];

  if (arg->type == ARGUMENT_TYPE_REGISTER)
    return (write(output_file, &arg->value, 1) == 1 ? 0 : -1);
  else
    {
      memory_write_int_16(buffer, arg->value);
      return (write(output_file, buffer, 2) == 2 ? 0 : -1);
    }
}

static int      write_sti(const t_instr *instr, int output_file)
{
  if (argument_write(instr->arguments + 0, output_file))
    return (-1);
  if (write_index_arg(instr->arguments + 1, output_file))
    return (-1);
  if (write_index_arg(instr->arguments + 2, output_file))
    return (-1);
  return (0);
}

static int      write_ldi(const t_instr *instr, int output_file)
{
  if (write_index_arg(instr->arguments + 0, output_file))
    return (-1);
  if (write_index_arg(instr->arguments + 1, output_file))
    return (-1);
  if (argument_write(instr->arguments + 2, output_file))
    return (-1);
  return (0);
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
      if (write(output_file, &descr, 1) != 1)
        return (-1);
    }
  if (string_equals(instr->info->name, "sti"))
    return (write_sti(instr, output_file));
  if (string_equals(instr->info->name, "ldi"))
    return (write_ldi(instr, output_file));
  if (string_equals(instr->info->name, "zjmp"))
    return (write_index_arg(instr->arguments, output_file));
  if (string_equals(instr->info->name, "fork"))
    return (write_index_arg(instr->arguments, output_file));
  i = -1;
  while (++i < instr->info->argument_count)
    if (argument_write(instr->arguments + i, output_file))
      return (-1);
  return (0);
}
