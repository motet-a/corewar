/*
** vm_kill_process.c for corewar in /home/antoine/corewar/corewar
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  sam. mars 26 00:03:53 2016 Antoine Baudrand
** Last update sam. mars 26 13:45:16 2016 Antoine Baudrand
*/

#include "vm.h"
#include "stdlib.h"

int    	vm_kill_process(t_vm *vm, t_process *process)
{
  t_process	*processes;
  t_process	*to_kill;

  processes = vm->processes;
  if (processes == process)
    {
      vm->processes = vm->processes->next;
      free(processes);
      return (0);
    }
  else
    {
      while (processes->next != process && processes->next != NULL)
	processes = processes->next;
      if (process->next == process)
	{
	  to_kill = processes->next;
	  processes->next = to_kill->next;
	  free(to_kill);
	  return (0);
	}
      else
	return (-1);
    }
}
