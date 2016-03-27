/*
** vm_instr_write_int.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sun Mar 27 19:54:45 2016 Jamy Bailly
** Last update Sun Mar 27 20:18:19 2016 Jamy Bailly
*/

#include "instructions.h"
#include "../libcw/memory.h"

void	vm_instr_write_value(t_instruction *i, int pos, int value)
{
  int	relative;

  if (i->type_params[pos] == ARGUMENT_TYPE_REGISTER)
    i->processes->registers[i->value[pos]] = value;
  else if (i->type_params[pos] == ARGUMENT_TYPE_DIRECT)
    memory_write_int_32(i->memory, value);
  else if (i->type_params[pos] == ARGUMENT_TYPE_INDIRECT)
    {
      relative = i->processes->pc + (i->value[pos] % IDX_MOD);
      memory_write_int_32(i->memory + relative, value);
    }
}
