/*
** vm_aff.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 04:58:34 2016 Jamy Bailly
** Last update Sat Mar 26 05:35:41 2016 Jamy Bailly
*/

#include "../libcw/print.h"
#include "instructions.h"

void	vm_aff(t_instruction *i)
{
  char	c;

  c = (char) *(i)->process->registers[i->value[0] - 1];
  print_char(c);
}
