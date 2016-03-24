/*
** instructions.h for vm in /home/antoine/corewar/src/vm
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  lun. mars 21 23:52:26 2016 Antoine Baudrand
** Last update Tue Mar 22 10:28:30 2016 Antoine
*/

#ifndef INSTRUCTIONS_H_
# define INSTRUCTIONS_H_

#include "vm.h"

void	vm_live(t_process *process);
void	vm_ld(t_process *process);
void	vm_st(t_process *process);
void	vm_add(t_process *process);
void	vm_sub(t_process *process);
void	vm_and(t_process *process);
void	vm_or(t_process *process);
void	vm_xor(t_process *process);
void	vm_zjmp(t_process *process);
void	vm_ldi(t_process *process);
void	vm_sti(t_process *process);
void	vm_fork(t_process *process);
void	vm_lld(t_process *process);
void	vm_lldi(t_process *process);
void	vm_lfork(t_process *process);
void	vm_aff(t_process *process);

#endif /* !INSTRUCTIONS_H_ */
