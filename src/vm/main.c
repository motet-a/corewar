/*
** main.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 29 17:34:08 2016 antoine
** Last update Tue Mar 22 00:10:31 2016 Valentin Pichard
*/

#include "../libcw/print.h"
#include "vm.h"
#include "options.h"

static int              parse_options(int argc,
                                      char **argv,
                                      const t_option *options)
{
  int                   arg_index;
  t_option_result       r;

  arg_index = 0;
  while (arg_index < argc)
    {
      r = option_get_next(argc, argv, &arg_index, options);
      if (r.error_message != NULL)
        {
          print_string_err(r.error_message);
          print_string_err("\n");
          return (-1);
        }
    }
  return (0);
}

int	main(int argc, char **argv)
{
  if ((argc % 3) - 2 != 0)
    print_usage(argv[0]);
  return (0);
}
