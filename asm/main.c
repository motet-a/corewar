/*
** main.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 18:03:12 2016 antoine
** Last update Mon Feb 29 13:09:21 2016 Antoine Baudrand
*/

#include <unistd.h>
#include "../libcw/print.h"
#include "asm.h"

static void     print_help(const char *program_name, int output_file)
{
  int           f;

  f = output_file;
  print_string_file("Usage: ", f);
  print_string_file(program_name, f);
  print_string_file(" FILE\n", f);
}

int             main(int argc, char **argv)
{
  if (argc != 2) {
    print_help(argv[0], STDERR_FILENO);
    return (1);
  }
  return (read_and_compile(argv[1]));
}
