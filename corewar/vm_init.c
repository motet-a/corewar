/*
** vm_initialize.c for corewar in /home/antoine/corewar/corewar
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Mon Mar 21 23:36:45 2016 Valentin Pichard
** Last update Mon Mar 28 22:02:58 2016 Antoine
*/

#include <stdlib.h>
#include "vm.h"

static int      init_memory(t_vm *vm)
{
  int		i;

  if ((vm->memory = malloc(sizeof(char) * MEMORY_SIZE)) == NULL)
    return (-1);
  i = 0;
  while (i < MEMORY_SIZE)
    {
      vm->memory[i] = 0;
      i++;
    }
  return (0);
}

int             vm_init(t_vm *vm)
{
  vm->cycle = 0;
  vm->cycle_to_die = CYCLE_TO_DIE;
  vm->live_count = 0;
  vm->program_count = 2;
  vm->programs = NULL;
  vm->processes = NULL;
  if ((init_memory(vm)) == -1)
    return (-1);
  return (0);
}
