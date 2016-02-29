/*
** token.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 18:05:12 2016 antoine
** Last update Fri Feb 26 18:05:12 2016 antoine
*/

#ifndef TOKEN_H
# define TOKEN_H

#include "../libcw/position.h"

typedef enum    e_token_type
{
  TOKEN_TYPE_IDENTIFIER,
  TOKEN_TYPE_INTEGER,
  TOKEN_TYPE_STRING,
  TOKEN_TYPE_DIRECTIVE,
  TOKEN_TYPE_COMMENT,
  TOKEN_TYPE_LABEL,
  TOKEN_TYPE_COMMA,
  TOKEN_TYPE_PERCENT,
}               t_token_type;

const char      *token_type_to_string(t_token_type type);

/*
** string_value: For TOKEN_TYPE_IDENTIFIER, TOKEN_TYPE_STRING,
** TOKEN_TYPE_DIRECTIVE or TOKEN_TYPE_LABEL.
**
** int_value: For TOKEN_TYPE_INTEGER
*/
typedef struct  s_token
{
  t_position    position;
  t_token_type  type;
  char          *string_value;
  long          integer_value;
}               t_token;

/*
** Creates a token.
**
** Does not initialize the value of the token.
** The returned token must be freed with token_delete().
** Returns NULL on error.
*/
t_token         *token_new(t_token_type type,
                           const t_position *position);

/*
** Creates a token of type TOKEN_TYPE_IDENTIFIER, TOKEN_TYPE_STRING,
** TOKEN_TYPE_DIRECTIVE or TOKEN_TYPE_LABEL.
**
** The returned token must be freed with token_delete().
** Returns NULL on error.
*/
t_token         *token_new_string(t_token_type type,
                                  const t_position *position,
                                  const char *string);

void            token_delete(t_token *token);

/*
** Returns a malloced string for debugging purposes.
** Returns NULL on error.
** TODO
*/
char            *token_to_string(const t_token *token);

/*
** Prints the string returned by token_to_string().
*/
void            token_print(const t_token *token, int output_file);

typedef struct          s_token_list
{
  t_token               *token;
  struct s_token_list   *next;
}                       t_token_list;

/*
** Returns NULL on error.
*/
t_token_list    *token_list_new(t_token *token, t_token_list *next);
void            token_list_add(t_token_list **list, t_token *token);
void            token_list_free(t_token_list *list, int delete_tokens);

/*
** Returns a malloced string for debugging purposes.
** Returns NULL on error.
** TODO
*/
char            *token_list_to_string(const t_token_list *list);

/*
** Prints the string returned by token_to_string().
*/
void            token_list_print(const t_token_list *list, int output_file);

#endif /* TOKEN_H */
