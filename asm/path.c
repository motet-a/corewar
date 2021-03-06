/*
** path.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Mar 27 15:05:44 2016 antoine
** Last update Sun Mar 27 15:05:44 2016 antoine
*/

#include <stdlib.h>
#include "../libcw/string.h"

static const char       *get_file_name(const char *path)
{
  while (string_find(path, "/"))
    path++;
  return (path);
}

char                    *get_cor_file_path(const char *input)
{
  char                  *s;

  input = get_file_name(input);
  s = malloc(string_get_length(input) + 5);
  if (!s)
    return (NULL);
  s[0] = '\0';
  if (string_ends_with(input, ".s"))
    string_copy_n(s, input, string_get_length(input) - 2);
  else
    string_copy(s, input);
  string_concat(s, ".cor");
  return (s);
}
