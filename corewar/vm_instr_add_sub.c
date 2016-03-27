/*
** vm_instr_add_sub.c for corewar in /home/antoine/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 07:40:41 2016 Jamy Bailly
** Last update Sun Mar 27 16:19:49 2016 Jamy Bailly
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
  if (out == 0)
    i->processes->carry = 1;
  else
    i->processes->carry = 0;
}

void	vm_sub(t_instruction *i)
{
  int	p1;
  int	p2;
  int	out;

  p1 = i->processes->registers[i->value[0] - 1];
  p2 = i->processes->registers[i->value[1] - 1];
  out = p1 - p2;
  i->processes->registers[i->value[2]] = p1 - p2;
  if (out == 0)
    i->processes->carry = 1;
  else
    i->processes->carry = 0;
}
