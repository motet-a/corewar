/*
** vm_create_process.c for corewar in /home/antoine/corewar/corewar
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  sam. mars 26 00:03:04 2016 Antoine Baudrand
** Last update dim. mars 27 13:18:38 2016 Antoine Baudrand
*/

#include "stdlib.h"
#include "unistd.h"
#include "vm.h"
#include "../libcw/print.h"

static t_process	*get_last_process(t_process *processes)
{
  while (processes->next != NULL)
    processes = processes->next;
  return (processes);
}

void		vm_create_process(t_vm *vm, int pc, t_program *program)
{
  t_process	*new;

  if (!(new = malloc(sizeof(t_process))))
    {
      print_string_err("can't malloc\n");
      exit(-1);
    }
  new->pc = pc;
  new->carry = 1;
  new->remaining_cycles = 0;
  new->program = program;
  new->next = NULL;
  if (vm->processes != NULL)
    get_last_process(vm->processes)->next = new;
  else
    vm->processes = new;
}
