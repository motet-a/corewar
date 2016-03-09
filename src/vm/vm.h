/*
** vm.h for  in /Users/westery/Documents/tek1/CPE/corewar/src/vm/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Tue Mar  8 23:44:36 2016 Valentin Pichard
** Last update Wed Mar  9 05:56:27 2016 Antoine Baudrand
*/

#ifndef VM_H
# define VM_H

# include "../libcw/instr.h"

# define CYCLE_TO_DIE	1536
# define CYCLE_DELTA	4
# define NBR_LIVE	2048

void		print_usage(const char *filename);

typedef struct		s_vm
{
	unsigned	pc;
	unsigned	carry;
	unsigned	*registers[VM_REGISTER_COUNT];
}			t_vm;

#endif /* VM_H */
