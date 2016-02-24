/*
** print.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 22 22:52:08 2016 antoine
** Last update Mon Feb 22 22:52:08 2016 antoine
*/

#ifndef PRINT_H
# define PRINT_H

void            print_uint_file(unsigned long n, int file);
void            print_int_file(long n, int file);
void            print_uint(unsigned long n);
void            print_int(long n);

void            print_char_file(char c, int file);
void            print_char(char c);

/*
** Prints a string to the given file.
*/
void            print_string_file(const char *string, int file);

/*
** Prints a string to the standard output.
*/
void            print_string(const char *string);

/*
** Prints a string to the error output.
*/
void            print_string_err(const char *string);

/*
** Prints n times the character c to the given file.
*/
void            print_n_chars_file(char c, int n, int file);

/*
** Prints n times the character c to the standard output.
*/
void            print_n_chars(char c, int n);

#endif /* PRINT_H */
