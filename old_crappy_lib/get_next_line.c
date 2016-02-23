/*
** get_next_line.c for  in /Users/westery/Documents/tek1/CPE/CPE_2015_Allum1/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Sat Feb 20 12:06:47 2016 Valentin Pichard
** Last update Tue Feb 23 01:25:46 2016 Valentin Pichard
*/

#include "corewar_lib.h"

static char	*my_strncpy(char *dest, char *src, int index)
{
  int           i;

  i = 0;
  while (src[i] != '\0' && i < index)
    {
      dest[i] = src[i];
      i++;
    }
  if (index < i)
    {
      dest[i] = '\0';
    }
  return (dest);
}

static char	*add_some_line(char *line, int count, char *buffer, int *start)
{
  char          *getnewlen;
  int           getoldlen;

  if (line != 0)
    getoldlen = my_putstrlen(line, 0);
  else
    getoldlen = 0;
  if ((getnewlen = malloc((getoldlen + count + 1) *
			  sizeof(*getnewlen))) == NULL)
    return (0);
  if (line != 0)
      my_strncpy(getnewlen, line, getoldlen);
  else
      my_strncpy(getnewlen, "", getoldlen);
  getnewlen[getoldlen + count] = 0;
  my_strncpy(getnewlen + getoldlen, buffer + *start, count);
  if (line)
    free(line);
  *start = *start + (count + 1);
  return (getnewlen);
}

char		*get_next_line(const int fd)
{
  static char   buffer[READ_SIZE];
  static int    indexbuffer = 0;
  static int    start;
  int           count;
  char          *line;

  line = 0;
  count = 0;
  while (42)
    {
      if (indexbuffer <= start)
        {
          start = 0;
          if (!(indexbuffer = read(fd, buffer, READ_SIZE)))
            return (line);
          if (indexbuffer == -1)
            return (NULL);
          count = 0;
        }
      if (buffer[start + count] == '\n')
	return (line = add_some_line(line, count, buffer, &start));
      if (start + count == indexbuffer - 1)
        line = add_some_line(line, count + 1, buffer, &start);
      count++;
    }
}
