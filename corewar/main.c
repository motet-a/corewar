/*
** main.c for corewar in /home/antoine/corewar/corewar
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 29 17:34:08 2016 antoine
** Last update Mon Mar 28 22:03:48 2016 Antoine
*/

#include <stdlib.h>
#include "../libcw/print.h"
#include "../libcw/instr.h"
#include "../libcw/string.h"
#include "../libcw/parse_int.h"
#include "vm.h"

int			main(int argc, char **argv)
{
  const char		*program_name;
  t_vm                  vm;

  program_name = argv[0];
  vm_init(&vm);
  print_usage(program_name);
  vm_free(&vm);
  return (0);
}
