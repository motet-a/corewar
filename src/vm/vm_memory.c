/*
** vm_memory.c for corewar in /home/bailly_j/rendu/corewar/src/vm
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Wed Mar 23 23:41:31 2016 Jamy Bailly
** Last update Wed Mar 23 23:48:28 2016 Jamy Bailly
*/

#include <stdlib.h>
#include "vm.h"

int	create_memory(char *memory)
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

void	free_memory(char *memory)
{
  free(memory);
}
