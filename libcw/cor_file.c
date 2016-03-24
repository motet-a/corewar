/*
** cor_file.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Mar 22 10:16:16 2016 antoine
** Last update Thu Mar 24 17:43:10 2016 Valentin Pichard
*/

#include <stdlib.h>
#include "cor_file_private.h"
#include "string.h"
#include "print.h"

const char      *cor_file_header_init(t_cor_file_header *self,
                                      const char *name,
                                      const char *comment,
                                      int program_size)
{
  if (string_get_length(name) > NAME_LENGTH)
    return (NAME_TOO_LONG_ERROR);
  if (string_get_length(comment) > COMMENT_LENGTH)
    return (COMMENT_TOO_LONG_ERROR);
  self->name = string_duplicate(name);
  self->comment = string_duplicate(name);
  if (!self->name || !self->comment)
    return (NO_MEMORY_ERROR);
  self->program_size = program_size;
  return (NULL);
}

void            cor_file_header_free(t_cor_file_header *self)
{
  free(self->name);
  free(self->comment);
}

void            cor_file_header_print(const t_cor_file_header *self)
{
  print_string("name: ");
  print_string(self->name);
  print_string("\ncomment: ");
  print_string(self->comment);
  print_string("\nprogram_size: ");
  print_int(self->program_size);
  print_string("\n");
}
