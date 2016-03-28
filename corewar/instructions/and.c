/*
** and.c for instructions in /home/antoine/corewar/corewar/instructions
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 06:56:51 2016 Jamy Bailly
** Last update Mon Mar 28 22:07:29 2016 Antoine
*/

#include "instructions.h"
#include "../../libcw/instr.c"
#include "../../libcw/memory.h"

void	vm_and(t_instruction *i)
{
  int	p1;
  int	p2;
  int	out;

  p1 = vm_instr_find_value(i, 0);
  p2 = vm_instr_find_value(i, 1);
  out = p1 & p2;
  i->processes->carry = vm_edit_value_carry(out);
}
