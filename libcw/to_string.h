/*
** to_string.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar  4 13:03:25 2016 antoine
** Last update Fri Mar  4 13:03:25 2016 antoine
*/

#ifndef TO_STRING_H
# define TO_STRING_H

# include "stddef.h"

size_t  uint_to_string_base_get_length(unsigned long integer,
                                       unsigned base);
size_t  int_to_string_base_get_length(long integer, unsigned base);
size_t  int_to_string_get_length(long integer);

/*
** Writes an integer into the given buffer.
** The buffer must be large enougth to contain `max_size` bytes,
** including the terminating null byte ('\0').
** Returns 0 on success, -1 on error.
*/
int     int_to_string_base(long integer,
                           char *buffer,
                           size_t max_size,
                           unsigned base);

/*
** Writes an integer into the given buffer.
** The buffer must be large enougth to contain `max_size` bytes,
** including the terminating null byte ('\0').
** Returns 0 on success, -1 on error.
*/
int     int_to_string(long integer, char *buffer, size_t max_size);

/*
** Returns a malloced string.
** Returns NULL on error.
*/
char    *int_to_malloced_string_base(long integer, unsigned base);

/*
** Returns a malloced string.
** Returns NULL on error.
*/
char    *int_to_malloced_string(long integer);

#endif /* TO_STRING_H */
