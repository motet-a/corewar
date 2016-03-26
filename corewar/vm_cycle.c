/*
** vm_cycle.c for corewar in /home/antoine/corewar/corewar
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  sam. mars 26 17:17:59 2016 Antoine Baudrand
** Last update sam. mars 26 18:54:19 2016 Antoine Baudrand
*/

#include "vm.h"

/*
** TODO
*/
static void	vm_process_cycle(t_vm *vm, t_process *process)
{
  (void) vm;
  (void) process;
}

int    	vm_cycle(t_vm *vm)
{
  t_process	*processes;
  t_process	*to_kill;

  vm->cycle += 1;
  processes = vm->processes;
  if (processes == NULL)
    return (0);
  while (processes != NULL)
    {
      if (processes->program->alive)
	{
	  vm_process_cycle(vm, processes);
	  processes = processes->next;
	}
      else
	{
	  to_kill = processes;
	  processes = processes->next;
	  vm_kill_process(vm, to_kill);
	}
    }
  return (1);
}
