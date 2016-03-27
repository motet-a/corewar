/*
** vm_instr_ld.c for corewar in /home/antoine/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 07:42:29 2016 Jamy Bailly
** Last update Sun Mar 27 16:57:08 2016 Jamy Bailly
*/

#include "instructions.h"

void	vm_ld(t_instruction *i)
{
  int	p1;

  p1 = vm_instr_find_value(i, 0);
  i->processes->registers[i->value[1] - 1] = p1;
  i->processes->carry = vm_edit_value_carry(p1);
}
