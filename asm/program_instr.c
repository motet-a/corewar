/*
** program_instr.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Mar 27 14:49:59 2016 antoine
** Last update Sun Mar 27 14:49:59 2016 antoine
*/

#include "asm.h"

int             program_get_instr_offset(const t_program *program,
                                         const t_instr *instr)
{
  t_instr_list  *instructions;
  int           offset;

  offset = 0;
  instructions = program->instructions;
  while (instructions)
    {
      if (&instructions->instr == instr)
        {
          return (offset);
        }
      offset += instr_get_size(&instructions->instr);
      instructions = instructions->next;
    }
  return (-1);
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
