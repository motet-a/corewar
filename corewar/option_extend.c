/*
** option_extend.c for  in /Users/westery/Documents/tek1/CPE/corewar/src/vm/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Tue Mar 22 00:03:32 2016 Valentin Pichard
** Last update Tue Mar 22 00:04:39 2016 Valentin Pichard
*/

#include <stdlib.h>
#include "options.h"
#include "../libcw/string.h"

t_option_result         create_error_result(const char *message)
{
  t_option_result       r;

  r.error_message = message;
  r.option = NULL;
  r.value = NULL;
  return (r);
}

t_option_result         create_option_result(const t_option *option,
                                             const char *value)
{
  t_option_result       r;

  r.error_message = NULL;
  r.option = option;
  r.value = value;
  return (r);
}

t_option_result         option_get_next(int argc,
                                        char **argv,
                                        int *arg_index,
                                        const t_option *options)
{
  if (*arg_index >= argc)
    return (create_error_result("No arguments left"));
  return (parse_arg(argc, argv, arg_index, options));
}

int              	option_is_named(const t_option *option,
                                        const char *name)
{
  if (name[0] != '-')
    return (0);
  if (option->name)
    return (string_equals(name + 1, option->name));
  return (0);
}
