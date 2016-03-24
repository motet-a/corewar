/*
** token_has_value.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 29 19:09:37 2016 antoine
** Last update Mon Feb 29 19:09:37 2016 antoine
*/

#include "token.h"

int             token_has_value(const t_token *token)
{
  return (token_type_has_value(token->type));
}

int             token_has_string_value(const t_token *token)
{
  return (token_type_has_string_value(token->type));
}
