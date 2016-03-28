/*
** vm_instr_ld.c for corewar in /home/antoine/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 07:42:29 2016 Jamy Bailly
** Last update Mon Mar 28 22:07:31 2016 Antoine
*/

#include "instructions.h"
#include "../../libcw/memory.h"

void	vm_ld(t_instruction *i)
{
  int	out;

  out = vm_instr_find_value(i, 0);
  i->processes->registers[i->value[1] - 1] = out;
  i->processes->carry = vm_edit_value_carry(out);
}

void	vm_lld(t_instruction *i)
{
  int	out;

  out = vm_instr_find_value_no_idx(i, 0);
  i->processes->registers[i->value[1] - 1] = out;
  i->processes->carry = vm_edit_value_carry(out);
}

void	vm_ldi(t_instruction *i)
{
  int	p1;
  int	p2;
  int	out;

  p1 = vm_instr_find_address(i, 0);
  p2 = vm_instr_find_address(i, 1);
  out = memory_read_int_32(i->vm->memory + p1 + p2);
  i->processes->registers[i->value[2] - 1] = out;
  i->processes->carry = vm_edit_value_carry(out);
}

void	vm_lldi(t_instruction *i)
{
  int	p1;
  int	p2;
  int	out;

  p1 = vm_instr_find_address_no_idx(i, 0);
  p2 = vm_instr_find_address_no_idx(i, 1);
  out = memory_read_int_32(i->vm->memory + p1 + p2);
  i->processes->registers[i->value[2] - 1] = out;
  i->processes->carry = vm_edit_value_carry(out);
}
