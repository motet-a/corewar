/*
** test.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Feb 24 20:01:52 2016 antoine
** Last update Wed Mar  9 11:14:01 2016 Valentin Pichard
*/

#ifndef TEST_H
# define TEST_H

# define STRINGIFY_(s)          #s
# define STRINGIFY(s)           STRINGIFY_(s)

# define TEST_GET_POSITION()    (__FILE__ ":" STRINGIFY(__LINE__))

void                    fail_impl(const char *position);
void                    assert_impl(int a, const char *position);

# define FAIL()         fail_impl(TEST_GET_POSITION())
# define ASSERT(a)      assert_impl(a, TEST_GET_POSITION())

typedef struct          s_test_stats
{
  int                   failed_test_count;
  int                   total_test_count;
}                       t_test_stats;

void    test_suite_memory(void);
void    test_suite_parse_int(void);
void    test_suite_string_concat(void);
void    test_suite_string_find_char(void);
void    test_suite_string_find(void);
void    test_suite_token_list(void);
void    test_suite_string_type(void);
void    test_suite_string_type_convert(void);
void    test_suite_int_to_string(void);

#endif /* TEST_H */
