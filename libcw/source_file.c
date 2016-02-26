/*
** source_file.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 16:59:59 2016 antoine
** Last update Fri Feb 26 16:59:59 2016 antoine
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "position.h"
#include "str.h"

/*
** From Whiskey :-)
*/
char            *read_whole_file(int file_descriptor)
{
  size_t        block_size;
  char          *string;
  size_t        length;
  size_t        read_char_count;

  string = NULL;
  length = 0;
  block_size = 1024 * 1024;
  while ((string = realloc(string, length + block_size + 1)) != NULL)
    {
      read_char_count = read(file_descriptor, string + length, block_size);
      length += read_char_count;
      string[length] = '\0';
      if (string_get_length(string) != (int)length)
        {
          free(string);
          return (NULL);
        }
      if (read_char_count != block_size)
        break;
    }
  return (string);
}

int             source_file_read(t_source_file *file,
                                 const char *file_name)
{
  int           fd;

  file->name = file_name;
  fd = open(file_name, O_RDONLY);
  if (fd == -1)
    return (-1);
  file->content = read_whole_file(fd);
  if (!file->content)
    {
      close(fd);
      return (-2);
    }
  close(fd);
  return (0);
}

void            source_file_free(t_source_file *file)
{
  free(file->content);
}
