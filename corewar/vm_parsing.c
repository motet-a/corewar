/*
** vm_parsing.c for  in /Users/westery/Documents/tek1/CPE/corewar/corewar/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Sun Mar 27 21:59:25 2016 Valentin Pichard
** Last update Sun Mar 27 22:28:37 2016 Valentin Pichard
*/

#include "../libcw/print.h"
#include "../libcw/instr.h"
#include "../libcw/string.h"
#include "vm.h"
#include "instructions.h"
#include "options.h"

int              	parse_program_options(t_parser_state *state,
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

int	              parse_program_opt(t_parser_state *state,
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

int			parse_programs(t_parser_state *state)
{
  t_program_opt         program;

  while (state->index < state->argc)
    {
      if (parse_program_opt(state, &program))
        return (-1);
    }
  return (0);
}

int			parse_options(int argc,
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
