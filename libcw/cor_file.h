/*
** cor_file.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Feb 23 08:50:24 2016 antoine
** Last update Tue Feb 23 08:50:24 2016 antoine
*/

#ifndef COR_FILE_H
# define COR_FILE_H

/*
** The header of the .cor binary files
*/
typedef struct          s_cor_file_header
{
  char                  *name;
  char                  *comment;
  int                   program_size;
}                       t_cor_file_header;

/*
** Returns NULL on success
** Returns a string describing the issue on error
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
*/
const char      *cor_file_header_write(const t_cor_file_header *self,
                                       int output_file);

/*
** Reads a header from a binary file.
**
** Returns NULL on success
** Returns a string describing the issue on error
*/
const char      *cor_file_header_read(t_cor_file_header *self,
                                      int input_file);

/*
** Prints the header in a human-readable format for debugging purposes.
*/
void            cor_file_header_print(const t_cor_file_header *self);

#endif /* COR_FILE_H */
