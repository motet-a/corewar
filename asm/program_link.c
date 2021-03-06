/*
** program_link.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Mar 26 17:27:21 2016 antoine
** Last update Sat Mar 26 17:27:21 2016 antoine
*/

#include <stdlib.h>
#include "asm.h"

static void     set_label_offset(const t_program *program, t_label *label)
{
  if (!label->instr)
    label->offset = program_get_size(program);
  else
    label->offset = program_get_instr_offset(program, label->instr);
}

static void     set_label_offsets(const t_program *program)
{
  t_label_list  *labels;

  labels = program->labels;
  while (labels)
    {
      set_label_offset(program, &labels->label);
      labels = labels->next;
    }
}

static t_syntax_error   *link_arg(const t_program *program,
                                  const t_instr *instr,
                                  t_argument *arg)
{
  t_label               *label;

  if (!arg->label)
    return (NULL);
  label = program_get_label(program, arg->label);
  if (!label)
    return (syntax_error_new(&instr->position, "Undefined label"));
  arg->value = label->offset - program_get_instr_offset(program, instr);
  return (NULL);
}

static t_syntax_error   *link_instr(const t_program *program,
                                    t_instr *instruction)
{
  int                   i;
  t_syntax_error        *error;

  i = -1;
  while (++i < instruction->info->argument_count)
    {
      error = link_arg(program, instruction, instruction->arguments + i);
      if (error)
        return (error);
    }
  return (NULL);
}

t_syntax_error          *program_link_labels(const t_program *program)
{
  t_instr_list          *instructions;
  t_syntax_error        *error;

  set_label_offsets(program);
  instructions = program->instructions;
  while (instructions)
    {
      error = link_instr(program, &instructions->instr);
      if (error)
        return (error);
      instructions = instructions->next;
    }
  return (NULL);
}
