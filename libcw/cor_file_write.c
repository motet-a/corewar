/*
** cor_file_write.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 24 21:17:14 2016 antoine
** Last update Thu Mar 24 21:17:14 2016 antoine
*/

#include <stdlib.h>
#include <unistd.h>
#include "string.h"
#include "cor_file_private.h"
#include "memory.h"

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

int             cor_file_write_int_16(int output_file, int n)
{
  char          buffer[2];

  memory_write_int_16(buffer, n);
  return (write(output_file, buffer, sizeof(buffer)) == sizeof(buffer));
}

int             cor_file_write_int_32(int output_file, long n)
{
  char          buffer[4];

  memory_write_int_32(buffer, n);
  return (write(output_file, buffer, sizeof(buffer)) == sizeof(buffer));
}
