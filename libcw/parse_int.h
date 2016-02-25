/*
** parse_int.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 22 23:36:07 2016 antoine
** Last update Mon Feb 22 23:36:07 2016 antoine
*/

#ifndef PARSE_INT_H
# define PARSE_INT_H

/*
** Parses an unsigned integer.
**
** Returns 0 on success, -1 on error.
** On success, string_pointer is incremented.
*/
int     parse_and_read_uint_base(const char **string_pointer,
                                 unsigned long *result_pointer,
                                 int base);

/*
** Parses a signed integer.
**
** It can be preceded by one or more '-' signs.
**
** Returns 0 on success, -1 on error.
** On success, string_pointer is incremented.
*/
int     parse_and_read_int_base(const char **string_pointer,
                                long *result_pointer,
                                int base);

int     parse_and_read_uint(const char **string_pointer,
                            unsigned long *result_pointer);
int     parse_and_read_int(const char **string_pointer,
                           long *result_pointer);

/*
** Parses an unsigned long integer in a given base.
**
** If the base is greater than 9, the character `a` is considered
** as the 10th digit, `b` is the 11th digit, etc. The case is ignored.
** Writes the parsed number at the given address on success.
** Returns 0 on success, -1 on error.
*/
int     parse_uint_base(const char *string,
                        unsigned long *result_pointer,
                        int base);

/*
** Parses a long integer in a given base.
**
** It can be preceded by one or more '-' signs.
**
** If the base is greater than 9, the character `a` is considered
** as the 10th digit, `b` is the 11th digit, etc. The case is ignored.
** Writes the parsed number at the given address on success.
** Returns 0 on success, -1 on error.
*/
int     parse_int_base(const char *string,
                       long *result_pointer,
                       int base);

/*
** Parses an unsigned long integer.
**
** Writes the parsed number at the given address on success.
** Returns 0 on success, -1 on error.
*/
int     parse_uint(const char *string, unsigned long *result_pointer);

/*
** Parses a long integer.
**
** It can be preceded by one or more '-' signs.
**
** Writes the parsed number at the given address on success.
** Returns 0 on success, -1 on error.
*/
int     parse_int(const char *string, long *result_pointer);

#endif /* PARSE_INT_H */
