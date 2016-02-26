/*
** print_char.c for corewar in /home/bailly_j/rendu/corewar/libcw
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Fri Feb 26 14:59:18 2016 Jamy Bailly
** Last update Fri Feb 26 15:26:21 2016 Jamy Bailly
*/

void	print_char_file(char c, int file_descriptor)
{
  write(file_descriptor, &c, 1);
}

void	print_char(char c)
{
  print_char_file(c, STDOUT_FILENO);
}

void	print_n_char_file(char c, int n, int file_descriptor)
{
  int	i;

  i = 0;
  while (i++ < n)
    print_char_file(c, file_descriptor);
}

void	print_n_chars(char c, int n)
{
  print_n_char_file(c, n, STDOUT_FILENO);
}
