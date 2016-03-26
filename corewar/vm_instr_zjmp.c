/*
** vm_instr_zjmp.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 20:00:55 2016 Jamy Bailly
** Last update Sat Mar 26 20:22:03 2016 Jamy Bailly
*/

#include "instructions.h"
#include "../libcw/memory.h"

void	vm_zjmp(t_instruction *i)
{
  char	*pos;

  if (i->processes->carry)
    {
      pos = i->memory + i->processes->pc + i->value[0];
      i->processes->pc += memory_read_int_32(pos);
    }
}
