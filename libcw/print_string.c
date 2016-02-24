/*
** print_string.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Feb 24 20:11:34 2016 antoine
** Last update Wed Feb 24 20:11:34 2016 antoine
*/

#include <unistd.h>
#include "print.h"

void            print_string_file(const char *string, int file)
{
  while (*string) {
    write(file, string, 1);
    string++;
  }
}

void            print_string(const char *string)
{
  print_string_file(string, STDOUT_FILENO);
}

void            print_string_err(const char *string)
{
  print_string_file(string, STDERR_FILENO);
}
