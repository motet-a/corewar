/*
** main.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 29 17:34:08 2016 antoine
** Last update Wed Mar 16 13:38:39 2016 Valentin Pichard
*/

#include "../libcw/print.h"
#include "vm.h"

int	main(int argc, char **argv)
{
  if ((argc % 3) - 2 != 0)
    print_usage(argv[0]);
  return (0);
}
