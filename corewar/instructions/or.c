/*
** or.c for instructions in /home/antoine/corewar/corewar/instructions
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  lun. mars 28 21:55:15 2016 Antoine Baudrand
** Last update Mon Mar 28 22:07:26 2016 Antoine
*/

#include "instructions.h"
#include "../../libcw/instr.c"
#include "../../libcw/memory.h"

void	vm_or(t_instruction *i)
{
  int	p1;
  int	p2;
  int	out;

  p1 = vm_instr_find_value(i, 0);
  p2 = vm_instr_find_value(i, 1);
  out = p1 | p2;
  i->processes->registers[i->value[2]] = out;
  i->processes->carry = vm_edit_value_carry(out);
}
