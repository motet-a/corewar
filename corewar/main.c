/*
** main.c for corewar in /home/antoine/corewar/corewar
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 29 17:34:08 2016 antoine
** Last update Sun Mar 27 21:56:26 2016 Valentin Pichard
*/

#include <stdlib.h>
#include "../libcw/print.h"
#include "../libcw/instr.h"
#include "../libcw/string.h"
#include "../libcw/parse_int.h"
#include "vm.h"

static int              set_program_number(t_program_opt *program,
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

static int              set_option(t_program_opt *program,
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

static int              parse_program_options(t_parser_state *state,
                                              t_program_opt *program)
{
  t_option_result       r;

  program_opt_init(program);
  while (state->index < state->argc)
    {
      if (state->argv[state->index][0] != '-')
        break;
      r = option_get_next(state->argc, state->argv,
                          &state->index, state->options);
      if (r.error_message)
        {
          print_string_err(r.error_message);
          print_string_err("\n");
          return (-1);
        }
      if (set_option(program, &r))
        return (-1);
    }
  return (0);
}

static int              parse_program_opt(t_parser_state *state,
                                          t_program_opt *program)
{
  if (parse_program_options(state, program))
    return (-1);
  if (state->index >= state->argc)
    {
      print_string("Expected program name\n");
      return (-1);
    }
  if (state->argv[state->index][0] != '-')
    {
      print_string("This is a program: ");
      print_string(state->argv[state->index]);
      print_string("\n");
      state->index++;
    }
  return (0);
}

static int              parse_programs(t_parser_state *state)
{
  t_program_opt         program;

  while (state->index < state->argc)
    {
      if (parse_program_opt(state, &program))
        return (-1);
    }
  return (0);
}

static int              parse_options(int argc,
                                      char **argv,
                                      const t_option *options)
{
  t_parser_state        state;

  state.argv = argv;
  state.argc = argc;
  state.options = options;
  state.index = 0;
  return (parse_programs(&state));
}

int			main(int argc, char **argv)
{
  const char		*program_name;
  t_option		options[32];
  t_vm                  vm;

  init_vm_options(options);
  program_name = argv[0];
  vm_init(&vm);
  if (parse_options(argc - 1, argv + 1, options))
    {
      vm_free(&vm);
      print_usage(program_name);
      return (2);
    }
  vm_free(&vm);
  return (0);
}
