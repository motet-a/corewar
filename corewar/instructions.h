/*
** instructions.h for vm in /home/antoine/corewar/src/vm
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  lun. mars 21 23:52:26 2016 Antoine Baudrand
** Last update Sat Mar 26 04:05:31 2016 Jamy Bailly
*/

#ifndef INSTRUCTIONS_H_
# define INSTRUCTIONS_H_

#include "vm.h"

void	vm_live(t_process *process);
void	vm_ld(t_process *process, int type_params[4], int value[4]);
void	vm_st(t_process *process, int type_params[4], int value[4]);
void	vm_add(t_process *process, int type_params[4], int value[4]);
void	vm_sub(t_process *process, int type_params[4], int value[4]);
void	vm_and(t_process *process, int type_params[4], int value[4]);
void	vm_or(t_process *process, int type_params[4], int value[4]);
void	vm_xor(t_process *process, int type_params[4], int value[4]);
void	vm_zjmp(t_process *process, int type_params[4], int value[4]);
void	vm_ldi(t_process *process, int type_params[4], int value[4]);
void	vm_sti(t_process *process, int type_params[4], int value[4]);
void	vm_fork(t_process *process, int type_params[4], int value[4]);
void	vm_lld(t_process *process, int type_params[4], int value[4]);
void	vm_lldi(t_process *process, int type_params[4], int value[4]);
void	vm_lfork(t_process *process, int type_params[4], int value[4]);
void	vm_aff(t_process *process, int type_params[4], int value[4]);

#endif /* !INSTRUCTIONS_H_ */
