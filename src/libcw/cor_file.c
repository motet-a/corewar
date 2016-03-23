/*
** cor_file.c for libcw in /home/antoine/corewar/src/libcw
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Mar 22 10:16:16 2016 antoine
** Last update mer. mars 23 21:21:57 2016 Antoine Baudrand
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
  self->name[0] = '\0';
  self->comment[0] = '\0';
  string_concat(self->name, name);
  string_concat(self->comment, comment);
  self->program_size = program_size;
  return (NULL);
}

void            cor_file_header_free(t_cor_file_header *self)
{
  free(self->name);
  free(self->comment);
}

const char      *cor_file_header_write(const t_cor_file_header *self,
                                       int output_file)
{

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
