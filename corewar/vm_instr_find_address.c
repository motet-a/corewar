/*
** vm_instr_find_address.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sun Mar 27 17:31:56 2016 Jamy Bailly
** Last update Sun Mar 27 17:51:08 2016 Jamy Bailly
*/

#include "instructions.h"

int	vm_instr_find_address(t_instruction *i, int pos)
{
  if (i->type_params[pos] == ARGUMENT_TYPE_DIRECT)
    return (i->value[pos]);
  else if (i->type_params[pos] == ARGUMENT_TYPE_INDIRECT)
    return (i->processes->pc + i->value[pos]);
  return (0);
}
