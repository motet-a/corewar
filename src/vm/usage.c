/*
** usage.c for  in /Users/westery/Documents/tek1/CPE/corewar/src/vm/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Tue Mar  8 23:40:07 2016 Valentin Pichard
** Last update Tue Mar  8 23:57:55 2016 Valentin Pichard
*/

#include "../libcw/print.h"
#include "vm.h"

void		print_usage(const char *filename)
{
  print_string("Usage : ");
  print_string(filename);
  print_string(" [-dump nbr_cycle] [[-n prog_number]"
	       " [-a load_address] prog_name] ...");
}
