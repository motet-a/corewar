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

# define CYCLE_TO_DIE	1536
# define CYCLE_DELTA	4
# define NBR_LIVE	2048
# define REG_NUMBER	16

void		print_usage(const char *filename);

typedef struct		s_program
{
	unsigned	pc;
	unsigned	carry;
	unsigned	*registers[REG_NUMBER];
}			t_program;

#endif /* VM_H */
