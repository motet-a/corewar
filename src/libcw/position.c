/*
** position.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar  9 12:53:13 2016 antoine
** Last update Wed Mar  9 12:53:13 2016 antoine
*/

#include "position.h"
#include "print.h"

void            position_init(t_position *position,
                              t_source_file *source_file)
{
  position->source_file = source_file;
  position->index = 0;
  position->line = 1;
  position->column = 1;
}

void            position_print(const t_position *position, int file)
{
  print_string_file(position->source_file->name, file);
  print_string_file(":", file);
  print_int_file(position->line, file);
  print_string_file(":", file);
  print_int_file(position->column, file);
}
