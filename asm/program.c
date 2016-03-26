/*
** program.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 15:59:28 2016 antoine
** Last update Fri Mar 25 15:59:28 2016 antoine
*/

#include <stdlib.h>
#include "asm.h"

t_syntax_error          *program_parse(t_program *program,
                                       t_token_list *tokens)
{
  t_syntax_error        *error;

  program->instructions = NULL;
  program->labels = NULL;
  while (tokens)
    {
      error = parse_line(program, &tokens);
      if (error)
        {
          program_free(program);
          return (error);
        }
    }
  return (NULL);
}

void            program_free(t_program *program)
{
  instr_list_delete(program->instructions);
  label_list_delete(program->labels);
}

void            program_print(const t_program *program)
{
  label_list_print(program->labels);
}

void            program_write(const t_program *program, int output_file);