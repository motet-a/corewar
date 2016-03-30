/*
** vm_instr_write_int.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sun Mar 27 19:54:45 2016 Jamy Bailly
** Last update Mon Mar 28 22:07:23 2016 Antoine
*/

#include "instructions.h"
#include "../../libcw/memory.h"

void	vm_instr_write_value(t_instruction *i, int pos, int value, int relative)
{
  if (i->type_params[pos] == ARGUMENT_TYPE_REGISTER)
    i->processes->registers[i->value[pos] - 1] = value;
  else if (i->type_params[pos] == ARGUMENT_TYPE_DIRECT)
    memory_write_int_32(i->vm->memory, value);
  else if (i->type_params[pos] == ARGUMENT_TYPE_INDIRECT)
    memory_write_int_32(i->vm->memory + relative, value);
}