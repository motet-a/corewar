/*
** vm_init_options.c for  in /Users/westery/Documents/tek1/CPE/corewar/src/vm/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Mon Mar 21 23:36:45 2016 Valentin Pichard
** Last update Mon Mar 21 23:58:29 2016 Valentin Pichard
*/

#include "options.h"

void            vm_init_options(t_option *options)
{
  int           i;

  i = 0;
  options[i].name = "dump";
  options[i++].has_value = 1;
  options[i].name = "n";
  options[i++].has_value = 1;
  options[i].name = "a";
  options[i++].has_value = 1;
}
