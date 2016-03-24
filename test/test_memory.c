/*
** test_memory.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 16:21:37 2016 antoine
** Last update Fri Feb 26 16:21:37 2016 antoine
*/

#include "test.h"
#include "../libcw/memory.h"
#include "../libcw/string.h"

static void     test_memory_read(void)
{
  long          n;

  n = memory_read_int_16("\x12\x34\x56\x78\x9a");
  ASSERT(n == 0x1234);
  n = memory_read_int_32("\x12\x34\x56\x78\x9a");
  ASSERT(n == 0x12345678);
}

static void     test_memory_write(void)
{
  char          s[10];

  string_set_n_chars(s, '\0', 10);
  memory_write_int_16(s, 0x1234);
  ASSERT(string_equals(s, "\x12\x34"));
  memory_write_int_32(s, 0x12345678);
  ASSERT(string_equals(s, "\x12\x34\x56\x78"));
}

void    test_suite_memory(void)
{
  test_memory_read();
  test_memory_write();
}
