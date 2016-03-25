/*
** main.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 18:03:12 2016 antoine
** Last update Mon Feb 29 13:09:21 2016 Antoine Baudrand
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libcw/print.h"
#include "../libcw/position.h"
#include "asm.h"

static void     print_help(const char *program_name, int output_file)
{
  int           f;

  f = output_file;
  print_string_file("Usage: ", f);
  print_string_file(program_name, f);
  print_string_file(" FILE\n", f);
}

int             compile(int source_file, const char *path)
{
  char          *source;

  source = read_whole_file(source_file);
  if (!source)
    {
      print_string_err("Can't read ");
      print_string_err(path);
      print_string_err("\n");
      return (-1);
    }
  free(source);
  return (0);
}


static int      open_and_compile(const char *source_file_path)
{
  int           file;
  int           r;

  file = open(source_file_path, O_RDONLY);
  if (file == -1)
    {
      print_string_err("Can't open ");
      print_string_err(source_file_path);
      print_string_err("\n");
      return (-1);
    }
  r = compile(file, source_file_path);
  close(file);
  return (r);
}

int             main(int argc, char **argv)
{
  if (argc != 2) {
    print_help(argv[0], STDERR_FILENO);
    return (1);
  }
  return (open_and_compile(argv[1]));
}
