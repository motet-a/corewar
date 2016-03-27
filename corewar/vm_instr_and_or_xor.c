/*
** vm_intsr_and_or.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 06:56:51 2016 Jamy Bailly
** Last update Sun Mar 27 16:50:25 2016 Jamy Bailly
*/

#include "instructions.h"
#include "../libcw/instr.c"
#include "../libcw/memory.h"

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

void	vm_xor(t_instruction *i)
{
  int	p1;
  int	p2;
  int	out;

  p1 = vm_instr_find_value(i, 0);
  p2 = vm_instr_find_value(i, 1);
  out = p1 ^ p2;
  i->processes->registers[i->value[2]] = out;
  i->processes->carry = vm_edit_value_carry(out);
}
