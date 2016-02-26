/*
** position.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 16:48:15 2016 antoine
** Last update Fri Feb 26 16:48:15 2016 antoine
*/

#ifndef POSITION_H
# define POSITION_H

typedef struct  s_source_file
{
  const char    *name;
  char          *content;
}               t_source_file;

/**
 * Returns 0 on success, -1 on open() error, -2 on read() error.
 */
int             source_file_read(t_source_file *file,
                                 const char *file_name);
void            source_file_free(t_source_file *file);

/*
** Reads everything from a given file descriptor.
**
** Returns a malloced string.
** Returns NULL on error.
*/
char            *read_whole_file(int file_descriptor);

/*
** line: 1-based line number
** column: 1-based column number
*/
typedef struct  t_position
{
  t_source_file *source_file;
  int           index;
  int           line;
  int           column;
}               s_position;

void            position_print(int output_file_descriptor);

#endif /* POSITION_H */
