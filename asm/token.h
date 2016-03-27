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
  TOKEN_TYPE_INSTRUCTION,
  TOKEN_TYPE_INTEGER,
  TOKEN_TYPE_STRING,
  TOKEN_TYPE_DIRECTIVE,
  TOKEN_TYPE_COMMENT,
  TOKEN_TYPE_LABEL_DEF,
  TOKEN_TYPE_LABEL_REF,
  TOKEN_TYPE_COMMA,
  TOKEN_TYPE_PERCENT,
  TOKEN_TYPE_NEW_LINE,
}               t_token_type;

const char      *token_type_to_string(t_token_type type);
int             token_type_has_string_value(t_token_type type);
int             token_type_has_value(t_token_type type);

/*
** string_value: For TOKEN_TYPE_INSTRUCTION, TOKEN_TYPE_STRING,
** TOKEN_TYPE_DIRECTIVE, TOKEN_TYPE_LABEL_DEF or TOKEN_TYPE_LABEL_REF.
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
** Creates a token of type TOKEN_TYPE_INSTRUCTION, TOKEN_TYPE_STRING,
** TOKEN_TYPE_DIRECTIVE, TOKEN_TYPE_LABEL_DEF or TOKEN_TYPE_LABEL_REF.
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
*/
char            *token_to_string(const t_token *token);

/*
** Prints the string returned by token_to_string().
*/
void            token_print(const t_token *token, int output_file);

int             token_has_value(const t_token *token);
int             token_has_string_value(const t_token *token);

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
void            token_list_delete(t_token_list *list, int delete_tokens);
t_token_list    *token_list_get_last(t_token_list *list);

/*
** Returns a malloced string for debugging purposes.
** Returns NULL on error.
*/
char            *token_list_to_string(const t_token_list *list);

/*
** Prints the string returned by token_to_string().
*/
void            token_list_print(const t_token_list *list,
                                 const char *separator,
                                 int output_file);

#endif /* TOKEN_H */
