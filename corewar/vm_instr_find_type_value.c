/*
** vm_instr_find_type_value.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 07:41:59 2016 Jamy Bailly
** Last update Sat Mar 26 07:44:53 2016 Jamy Bailly
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
    return (*i->processes->registers[i->value[pos] - 1]);
  return (0);
}
