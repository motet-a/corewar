/*
** vm_memory.c for vm in /home/antoine/corewar/src/vm
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Wed Mar 23 23:41:31 2016 Jamy Bailly
** Last update jeu. mars 24 13:39:51 2016 Antoine Baudrand
*/

#include <stdlib.h>
#include "vm.h"

int	vm_init_memory(char *memory)
{
  int	i;

  i = 0;
  if ((memory = malloc(sizeof(char) * MEMORY_SIZE)) == NULL)
    return (-1);
  while (i < MEMORY_SIZE)
    {
      i[memory] = 0;
      i++;
    }
  return (0);
}
