/*
** vm_free.c for corewar in /home/bailly_j/rendu/corewar/corewar
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Thu Mar 24 23:07:37 2016 Jamy Bailly
** Last update Thu Mar 24 23:10:59 2016 Jamy Bailly
*/

#include <stdlib.h>
#include "vm.h"

void	vm_free(t_vm *vm)
{
  free(vm->programs);
  free(vm->memory);
  free(vm);
}
