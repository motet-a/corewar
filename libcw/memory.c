/*
** memory.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 16:04:03 2016 antoine
** Last update Fri Feb 26 16:04:03 2016 antoine
*/

#include "memory.h"

int     memory_read_int_16(const char *memory)
{
  return (memory[1] + (memory[0] << 8));
}

long    memory_read_int_32(const char *memory)
{
  return (memory[3] +
          (memory[2] << 8) +
          (memory[1] << 16) +
          (memory[0] << 24));
}

void    memory_write_int_16(char *memory, int n)
{
  int   i;

  i = -1;
  while (++i < 2)
    {
      memory[1 - i] = (n >> (i * 8)) & 0xff;
    }
}

void    memory_write_int_32(char *memory, long n)
{
  int   i;

  i = -1;
  while (++i < 4)
    {
      memory[3 - i] = (n >> (i * 8)) & 0xff;
    }
}
