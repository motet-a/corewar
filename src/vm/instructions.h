/*
** instructions.h for vm in /home/antoine/corewar/src/vm
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  lun. mars 21 23:52:26 2016 Antoine Baudrand
** Last update Tue Mar 22 00:12:36 2016 Valentin Pichard
*/

#ifndef INSTRUCTIONS_H_
# define INSTRUCTIONS_H_

#include "vm.h"

void	live(t_process *process);
void	ld(t_process *process);
void	st(t_process *process);
void	add(t_process *process);
void	sub(t_process *process);
void	and(t_process *process);
void	or(t_process *process);
void	xor(t_process *process);
void	zjmp(t_process *process);
void	ldi(t_process *process);
void	sti(t_process *process);
void	fork(t_process *process);
void	lld(t_process *process);
void	lldi(t_process *process);
void	lfork(t_process *process);
void	aff(t_process *process);

#endif /* !INSTRUCTIONS_H_ */
