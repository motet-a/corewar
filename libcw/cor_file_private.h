/*
** cor_file_private.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Feb 23 09:04:07 2016 antoine
** Last update Tue Feb 23 09:04:07 2016 antoine
*/

#ifndef COR_FILE_PRIVATE_H
# define COR_FILE_PRIVATE_H

# include "cor_file.h"

# define NAME_LENGTH           128
# define COMMENT_LENGTH        2048

# define NO_MEMORY_ERROR "cannot allocate memory"
# define READ_ERROR "read error"
# define WRITE_ERROR "write error"
# define HEADER_TOO_SHORT_ERROR "header to short"
# define NAME_TOO_LONG_ERROR "name to long"
# define COMMENT_TOO_LONG_ERROR "comment to long"
# define BAD_MAGIC_NUMBER_ERROR "bad magic number"

#endif /* COR_FILE_PRIVATE_H */
