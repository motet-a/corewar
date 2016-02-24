/*
** test.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Feb 24 20:01:52 2016 antoine
** Last update Wed Feb 24 20:01:52 2016 antoine
*/

#ifndef TEST_H
# define TEST_H

# define STRINGIFY_(s) #s
# define STRINGIFY(s) STRINGIFY_(s)

# define TEST_GET_POSITION() (__FILE__ ":" STRINGIFY(__LINE__))

# define FAIL() fail_impl(TEST_GET_POSITION())
# define ASSERT(a) assert_impl(a, TEST_GET_POSITION())

#endif /* TEST_H */
