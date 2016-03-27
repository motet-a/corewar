/*
** vm_instr_live.c for  in /Users/westery/Documents/tek1/CPE/corewar/corewar/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Sun Mar 27 21:06:19 2016 Valentin Pichard
** Last update Sun Mar 27 21:24:50 2016 Valentin Pichard
*/

#include "instructions.h"
#include "vm.h"
#include "../libcw/memory.h"

void		vm_live(t_instruction *i)
{
  i->processes->program->last_live_cycle = i->vm->cycle;
}
