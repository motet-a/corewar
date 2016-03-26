/*
** parse_line.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 14:00:57 2016 antoine
** Last update Fri Mar 25 14:00:57 2016 antoine
*/

#include <stdlib.h>
#include "asm.h"
#include "../libcw/string.h"
#include "../libcw/char_type.h"
#include "../libcw/parse_int.h"

static t_token          *try_to_read_token(t_token_list **list_pointer,
                                           t_token_type type)
{
  t_token               *token;

  if (!*list_pointer)
    return (NULL);
  token = (*list_pointer)->token;
  if (token->type == type)
    {
      *list_pointer = (*list_pointer)->next;
      return (token);
    }
  else
    return (NULL);
}

static t_syntax_error   *parse_label_def(t_program *program,
                                         t_token_list **list_pointer)
{
  t_token               *token;

  token = try_to_read_token(list_pointer, TOKEN_TYPE_LABEL_DEF);
  if (token)
    {
      label_list_add(&program->labels, token);
    }
  return (NULL);
}

static t_syntax_error   *parse_directive(t_program *program,
                                         t_token_list **list_pointer,
                                         int *ok)
{
  t_token               *directive;
  t_token               *string;
  int                   type;

  *ok = 0;
  directive = try_to_read_token(list_pointer, TOKEN_TYPE_DIRECTIVE);
  if (!directive)
    return (NULL);
  if (string_equals(directive->string_value, "name"))
    type = 0;
  else if (string_equals(directive->string_value, "comment"))
    type = 1;
  else
    return (syntax_error_new(&directive->position, "Invalid directive"));
  string = try_to_read_token(list_pointer, TOKEN_TYPE_STRING);
  if (!string)
    return (syntax_error_new(&directive->position, "Expected a string"));
  *ok = 1;
  return (NULL);
}

static t_syntax_error   *parse_register(t_argument *arg,
                                        const t_token *token)
{
  const char            *s;
  long                  number;

  arg->type = ARGUMENT_TYPE_REGISTER;
  s = token->string_value;
  if (string_get_length(s) < 2 || string_get_length(s) > 3 || s[0] != 'r')
    return (syntax_error_new(&token->position, "Unknown identifier"));
  s++;
  if (parse_int(s, &number))
    return (syntax_error_new(&token->position, "Invalid register name"));
  if (!(number >= 1 && number <= VM_REGISTER_COUNT))
    return (syntax_error_new(&token->position, "Invalid register number"));
  arg->value = number;
  return (NULL);
}

static t_syntax_error   *parse_arg_indirect(t_argument *arg,
                                            t_token_list **list_pointer,
                                            const t_token *previous)
{
  t_token               *token;

  token = try_to_read_token(list_pointer, TOKEN_TYPE_INTEGER);
  if (token)
    {
      arg->value = token->integer_value;
      return (NULL);
    }
  token = try_to_read_token(list_pointer, TOKEN_TYPE_LABEL_REF);
  if (token)
    {
      arg->label = string_duplicate(token->string_value);
      return (NULL);
    }
  token = try_to_read_token(list_pointer, TOKEN_TYPE_INSTRUCTION);
  if (token)
    return (parse_register(arg, token));
  return (syntax_error_new(&previous->position, "Expected value"));
}

static t_syntax_error   *parse_arg_direct(t_argument *arg,
                                          t_token_list **list_pointer,
                                          const t_token *percent)
{
  t_token               *token;

  token = try_to_read_token(list_pointer, TOKEN_TYPE_INTEGER);
  if (token)
    {
      arg->value = token->integer_value;
      return (NULL);
    }
  token = try_to_read_token(list_pointer, TOKEN_TYPE_LABEL_REF);
  if (token)
    {
      arg->label = string_duplicate(token->string_value);
      return (NULL);
    }
  return (syntax_error_new(&percent->position, "Expected value"));
}

static t_syntax_error   *parse_arg(t_argument *arg,
                                   t_token_list **list_pointer,
                                   const t_token *previous)
{
  t_token               *percent;

  arg->value = 0;
  arg->label = NULL;
  percent = try_to_read_token(list_pointer, TOKEN_TYPE_PERCENT);
  if (percent)
    {
      arg->type = ARGUMENT_TYPE_DIRECT;
      return (parse_arg_direct(arg, list_pointer, percent));
    }
  else
    {
      arg->type = ARGUMENT_TYPE_INDIRECT;
      return (parse_arg_indirect(arg, list_pointer, previous));
    }
}

static t_syntax_error   *parse_args(t_instr *instruction,
                                    t_token_list **list_pointer,
                                    const t_token *previous)
{
  int                   i;
  t_syntax_error        *error;
  t_token               *comma;

  i = -1;
  while (++i < instruction->info->argument_count)
    {
      if (i)
        {
          comma = try_to_read_token(list_pointer, TOKEN_TYPE_COMMA);
          if (!comma)
            return (syntax_error_new(&previous->position, "Expected comma"));
        }
      error = parse_arg(instruction->arguments + i, list_pointer, previous);
      if (error)
        return (error);
    }
  return (NULL);
}

static t_syntax_error   *parse_instr(const t_instr_info *infos,
                                     t_instr *instruction,
                                     t_token_list **list_pointer)
{
  t_token               *instr_token;
  const t_instr_info    *info;
  t_syntax_error        *error;


  instr_token = try_to_read_token(list_pointer, TOKEN_TYPE_INSTRUCTION);
  if (!instr_token)
    return (NULL);
  info = instr_info_get_from_name(infos, instr_token->string_value);
  if (!info)
    return (syntax_error_new(&instr_token->position, "Unknown instruction"));
  instruction->info = info;
  error = parse_args(instruction, list_pointer, instr_token);
  if (error)
    return (error);
  return (NULL);
}

static t_syntax_error   *parse_instr_2(t_program *program,
                                       t_token_list **list_pointer)
{
  t_syntax_error        *error;
  t_instr               instruction;

  instruction.info = NULL;
  error = parse_instr(program->instr_infos, &instruction, list_pointer);
  if (error || !instruction.info)
    return (error);
  program_add_instr(program, &instruction);
  return (NULL);
}

t_syntax_error          *parse_line(t_program *program,
                                    t_token_list **list_pointer)
{
  t_syntax_error        *error;
  t_token               *first;
  int                   ok;

  if (!*list_pointer)
    return (NULL);
  first = (*list_pointer)->token;
  error = parse_directive(program, list_pointer, &ok);
  if (error || ok)
    return (error);
  error = parse_label_def(program, list_pointer);
  if (error)
    return (error);
  error = parse_instr_2(program, list_pointer);
  if (error)
    return (error);
  if (!*list_pointer)
    return (NULL);
  if (!try_to_read_token(list_pointer, TOKEN_TYPE_NEW_LINE))
    return (syntax_error_new(&first->position, "Expected end of line"));
  return (NULL);
}
