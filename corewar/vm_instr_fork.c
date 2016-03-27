/*
** vm_instr_fork.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Mon Mar 28 00:15:13 2016 Jamy Bailly
** Last update Mon Mar 28 00:31:06 2016 Jamy Bailly
*/

#include "instructions.h"

void	vm_fork(t_instruction *i)
{
  int	p1;
  int	new_pc;

  p1 = i->value[0];
  new_pc = i->processes->pc + p1 % IDX_MOD;
  vm_create_process(i->vm, new_pc, i->processes->program);
}
