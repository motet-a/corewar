/*
** vm_instr_aff.c for corewar in /home/antoine/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Mar 26 07:41:39 2016 Jamy Bailly
** Last update Mon Mar 28 22:07:46 2016 Antoine
*/

#include "../../libcw/print.h"
#include "instructions.h"

void	vm_aff(t_instruction *i)
{
  char	c;

  c = (char) i->processes->registers[i->value[0] - 1];
  print_char(c);
}
