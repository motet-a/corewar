/*
** vm_instr_zjmp.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 20:00:55 2016 Jamy Bailly
** Last update Sun Mar 27 14:59:41 2016 Jamy Bailly
*/

#include "instructions.h"
#include "../libcw/memory.h"

void	vm_zjmp(t_instruction *i)
{
  if (i->processes->carry)
      i->processes->pc += vm_instr_find_value(i, 0);
}
