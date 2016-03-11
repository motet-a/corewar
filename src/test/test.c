/*
** test.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Feb 23 00:12:28 2016 antoine
** Last update Tue Feb 23 00:12:28 2016 antoine
*/

#include <stdlib.h>
#include "../libcw/print.h"
#include "test.h"

static t_test_stats     g_test_stats;

void            fail_impl(const char *position)
{
  print_string_err(position);
  print_string_err(": Test failed");
  print_string_err("\n");
  g_test_stats.failed_test_count++;
}

void            assert_impl(int a, const char *position)
{
  if (!a)
    fail_impl(position);
  g_test_stats.total_test_count++;
}

int             main()
{
  g_test_stats.failed_test_count = 0;
  g_test_stats.total_test_count = 0;
  run_libcw_suites();
  run_asm_suites();
  run_vm_suites();
  print_int(g_test_stats.total_test_count);
  print_string(" tests, ");
  print_int(g_test_stats.failed_test_count);
  print_string(" failures\n");
  return (g_test_stats.failed_test_count != 0);
}
