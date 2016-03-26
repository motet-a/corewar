/*
** argument.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 16:59:22 2016 antoine
** Last update Fri Mar 25 16:59:22 2016 antoine
*/

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
