/*
** instructions.h for vm in /home/antoine/corewar/src/vm
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  lun. mars 21 23:52:26 2016 Antoine Baudrand
** Last update Sat Mar 26 07:37:36 2016 Jamy Bailly
*/

#ifndef INSTRUCTIONS_H_
# define INSTRUCTIONS_H_

#include "vm.h"
#include "../libcw/instr.h"

typedef struct		s_instruction
{
  t_process		*processes;
  int			params_count;
  t_argument_type	type_params[4];
  int			value[4];
  char			*memory;
}			t_instruction;

#include "vm.h"

/*
** Instructions of corewar. See subject for more information.
** TODO vm_live, vm_st, vm_and, vm_and, vm_or, vm_xor,
** vm_zjmp, vm_ldi, vm_sti, vm_fork, vm_lld, vm_lldi, vm_lfork
*/
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

/*
**  Find the type of the value and return value
*/
int	vm_intsr_find_type_value(t_instruction *, int pos);

#endif /* !INSTRUCTIONS_H_ */
