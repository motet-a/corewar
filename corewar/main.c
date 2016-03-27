/*
** main.c for corewar in /home/antoine/corewar/corewar
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 29 17:34:08 2016 antoine
** Last update Sun Mar 27 23:28:45 2016 Valentin Pichard
*/

#include <stdlib.h>
#include "../libcw/print.h"
#include "../libcw/instr.h"
#include "../libcw/string.h"
#include "../libcw/parse_int.h"
#include "vm.h"
#include "options.h"

int	              set_program_number(t_program_opt *program,
                                           const char *string)
{
  long                  n;

  if (parse_int(string, &n) || n < 0)
    {
      print_string_err("Invalid program number\n");
      return (-1);
    }
  program->number = n;
  return (0);
}

int	              set_option(t_program_opt *program,
                                 const t_option_result *r)
{
  if (string_equals(r->option->name, "n"))
    return (set_program_number(program, r->value));
  else if (string_equals(r->option->name, "n"))
    return (0);
  print_string_err("Unexpected option '-");
  print_string_err(r->option->name);
  print_string_err("'\n");
  return (-1);
}

int			main(int argc, char **argv)
{
  const char		*program_name;
  t_option		options[32];
  t_vm                  vm;

  init_vm_options(options);
  program_name = argv[0];
  vm_init(&vm);
  if (parse_options(argc - 1, argv + 1, options) || argc < 2)
    {
      vm_free(&vm);
      print_usage(program_name);
      return (2);
    }
  vm_free(&vm);
  return (0);
}
