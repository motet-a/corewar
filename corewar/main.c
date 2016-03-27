/*
** main.c for corewar in /home/antoine/corewar/corewar
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 29 17:34:08 2016 antoine
** Last update Sun Mar 27 16:19:42 2016 Valentin Pichard
*/

#include "../libcw/print.h"
#include "../libcw/instr.h"
#include "vm.h"
#include <stdio.h>
#include "options.h"

static int              parse_options(int argc,
                                      char **argv,
                                      const t_option *options)
{
  int                   arg_index;
  t_option_result       r;

  arg_index = 0;
  while (arg_index < argc)
    {
      r = option_get_next(argc, argv, &arg_index, options);
      if (r.error_message != NULL)
        {
          print_string_err(r.error_message);
          print_string_err("\n");
          return (-1);
        }
    }
  return (0);
}

static void	lunch_vm(int program_count)
{
  t_vm		*vm;

  vm = init_new_vm(program_count);
  vm_free(vm);
}

int			main(int argc, char **argv)
{
  const char		*program_name;
  t_option		options[32];

  init_vm_options(options);
  program_name = argv[0];
  lunch_vm(2);
  if (parse_options(argc - 1, argv + 1, options) || argv[1] == NULL)
    {
      print_usage(program_name);
      return (2);
    }
  return (0);
}
