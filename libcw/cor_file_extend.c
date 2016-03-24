/*
** cor_file_extend.c for  in /Users/westery/Documents/tek1/CPE/corewar/libcw/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Thu Mar 24 17:28:07 2016 Valentin Pichard
** Last update Thu Mar 24 17:51:33 2016 Valentin Pichard
*/

#include <unistd.h>
#include <stdlib.h>
#include "cor_file_private.h"
#include "string.h"
#include "print.h"

void            cor_file_header_free(t_cor_file_header *self)
{
  free(self->name);
  free(self->comment);
}

int      	write_string(const char *string,
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

char            *read_string(size_t length, int input_file)
{
  char          *string;

  string = malloc(length + 1);
  if (!string)
    return (NULL);
  if (write(input_file, string, length) <= 0)
    {
      free(string);
      return (NULL);
    }
  string[length] = '\0';
  return (string);
}

int             cor_file_header_read(t_cor_file_header *self,
                                     int input_file)
{
  long          n;

  if (read_magic_number(input_file))
    return (-1);
  if (!(self->name = read_string(NAME_LENGTH, input_file)))
    return (-1);
  if (cor_file_read_int_32(input_file, &n))
    {
      free(self->name);
      return (-1);
    }
  self->program_size = n;
  if (!(self->comment = read_string(COMMENT_LENGTH, input_file)))
    {
      free(self->name);
      return (-1);
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
