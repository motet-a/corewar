/*
** vm_instr_add_sub.c for instructions in /home/antoine/corewar/corewar/instructions
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 07:40:41 2016 Jamy Bailly
** Last update Mon Mar 28 22:07:30 2016 Antoine
*/

#include "instructions.h"

void	vm_add(t_instruction *i)
{
  int	p1;
  int	p2;
  int	out;

  p1 = i->processes->registers[i->value[0] - 1];
  p2 = i->processes->registers[i->value[1] - 1];
  out = p1 + p2;
  i->processes->registers[i->value[2]]=  out;
  i->processes->carry = vm_edit_value_carry(out);
}
