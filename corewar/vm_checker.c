/*
** vm_checker.c for corewar in /home/antoine/corewar/corewar
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Fri Mar 25 17:10:21 2016 Valentin Pichard
** Last update sam. mars 26 17:22:08 2016 Antoine Baudrand
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
	  if ((this->cycle - this->programs[i].last_live_cycle) >
	      this->cycle_to_die)
	    this->programs[i].alive = 0;
	  else
	    this->programs[i].alive = 1;
	}
      else
	this->programs[i].alive = 0;
    }
}
