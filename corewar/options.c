/*
** options.c for corewar in /home/antoine/corewar/corewar
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  mer. mars 30 00:24:02 2016 Antoine Baudrand
** Last update mer. mars 30 16:04:29 2016 Antoine Baudrand
*/

#include <stdlib.h>
#include "options.h"
#include "../libcw/string.h"
#include "../libcw/print.h"

static int		parse_nbr(char *nbr)
{
  int		        res;

  res = 0;
  while (nbr && *nbr)
    {
      res *= 10;
      if (*nbr >= '0' && *nbr <= '9' && res >= 0)
	res += *nbr - '0';
      else
        return (-1);
      nbr++;
    }
  return (res);
}

static int          get_opt_value(int argc,char **argv, int *i)
{
  int               res;

  *i += 1;
  if (*i >= argc)
    {
      print_string_err("Invalid parameter option (number)\n");
      exit(-1);
    }
  else
    {
      res = parse_nbr(argv[*i]);
      if (res >= 0)
        return (res);
      else
        {
          print_string_err("Invalid parameter option (number)\n");
          exit(-1);
        }
    }
}

int	opt_parse(t_vm_options *opt, int argc, char **argv)
{
  int   i;

  opt->dump = 0;
  opt->programs_count = 0;
  opt->programs = NULL;
  while (i < argc)
    {
      if (string_equals(argv[i], "-dump"))
        opt->dump = get_opt_value(argc, argv, &i);
      else
        {
        }
      i += 1;
    }
  return (0);
}
