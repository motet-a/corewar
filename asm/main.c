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
#include "lexer.h"

static void     print_help(const char *program_name, int output_file)
{
  int           f;

  f = output_file;
  print_string_file("Usage: ", f);
  print_string_file(program_name, f);
  print_string_file(" FILE\n", f);
}

int                     compile(t_token_list *tokens)
{
  t_syntax_error        *error;
  t_program             program;

  /*token_list_print(tokens, "\n", STDOUT_FILENO);*/
  error = program_parse(&program, tokens);
  token_list_delete(tokens, 1);
  if (error)
    {
      syntax_error_print(error, STDERR_FILENO);
      syntax_error_delete(error);
      return (-1);
    }
  program_print(&program);
  program_free(&program);
  return (0);
}

int                     lex_and_compile(t_source_file *file)
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
  return (compile(result.tokens));
}

static int      read_and_compile(const char *source_file_path)
{
  t_source_file file;
  int           r;

  if (source_file_read(&file, source_file_path))
    {
      print_string_err("Can't read ");
      print_string_err(source_file_path);
      print_string_err("\n");
      return (-1);
    }
  r = lex_and_compile(&file);
  source_file_free(&file);
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
