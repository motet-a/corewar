/*
** vm_initialize.c for corewar in /home/antoine/corewar/corewar
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Mon Mar 21 23:36:45 2016 Valentin Pichard
** Last update dim. mars 27 14:35:40 2016 Antoine Baudrand
*/

#include <stdlib.h>
#include "options.h"
#include "vm.h"

void            init_vm_options(t_option *options)
{
  int           i;

  i = 0;
  options[i].name = "dump";
  options[i++].has_value = 1;
  options[i].name = "n";
  options[i++].has_value = 1;
  options[i].name = "a";
  options[i++].has_value = 1;
  options[i].name = NULL;
}

t_vm		*init_new_vm(int program_count)
{
  t_vm		*vm;

  if ((vm = malloc(sizeof(t_vm))) == NULL)
    return (NULL);
  vm->cycle = 0;
  vm->cycle_to_die = CYCLE_TO_DIE;
  vm->live_count = 0;
  vm->program_count = program_count;
  if ((vm->programs = malloc(sizeof(t_program) * program_count)) == NULL)
    return (NULL);
  vm->processes = NULL;
  if ((init_vm_memory(vm)) == -1)
    return (NULL);
  return (vm);
}

int		init_vm_memory(t_vm *vm)
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
