/*
** cor_file.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Mar 22 10:16:16 2016 antoine
** Last update Tue Mar 22 10:16:16 2016 antoine
*/

#include <unistd.h>
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

static int      write_string(const char *string,
                             size_t max_length,
                             int output)
{
  size_t        sl;

  sl = string_get_length(string);
  if (write(output, string, sl) != (ssize_t)sl)
    return (-1);
  while (sl < max_length)
    {
      if (write(output, "", 1) != 1)
        return (-1);
      sl++;
    }
  return (0);
}

int             cor_file_header_write(const t_cor_file_header *self,
                                      int output_file)
{
  if (cor_file_write_int_32(output_file, MAGIC_NUMBER))
    return (-1);
  if (write_string(self->name, NAME_LENGTH, output_file))
    return (-1);
  if (cor_file_write_int_32(output_file, self->program_size))
    return (-1);
  if (write_string(self->comment, COMMENT_LENGTH, output_file))
    return (-1);
  return (0);
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
