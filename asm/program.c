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
#include "../libcw/print.h"

t_syntax_error          *program_parse(t_program *program,
                                       t_token_list *tokens)
{
  t_syntax_error        *error;

  instr_info_get_list(program->instr_infos);
  program->instructions = NULL;
  program->labels = NULL;
  program->name = NULL;
  program->comment = NULL;
  while (tokens)
    {
      error = parse_line(program, &tokens);
      if (error)
        {
          program_free(program);
          return (error);
        }
    }
  error = program_link_labels(program);
  if (error)
    {
      program_free(program);
      return (error);
    }
  return (NULL);
}

void            program_free(t_program *program)
{
  instr_list_delete(program->instructions);
  label_list_delete(program->labels);
  free(program->name);
  free(program->comment);
}

void            program_print(const t_program *program)
{
  print_string("\nlabels:\n");
  label_list_print(program->labels);
  print_string("\ninstructions:\n");
  instr_list_print(program->instructions);
}

int             program_write(const t_program *program, int output_file)
{
  t_instr_list  *instructions;

  instructions = program->instructions;
  while (instructions)
    {
      if (instr_write(&instructions->instr, output_file))
        return (-1);
      instructions = instructions->next;
    }
  return (0);
}

void            program_add_instr(t_program *program, const t_instr *instr)
{
  t_label_list  *labels;

  instr_list_add(&program->instructions, instr);
  instr = &instr_list_get_last(program->instructions)->instr;
  labels = program->labels;
  while (labels)
    {
      if (!labels->label.instr)
        labels->label.instr = instr;
      labels = labels->next;
    }
}
