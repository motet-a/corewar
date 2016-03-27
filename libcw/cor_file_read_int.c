/*
** cor_file_read_int.c for libcw in /home/antoine/corewar/libcw
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  dim. mars 27 14:50:25 2016 Antoine Baudrand
** Last update dim. mars 27 14:55:01 2016 Antoine Baudrand
*/

#include <unistd.h>
#include "cor_file_private.h"
#include "memory.h"

int             cor_file_read_int_16(int input_file, int *result)
{
  char          buffer[2];

  if (read(input_file, buffer, sizeof(buffer)) != sizeof(buffer))
    return (-1);
  *result = memory_read_int_16(buffer);
  return (0);
}

int             cor_file_read_int_32(int input_file, long *result)
{
  char          buffer[4];

  if (read(input_file, buffer, sizeof(buffer)) != sizeof(buffer))
    return (-1);
  *result = memory_read_int_32(buffer);
  return (0);
}
