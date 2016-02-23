/*
** my_getnbr.c for  in /Users/westery/Documents/tek1/CPE/CPE_2015_Allum1/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Wed Feb 17 11:07:28 2016 Valentin Pichard
** Last update Tue Feb 23 01:22:34 2016 Valentin Pichard
*/

#include "corewar_lib.h"

int		check_string(char *str)
{
  int		i;
  int		is_nbr;

  i = 0;
  is_nbr = 0;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	is_nbr++;
      i++;
    }
  if (is_nbr == my_strlen(str))
    return (1);
  else
    return (-1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (*str != 0)
    {
      str++;
      i++;
    }
  return (i);
}

int		my_getnbr_extend(int position, int len, char *str, int sign)
{
  int		i;
  int		n;
  unsigned int	tmp;

  i = position;
  n = 0;
  if (len < 10 || (len < 11 && str[position] < '3'))
  {
    while (i < len + position)
    {
      tmp = n * 10 + (str[i] - '0');
      if (sign > 0 && tmp > 2147483647)
        return (0);
      else if (sign < 0 && tmp > 2147483648)
        return (0);
      else
	n = tmp;
      i++;
    }
    return (sign * n);
  }
  return (0);
}

int		my_getnbr(char *str)
{
  int	i;
  int	position;
  int	len;
  int	sign;

  sign = 0;
  i = 0;
  while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
  {
    if (str[i] == '-')
      sign++;
    i++;
  }
  position = i;
  if (sign % 2 == 1)
    sign = -1;
  else
    sign = 1;
  while (str[i] >= '0' && str[i] <= '9')
  {
    i++;
  }
  len = i - position;
  return (my_getnbr_extend(position, len, str, sign));
}
