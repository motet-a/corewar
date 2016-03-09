/*
** string_reader.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 16:46:41 2016 antoine
** Last update Fri Feb 26 16:46:41 2016 antoine
*/

#ifndef STRING_READER_H
# define STRING_READER_H

# include "position.h"

typedef struct  s_string_reader
{
  t_source_file *source_file;
  t_position    position;
}               t_string_reader;

int             string_reader_init_from_string(t_string_reader *reader,
                                               const char *string);
int             string_reader_init(t_string_reader *reader,
                                   t_source_file *source_file);
char            string_reader_next(t_string_reader *reader);
void            string_reader_skip_chars(t_string_reader *reader,
                                         const char *chars_to_skip);
void            string_reader_skip_whitespaces(t_string_reader *reader);
int             string_reader_has_more(const t_string_reader *reader);

#endif /* STRING_READER_H */
