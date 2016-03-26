/*
** vm_instr_find_type_value.c for corewar in /home/antoine/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 07:41:59 2016 Jamy Bailly
** Last update sam. mars 26 12:19:28 2016 Antoine Baudrand
*/

#include "instructions.h"
#include "../libcw/memory.h"

int	vm_instr_find_type_value(t_instruction *i, int pos)
{
  if (i->type_params[pos] == ARGUMENT_TYPE_REGISTER)
    return (i->value[pos]);
  else if (i->type_params[pos] == ARGUMENT_TYPE_DIRECT)
    return (memory_read_int_32(i->memory + i->processes->pc + i->value[pos]));
  else if (i->type_params[pos] == ARGUMENT_TYPE_INDIRECT)
    return (i->processes->registers[i->value[pos] - 1]);
  return (0);
}
