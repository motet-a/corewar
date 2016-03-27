/*
** cor_file_read.c for libcw in /home/antoine/corewar/libcw
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 24 21:11:27 2016 antoine
** Last update dim. mars 27 18:06:19 2016 Antoine Baudrand
*/

#include <unistd.h>
#include <stdlib.h>
#include "cor_file_private.h"
#include "memory.h"

static int      read_magic_number(int input_file)
{
  long          n;

  if (cor_file_read_int_32(input_file, &n))
    return (-1);
  if (n != MAGIC_NUMBER)
    return (-1);
  return (0);
}

static char     *read_string(size_t length, int input_file)
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

static int	cor_file_header_read_prog_size(t_cor_file_header *self,
					       int input_file)
{
  long		n;

  if (cor_file_read_int_32(input_file, &n) || n != 0)
    {
      free(self->name);
      return (-1);
    }
  if (cor_file_read_int_32(input_file, &n))
    {
      free(self->name);
      return (-1);
    }
  return (0);
}

int             cor_file_header_read(t_cor_file_header *self,
                                     int input_file)
{
  long          n;

  n = 0;
  if (read_magic_number(input_file))
    return (-1);
  if (!(self->name = read_string(NAME_LENGTH, input_file)))
    return (-1);
  if (cor_file_header_read_prog_size(self, input_file))
    return (-1);
  self->program_size = n;
  if (!(self->comment = read_string(COMMENT_LENGTH, input_file)))
    {
      free(self->name);
      return (-1);
    }
  if (cor_file_read_int_32(input_file, &n) || n != 0)
    {
      free(self->name);
      return (-1);
    }
  return (0);
}
