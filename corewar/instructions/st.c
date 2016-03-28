/*
** vm_instr_st.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sun Mar 27 19:25:01 2016 Jamy Bailly
** Last update Mon Mar 28 22:07:25 2016 Antoine
*/

#include "instructions.h"
#include "../../libcw/memory.h"

void	vm_st(t_instruction *i)
{
  int	p1;
  int	p2;

  p1 = vm_instr_find_value(i, 0);
  p2 = vm_instr_find_value(i, 1);
  vm_instr_write_value(i, 1, p1, p2);
}

void	vm_sti(t_instruction *i)
{
  int	p1;
  int	p2;
  int	p3;

  p1 = vm_instr_find_value(i, 0);
  p2 = vm_instr_find_value(i, 1);
  p3 = vm_instr_find_value(i, 2);
  i->type_params[3] = ARGUMENT_TYPE_INDIRECT;
  vm_instr_write_value(i, 3, p1, p2 + p3);
}
