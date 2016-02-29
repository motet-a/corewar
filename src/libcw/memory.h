/*
** memory.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Feb 24 19:38:13 2016 antoine
** Last update Wed Feb 24 19:38:13 2016 antoine
*/

#ifndef MEMORY_H
# define MEMORY_H

/*
** Just some functions to deal with endianness.
*/
int     memory_read_int_16(const char *memory);
long    memory_read_int_32(const char *memory);

void    memory_write_int_16(char *memory, int n);
void    memory_write_int_32(char *memory, long n);

#endif /* MEMORY_H */
