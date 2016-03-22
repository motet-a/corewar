/*
** options.h for  in /Users/westery/Documents/tek1/CPE/corewar/src/vm/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Mon Mar 21 23:43:43 2016 Valentin Pichard
** Last update Mon Mar 21 23:58:43 2016 Valentin Pichard
*/

#ifndef OPTION_H
# define OPTION_H

typedef struct          s_option
{
  const char            *name;
  int                   has_value;
}                       t_option;

typedef struct          s_option_result
{
  const char            *error_message;
  const t_option        *option;
  const char            *value;
}                       t_option_result;

t_option_result         option_get_next(int argc,
                                        char **argv,
                                        int *arg_index,
                                        const t_option *options);
t_option_result         create_error_result(const char *message);
t_option_result         create_option_result(const t_option *option,
                                             const char *value);
t_option_result         option_get_next(int argc,
					char **argv,
					int *arg_index,
					const t_option *options);
int              	option_is_named(const t_option *option,
                                        const char *name);
t_option_result		parse_arg(int argc,
				  char **argv,
				  int *arg_index,
				  const t_option *options);
void            	vm_init_options(t_option *options);

#endif /* OPTION_H */
