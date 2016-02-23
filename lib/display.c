/*
** display.c for  in /Users/westery/Documents/tek1/CPE/corewar/lib/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Tue Feb 23 01:20:50 2016 Valentin Pichard
** Last update Tue Feb 23 01:27:36 2016 Valentin Pichard
*/

#include "corewar_lib.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (*str != 0)
    {
      write(1, &*str, 1);
      str++;
    }
  return (0);
}

int		my_putnbr(int nb)
{
  int	rest;

  rest = 0;
  if (nb < 0)
    {
      if (nb == -2147483648)
	{
	  nb = -2147483647;
	  rest = 1;
      	}
	nb = -nb;
	my_putchar('-');
    }
  if (nb > 9)
    {
      my_putnbr(nb / 10);
      my_putchar(nb % 10 + 48 + rest);
    }
  if (nb <= 9)
    {
      my_putchar(nb % 10 + 48 + rest);
    }
  return (0);
}
