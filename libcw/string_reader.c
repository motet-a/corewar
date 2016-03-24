/*
** string_reader.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 10 23:47:28 2016 antoine
** Last update Thu Mar 10 23:47:28 2016 antoine
*/

#include <stdlib.h>
#include <assert.h>
#include "string_reader.h"
#include "../libcw/string.h"

int             string_reader_init_from_string(t_string_reader *reader,
                                               const char *string)
{
  t_source_file *file;

  file = malloc(sizeof(t_source_file));
  if (!file)
    return (-1);
  source_file_init_unnamed(file, string);
  return (string_reader_init(reader, file));
}

int             string_reader_init(t_string_reader *reader,
                                   t_source_file *file)
{
  reader->file = file;
  position_init(&reader->position, file);
  return (0);
}

char            string_reader_next(t_string_reader *reader)
{
  char          c;

  assert(string_reader_has_more(reader));
  c = reader->file->content[reader->position.index];
  reader->position.index++;
  return (c);
}

void            string_reader_skip(t_string_reader *reader,
                                   const char *chars_to_skip)
{
  t_position    prev;
  char          c;

  while (string_reader_has_more(reader))
    {
      prev = reader->position;
      c = string_reader_next(reader);
      if (!string_find_char(chars_to_skip, c))
        {
          reader->position = prev;
          break;
        }
    }
}

int             string_reader_has_more(const t_string_reader *reader)
{
  const char    *s;

  s = reader->file->content;
  return (reader->position.index < string_get_length(s));
}
