/*
** options.h for corewar in /home/antoine/corewar/corewar
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  lun. mars 28 22:23:51 2016 Antoine Baudrand
** Last update lun. mars 28 22:42:32 2016 Antoine Baudrand
*/

#ifndef OPTIONS_H_
# define OPTIONS_H_

typedef	struct		s_vm_program
{
  int			number;
  int			load_address;
  struct s_vm_program	*next;
}			t_vm_program;

typedef	struct		s_vm_options
{
  int			dump;
  int			programs_count;
  t_vm_program		*programs;
}			t_vm_options;

/*
** TODO
*/
int	opt_add_program(t_vm_options *opt);

/*
** TODO
*/
int	opt_parse(t_vm_options *opt, argc, arv);

#endif /* !OPTIONS_H_ */
