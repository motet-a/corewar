/*
** instr.c<asm> for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 15:07:26 2016 antoine
** Last update Fri Mar 25 15:07:26 2016 antoine
*/

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
