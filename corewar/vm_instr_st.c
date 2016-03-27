/*
** vm_instr_st.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sun Mar 27 19:25:01 2016 Jamy Bailly
** Last update Sun Mar 27 20:13:03 2016 Jamy Bailly
*/

#include "instructions.h"
#include "../libcw/memory.h"

void	vm_st(t_instruction *i)
{
  int	p1;

  p1 = vm_instr_find_value(i, 0);
  vm_instr_write_value(i, 0, p1);
}
