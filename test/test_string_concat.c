/*
** test_string_concat.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 29 18:48:09 2016 antoine
** Last update Mon Feb 29 18:48:09 2016 antoine
*/

#include "test.h"
#include "../libcw/string.h"

void    test_suite_string_concat(void)
{
  char  s[100];

  s[0] = 'a';
  s[1] = '\0';
  string_concat(s, "hello");
  ASSERT(string_equals("ahello", s));
  s[0] = '\0';
  string_concat_n(s, "hello", 4);
  ASSERT(string_equals("hell", s));
  s[0] = '\0';
  string_concat_n(s, "hello", 12);
  ASSERT(string_equals("hello", s));
  s[0] = 'a';
  s[1] = '\0';
  string_concat_n(s, "hello", 0);
  ASSERT(string_equals("a", s));
  s[0] = 'a';
  s[1] = '\0';
  string_concat_char(s, 'b');
  ASSERT(string_equals("ab", s));
}
