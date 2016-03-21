/*
** option.c for  in /Users/westery/Documents/tek1/CPE/corewar/src/vm/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Mon Mar 21 23:46:40 2016 Valentin Pichard
** Last update Mon Mar 21 23:56:00 2016 Valentin Pichard
*/

#include <stdlib.h>
#include "options.h"
#include "../libcw/string.h"

static const t_option   *find_option(const t_option *options,
                                     const char *name)
{
  while (options->name)
    {
      if (option_is_named(options, name))
        return (options);
      options++;
    }
  return (NULL);
}

static const char       *get_long_option_value(const char *arg)
{
  while (*arg)
    {
      if (*arg == '=')
        {
          arg++;
          return (arg);
        }
      arg++;
    }
  return (NULL);
}

static t_option_result  parse_short_option_value(int argc,
                                                 char **argv,
                                                 int *arg_index,
                                                 const t_option *option)
{
  const char            *value;

  if (*arg_index >= argc)
    return (create_error_result("Expected short option value"));
  value = argv[*arg_index];
  (*arg_index)++;
  return (create_option_result(option, value));
}

static t_option_result  parse_long_option_value(const char *arg,
                                                const t_option *option)
{
  const char            *value;

  value = get_long_option_value(arg);
  if (!value)
    return (create_error_result("Expected long option value after a '='"));
  return (create_option_result(option, value));
}

t_option_result		parse_arg(int argc,
                                  char **argv,
                                  int *arg_index,
                                  const t_option *options)
{
  const char            *arg;
  const t_option        *option;

  arg = argv[*arg_index];
  option = find_option(options, arg);
  if (!option)
    return (create_error_result("Invalid option"));
  (*arg_index)++;
  if (!option->has_value)
    return (create_option_result(option, NULL));
  if (arg[1] == '-')
    return (parse_long_option_value(arg, option));
  return (parse_short_option_value(argc, argv, arg_index, option));
}
