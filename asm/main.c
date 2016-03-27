/*
** main.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 18:03:12 2016 antoine
** Last update Mon Feb 29 13:09:21 2016 Antoine Baudrand
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libcw/print.h"
#include "../libcw/position.h"
#include "../libcw/string.h"
#include "asm.h"
#include "lexer.h"

static void     print_help(const char *program_name, int output_file)
{
  int           f;

  f = output_file;
  print_string_file("Usage: ", f);
  print_string_file(program_name, f);
  print_string_file(" FILE\n", f);
}

int             write_program(const t_program *program,
                              const char *output_path)
{
  int           file;
  mode_t        mode;

  mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  file = open(output_path, O_WRONLY | O_CREAT | O_TRUNC, mode);
  if (file == -1)
    {
      print_string_err("Can't open \"");
      print_string_err(output_path);
      print_string_err("\"\n");
      return (-1);
    }
  if (program_write(program, file) == -1)
    {
      close(file);
      print_string_err("write() error\n");
      return (-1);
    }
  close(file);
  return (0);
}

static int              compile(t_token_list *tokens,
                                const char *output_path)
{
  t_syntax_error        *error;
  t_program             program;

  error = program_parse(&program, tokens);
  token_list_delete(tokens, 1);
  if (error)
    {
      syntax_error_print(error, STDERR_FILENO);
      syntax_error_delete(error);
      return (-1);
    }
  program_print(&program);
  write_program(&program, output_path);
  program_free(&program);
  return (0);
}

int                     lex_and_compile(t_source_file *file,
                                        const char *output_path)
{
  t_lexer_result        result;
  t_string_reader       reader;

  if (string_reader_init(&reader, file))
    {
      print_string_err("string_reader_init(): Internal error\n");
      return (-1);
    }
  result = lex(&reader);
  if (result.error)
    {
      syntax_error_print(result.error, STDERR_FILENO);
      syntax_error_delete(result.error);
      return (-1);
    }
  return (compile(result.tokens, output_path));
}

static char             *get_output_path(const char *input)
{
  char                  *s;

  s = malloc(string_get_length(input) + 4);
  if (!s)
    return (NULL);
  s[0] = '\0';
  if (string_ends_with(input, ".s"))
    string_copy_n(s, input, string_get_length(input) - 2);
  else
    string_copy(s, input);
  string_concat(s, ".cor");
  return (s);
}

static int      read_and_compile(const char *source_file_path)
{
  t_source_file file;
  int           r;
  char          *output_path;

  output_path = get_output_path(source_file_path);
  if (!output_path)
    {
      print_string_err("Can't perform malloc()\n");
      return (-1);
    }
  if (source_file_read(&file, source_file_path))
    {
      print_string_err("Can't read ");
      print_string_err(source_file_path);
      print_string_err("\n");
      free(output_path);
      return (-1);
    }
  r = lex_and_compile(&file, output_path);
  source_file_free(&file);
  free(output_path);
  return (r);
}

int             main(int argc, char **argv)
{
  if (argc != 2) {
    print_help(argv[0], STDERR_FILENO);
    return (1);
  }
  return (read_and_compile(argv[1]));
}
