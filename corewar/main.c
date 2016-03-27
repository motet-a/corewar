/*
** main.c for corewar in /home/antoine/corewar/corewar
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 29 17:34:08 2016 antoine
** Last update Sun Mar 27 17:59:08 2016 Valentin Pichard
*/

#include "../libcw/print.h"
#include "../libcw/instr.h"
#include "vm.h"
#include <stdio.h>
#include "options.h"

static int              parse_options(int argc,
                                      char **argv,
                                      const t_option *options,
                                      t_vm *vm)
{
  int                   arg_index;
  t_option_result       r;

  arg_index = 0;
  while (arg_index < argc)
    {
      if (argv[arg_index][0] != '-')
        {
          print_string("This is a program: ");
          print_string(argv[arg_index]);
          print_string("\n");
          arg_index++;
        }
      else
        {
          r = option_get_next(argc, argv, &arg_index, options);
          if (r.error_message != NULL)
            {
              print_string_err(r.error_message);
              print_string_err("\n");
              return (-1);
            }
        }
    }
  return (0);
}

int			main(int argc, char **argv)
{
  const char		*program_name;
  t_option		options[32];
  t_vm                  vm;

  init_vm_options(options);
  program_name = argv[0];
  vm_init(&vm);
  if (parse_options(argc - 1, argv + 1, options, &vm))
    {
      vm_free(&vm);
      print_usage(program_name);
      return (2);
    }
  vm_free(&vm);
  return (0);
}
