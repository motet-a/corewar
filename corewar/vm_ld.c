/*
** vm_ld.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 05:42:31 2016 Jamy Bailly
** Last update Sat Mar 26 05:47:55 2016 Jamy Bailly
*/

#include "instructions.h"

void	vm_ld(t_instruction *i)
{
  *i->processes->registers[i->value[1] - 1] = i->value[0];
}
