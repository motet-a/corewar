/*
** argument.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 16:59:22 2016 antoine
** Last update Fri Mar 25 16:59:22 2016 antoine
*/

#include <stdlib.h>
#include "../libcw/print.h"
#include "asm.h"

void                    argument_print(const t_argument *arg)
{
  if (arg->type == ARGUMENT_TYPE_DIRECT)
    print_string("%");
  else if (arg->type == ARGUMENT_TYPE_REGISTER)
    {
      print_string("r");
      print_int(arg->value);
      return ;
    }
  if (arg->label)
    {
      print_string(":");
      print_string(arg->label);
    }
  else
    print_int(arg->value);
}

void                    argument_free(t_argument *arg)
{
  free(arg->label);
}

int                     argument_get_size(const t_argument *arg)
{
  if (arg->type == ARGUMENT_TYPE_REGISTER)
    return (VM_REGISTER_ARGUMENT_SIZE);
  else if (arg->type == ARGUMENT_TYPE_DIRECT)
    return (VM_DIRECT_ARGUMENT_SIZE);
  else
    return (VM_INDIRECT_ARGUMENT_SIZE);
}
