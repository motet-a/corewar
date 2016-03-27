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
