/*
** vm_checker.c for  in /Users/westery/Documents/tek1/CPE/corewar/corewar/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Fri Mar 25 17:10:21 2016 Valentin Pichard
** Last update Fri Mar 25 18:08:38 2016 Valentin Pichard
*/

#include "vm.h"

void		vm_check_alive(t_vm *this)
{
  int		i;

  i = -1;
  while (++i < this->program_count)
    {
      if (this->programs[i].alive)
	{
	  if ((this->cycle - this->programs[i].last_live_cycle) >=
	      this->cycle_to_die)
	    this->programs[i].alive = 0;
	  else
	    this->programs[i].alive = 1;
	}
      else
	this->programs[i].alive = 0;
    }
}
