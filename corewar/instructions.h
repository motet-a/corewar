/*
** instructions.h for  in /Users/westery/Documents/tek1/CPE/corewar/corewar/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Sun Mar 27 21:34:39 2016 Valentin Pichard
** Last update Sun Mar 27 21:34:41 2016 Valentin Pichard
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
  t_vm			*vm;
}			t_instruction;

/*
** Instructions of corewar. See subject for more information.
** TODO vm_live, vm_sti, vm_fork, vm_lld, vm_lldi, vm_lfork
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
** Find the value via the type of parameter and return value
*/
int	vm_instr_find_value(t_instruction *i, int pos);

/*
** Find the address in memory via the type of parameter and return value
*/
int	vm_instr_find_address(t_instruction *i, int pos);

/*
** write the value in memory via the type of parameter
*/
void	vm_instr_write_value(t_instruction *i, int pos, int value, int relative);

/*
** Find the value to edit carry
*/
int	vm_edit_value_carry(int out);

#endif /* !INSTRUCTIONS_H_ */
