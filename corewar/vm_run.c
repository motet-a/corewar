/*
** vm_run.c for corewar in /home/antoine/corewar/corewar
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  dim. mars 27 23:33:03 2016 Antoine Baudrand
** Last update dim. mars 27 23:43:54 2016 Antoine Baudrand
*/

#include "vm.h"

void	vm_run(t_vm *vm)
{
  while (vm_cycle(vm))
    {
      if (vm->live_count > NBR_LIVE)
	{
	  vm->live_count = 0;
	  vm->cycle_to_die -= CYCLE_DELTA;
	}
    }
}
