/*
** vm_initialize.c for corewar in /home/antoine/corewar/corewar
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Mon Mar 21 23:36:45 2016 Valentin Pichard
** Last update Sun Mar 27 21:52:47 2016 Valentin Pichard
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
  vm->program_count = 0;
  vm->programs = NULL;
  vm->processes = NULL;
  if ((init_memory(vm)) == -1)
    return (-1);
  return (0);
}

void                    program_opt_init(t_program_opt *program)
{
  program->name = NULL;
  program->number = -1;
  program->address = -1;
}
