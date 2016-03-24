/*
** vm_init_options.c for  in /Users/westery/Documents/tek1/CPE/corewar/src/vm/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Mon Mar 21 23:36:45 2016 Valentin Pichard
** Last update Thu Mar 24 00:15:47 2016 Valentin Pichard
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
