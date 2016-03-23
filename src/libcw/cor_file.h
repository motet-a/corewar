/*
** cor_file.h for libcw in /home/antoine/corewar/src/libcw
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Feb 23 08:50:24 2016 antoine
** Last update mer. mars 23 21:22:53 2016 Antoine Baudrand
*/

#ifndef COR_FILE_H
# define COR_FILE_H

# define NAME_LENGTH          	128
# define COMMENT_LENGTH		2048
# define COREWAR_EXEC_MAGIC	0xea83f3

/*
** The header of the .cor binary files
*/
typedef struct          s_cor_file_header
{
  int			magic;
  char                  name[NAME_LENGTH + 1];
  int                   program_size;
  char                  comment[COMMENT_LENGTH + 1];
}                       t_cor_file_header;

/*
** Returns NULL on success
** Returns a string describing the issue on error
** TODO
*/
const char      *cor_file_header_init(t_cor_file_header *self,
                                      const char *name,
                                      const char *comment,
                                      int program_size);
void            cor_file_header_free(t_cor_file_header *self);

/*
** Writes a header to a binary file.
**
** Returns NULL on success
** Returns a string describing the issue on error
** TODO
*/
const char      *cor_file_header_write(const t_cor_file_header *self,
                                       int output_file);

/*
** Reads a header from a binary file.
**
** Returns NULL on success
** Returns a string describing the issue on error
** TODO
*/
const char      *cor_file_header_read(t_cor_file_header *self,
                                      int input_file);

/*
** Prints the header in a human-readable format for debugging purposes.
*/
void            cor_file_header_print(const t_cor_file_header *self);

/*
** Returns 0 on success and -1 on error.
** TODO
*/
int             cor_file_read_int_16(int input_file, int *result);

/*
** Returns 0 on success and -1 on error.
** TODO
*/
int             cor_file_read_int_32(int input_file, long *result);

/*
** Returns 0 on success and -1 on error.
** TODO
*/
int             cor_file_write_int_16(int input_file, int n);

/*
** Returns 0 on success and -1 on error.
** TODO
*/
int             cor_file_write_int_32(int input_file, long n);

#endif /* COR_FILE_H */
