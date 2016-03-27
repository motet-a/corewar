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
#include "../libcw/string.h"

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
  print_string("name: ");
  print_string(program->name);
  print_string("\n");
  print_string("comment: ");
  print_string(program->comment);
  print_string("\n");
  print_string("\nlabels:\n");
  label_list_print(program->labels);
  print_string("\ninstructions:\n");
  instr_list_print(program->instructions);
}

int             program_get_size(const t_program *program)
{
  t_instr_list  *instructions;
  int           size;

  size = 0;
  instructions = program->instructions;
  while (instructions)
    {
      size += instr_get_size(&instructions->instr);
      instructions = instructions->next;
    }
  return (size);
}

t_label         *program_get_label(const t_program *program,
                                   const char *name)
{
  t_label_list  *labels;

  labels = program->labels;
  while (labels)
    {
      if (string_equals(name, labels->label.name))
        return (&labels->label);
      labels = labels->next;
    }
  return (NULL);
}
