/*
** vm_add_sub.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 06:04:30 2016 Jamy Bailly
** Last update Sat Mar 26 06:17:58 2016 Jamy Bailly
*/

#include "instructions.h"

void	vm_add(t_instruction *i)
{
  int	p1;
  int	p2;
  int	p3;

  p1 = *i->processes->registers[i->value[0] - 1];
  p2 = *i->processes->registers[i->value[1] - 1];
  p3 = *i->processes->registers[i->value[2] - 1];
  p3 = 0;
  p3 = p1 + p2 + p3;
}
