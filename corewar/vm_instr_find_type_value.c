/*
** vm_instr_find_type_value.c for corewar in /home/antoine/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 07:41:59 2016 Jamy Bailly
** Last update Sun Mar 27 19:03:24 2016 Jamy Bailly
*/

#include "instructions.h"
#include "../libcw/memory.h"

int	vm_instr_find_value(t_instruction *i, int pos)
{
  int	relative;

  if (i->type_params[pos] == ARGUMENT_TYPE_REGISTER)
    return (i->processes->registers[i->value[pos] - 1]);
  else if (i->type_params[pos] == ARGUMENT_TYPE_DIRECT)
    return (i->value[pos]);
  else if (i->type_params[pos] == ARGUMENT_TYPE_INDIRECT)
    {
      relative = i->processes->pc + (i->value[pos] % IDX_MOD);
      return (memory_read_int_32(i->memory + relative));
    }
  return (0);
}
