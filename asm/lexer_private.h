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

static t_lexer_result   lexer_result_create_tokens(t_token_list *tokens);
static t_lexer_result   lexer_result_create_error(t_syntax_error *error);
static t_result         create_error_result(const char *message,
                                            const t_position *position);
static t_result         create_token_result_2(t_token *token);
static t_result         create_token_result(const t_position *begin,
                                            t_token_type type);
static t_result         create_string_token_result(const t_position *begin,
                                                   t_string_reader *reader,
                                                   t_token_type type);
static t_result         create_null_result(void);

static t_result         lex_instruction(t_string_reader *reader);
static char             *get_string(const t_position *begin,
                                    t_string_reader *reader);

#endif /* LEXER_PRIVATE_H */
