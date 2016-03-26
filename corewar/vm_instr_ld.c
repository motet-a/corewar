/*
** vm_instr_ld.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 07:42:29 2016 Jamy Bailly
** Last update Sat Mar 26 08:39:22 2016 Jamy Bailly
*/

#include "instructions.h"

void	vm_ld(t_instruction *i)
{
  int	p1;

  p1 = vm_instr_find_type_value(i, 0);
  *i->processes->registers[i->value[1] - 1] = p1;
}
