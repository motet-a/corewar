/*
** syntax_error.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar  9 00:00:28 2016 antoine
** Last update Wed Mar  9 00:00:28 2016 antoine
*/

#include <stdlib.h>
#include "lexer.h"
#include "../libcw/string.h"
#include "../libcw/print.h"

t_syntax_error          *syntax_error_new(const t_position *position,
                                          const char *message)
{
  t_syntax_error        *e;

  e = malloc(sizeof(t_syntax_error));
  if (!e)
    return (NULL);
  e->position = *position;
  e->message = string_duplicate(message);
  if (!e->message)
    {
      free(e);
      return (NULL);
    }
  return (e);
}

void                    syntax_error_delete(t_syntax_error *syntax_error)
{
  free(syntax_error->message);
  free(syntax_error);
}

void                    syntax_error_print(const t_syntax_error *error,
                                           int output_file)
{
  position_print(&error->position, output_file);
  print_string_file(": ", output_file);
  print_string_file(error->message, output_file);
  print_string_file("\n", output_file);
}
