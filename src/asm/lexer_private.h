/*
** lexer_private.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar  9 13:11:54 2016 antoine
** Last update Wed Mar  9 13:11:54 2016 antoine
*/

#ifndef LEXER_PRIVATE_H
# define LEXER_PRIVATE_H

# include "lexer.h"

typedef struct          s_result
{
  t_syntax_error        *error;
  t_token               *token;
}                       t_result;

typedef t_result        (*t_lexer_function)(t_string_reader *reader);

# define has_more(reader)       string_reader_has_more(reader)
# define next(reader)           string_reader_next(reader)

#endif /* LEXER_PRIVATE_H */
