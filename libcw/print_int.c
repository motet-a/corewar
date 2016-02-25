/*
** print_int.c for corewar in /home/bailly_j/rendu/corewar/libcw
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Thu Feb 25 15:19:21 2016 Jamy Bailly
** Last update Thu Feb 25 20:51:27 2016 Jamy Bailly
*/

#include <unistd.h>
#include "print.h"

void	print_uint_file(unsigned long n, int file_descriptor)
{
  char	c;

  if (n >= 10)
    print_uint_file(n / 10, file_descriptor);
  c = n % 10 + '0';
  write(file_descriptor, &c, 1);
}

void	print_int_file(long n, int file_descriptor)
{
  if (n < 0)
    {
      write(file_descriptor, "-", 1);
      print_uint_file((unsigned long) -n, file_descriptor);
    }
  else
    print_uint_file((unsigned long) n, file_descriptor);
}

void	print_uint(unsigned long n)
{
  print_uint_file(n, STDOUT_FILENO);
}

void	print_int(long n)
{
  print_int_file(n, STDOUT_FILENO);
}
