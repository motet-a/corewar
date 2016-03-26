/*
** instructions.h for vm in /home/antoine/corewar/src/vm
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  lun. mars 21 23:52:26 2016 Antoine Baudrand
** Last update Sat Mar 26 04:14:21 2016 Jamy Bailly
*/

#ifndef INSTRUCTIONS_H_
# define INSTRUCTIONS_H_

#include "vm.h"

typedef struct	s_instruction
{
  t_process	*process;
  int		type_params[4];
  int		value[4];
  char		*memory;
}		t_instruction;

#include "vm.h"

void	vm_live(t_instruction *i);
void	vm_ld(t_instruction *i);
void	vm_st(t_instruction *i);
void	vm_add(t_instruction *i);
void	vm_sub(t_instruction *i);
void	vm_and(t_instruction *i);
void	vm_or(t_instruction *i);
void	vm_xor(t_instruction *i);
void	vm_zjmp(t_instruction *i);
void	vm_ldi(t_instruction *i);
void	vm_sti(t_instruction *i);
void	vm_fork(t_instruction *i);
void	vm_lld(t_instruction *i);
void	vm_lldi(t_instruction *i);
void	vm_lfork(t_instruction *i);
void	vm_aff(t_instruction *i);

#endif /* !INSTRUCTIONS_H_ */
