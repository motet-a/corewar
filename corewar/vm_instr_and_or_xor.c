/*
** vm_intsr_and_or.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 06:56:51 2016 Jamy Bailly
** Last update Sun Mar 27 15:50:47 2016 Jamy Bailly
*/

#include "instructions.h"
#include "../libcw/instr.c"
#include "../libcw/memory.h"

void	vm_and(t_instruction *i)
{
  int	p1;
  int	p2;

  p1 = vm_instr_find_value(i, 0);
  p2 = vm_instr_find_value(i, 1);
  i->processes->registers[i->value[2]] = p1 & p2;
}

void	vm_or(t_instruction *i)
{
  int	p1;
  int	p2;

  p1 = vm_instr_find_value(i, 0);
  p2 = vm_instr_find_value(i, 1);
  i->processes->registers[i->value[2]] = p1 | p2;
}

void	vm_xor(t_instruction *i)
{
  int	p1;
  int	p2;

  p1 = vm_instr_find_value(i, 0);
  p2 = vm_instr_find_value(i, 1);
  i->processes->registers[i->value[2]] = p1 ^ p2;
}
