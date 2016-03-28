/*
** sub.c for instructions in /home/antoine/corewar/corewar/instructions
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  lun. mars 28 21:53:35 2016 Antoine Baudrand
** Last update Mon Mar 28 22:07:24 2016 Antoine
*/

#include "instructions.h"

void	vm_sub(t_instruction *i)
{
  int	p1;
  int	p2;
  int	out;

  p1 = i->processes->registers[i->value[0] - 1];
  p2 = i->processes->registers[i->value[1] - 1];
  out = p1 - p2;
  i->processes->registers[i->value[2]] = p1 - p2;
  i->processes->carry = vm_edit_value_carry(out);
}
