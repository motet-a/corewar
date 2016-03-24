/*
** vm_new.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Thu Mar 24 22:08:43 2016 Jamy Bailly
** Last update Thu Mar 24 22:54:31 2016 Jamy Bailly
*/

#include <stdlib.h>
#include "vm.h"

t_vm	*vm_new(int program_count)
{
  t_vm	*vm;

  if ((vm = malloc(sizeof(t_vm))) == NULL)
    return (NULL);
  vm->cycle = 0;
  vm->cycle_to_die = CYCLE_TO_DIE;
  vm->live_count = 0;
  vm->program_count = program_count;
  if ((vm->programs = malloc(sizeof(t_program) * program_count)) == NULL)
    return (NULL);
  vm->processes = NULL;
  if ((vm_init_memory(vm->memory)) == -1)
    return (NULL);
  return (vm);
}
