/*
** main.c for corewar in /home/antoine/corewar/corewar
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 29 17:34:08 2016 antoine
** Last update mer. mars 30 13:52:14 2016 Antoine Baudrand
*/

#include <stdlib.h>
#include "../libcw/print.h"
#include "../libcw/instr.h"
#include "../libcw/string.h"
#include "../libcw/parse_int.h"
#include "vm.h"
#include "options.h"

int			main(int argc, char **argv)
{
  const char		*program_name;
  t_vm                  vm;
  t_vm_options          vm_options;

  program_name = argv[0];
  if (argc == 1)
    print_usage(program_name);
  else
    opt_parse(&vm_options, argc - 1, argv + 1);
  vm_init(&vm);
  print_usage(program_name);
  vm_free(&vm);
  return (0);
}
