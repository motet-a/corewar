/*
** lexer.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 29 14:24:36 2016 antoine
** Last update Mon Feb 29 14:24:36 2016 antoine
*/

#ifndef LEXER_H
# define LEXER_H

# include "token.h"
# include "../libcw/position.h"
# include "../libcw/string_reader.h"

typedef struct          s_syntax_error
{
  t_position            position;
  char                  *message;
}                       t_syntax_error;

t_syntax_error          *syntax_error_new(const t_position *position,
                                          const char *message);

void                    syntax_error_delete(t_syntax_error *syntax_error);

void                    syntax_error_print(const t_syntax_error *error,
                                           int output_file);

typedef struct          s_lexer_result
{
  t_syntax_error        syntax_error;
}                       t_lexer_result;

/* TODO */
t_lexer_result          lex_from_string(const char *string);
/* TODO */
t_lexer_result          lex(t_string_reader *string_reader);

#endif /* LEXER_H */
