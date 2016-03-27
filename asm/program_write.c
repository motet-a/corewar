/*
** program_write.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Mar 27 14:48:25 2016 antoine
** Last update Sun Mar 27 14:48:25 2016 antoine
*/

#include "asm.h"
#include "../libcw/cor_file.h"

static int              write_header(const t_program *program,
                                     int output_file)
{
  t_cor_file_header     header;
  int                   size;

  size = program_get_size(program);
  if (cor_file_header_init(&header, program->name, program->comment, size))
    return (-1);
  if (cor_file_header_write(&header, output_file))
    {
      cor_file_header_free(&header);
      return (-1);
    }
  cor_file_header_free(&header);
  return (0);
}

int             program_write(const t_program *program, int output_file)
{
  t_instr_list  *instructions;

  if (write_header(program, output_file))
    return (-1);
  instructions = program->instructions;
  while (instructions)
    {
      if (instr_write(&instructions->instr, output_file))
        return (-1);
      instructions = instructions->next;
    }
  return (0);
}
