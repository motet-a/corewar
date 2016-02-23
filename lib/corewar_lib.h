/*
** coreware_lib.h for  in /Users/westery/Documents/tek1/CPE/corewar/lib/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Tue Feb 23 01:19:06 2016 Valentin Pichard
** Last update Tue Feb 23 01:31:08 2016 Valentin Pichard
*/

#ifndef COREWAR_LIB_H_
# define COREWAR_LIB_H_

#include <unistd.h>

# ifndef READ_SIZE
#  define READ_SIZE (14)
# endif /* !READ_SIZE */

char		*my_strdup(char *src);
void		my_putchar(char c);
int		my_putstr(char *str);
int		my_putnbr(int nb);
char		*get_next_line(const int fd);
int		check_string(char *str);
int		my_strlen(char *str);
int		my_getnbr_extend(int position, int len, char *str, int sign);
int		my_getnbr(char *str);


#endif /* !COREWAR_LIB_H_ */
