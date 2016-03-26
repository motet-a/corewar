/*
** parse_instr.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Mar 26 18:17:39 2016 antoine
** Last update Sat Mar 26 18:17:39 2016 antoine
*/

#include <stdlib.h>
#include "asm.h"

static void             free_args(t_instr *instruction, int count)
{
  while (count)
    {
      count--;
      argument_free(instruction->arguments + count);
    }
}

static t_syntax_error   *parse_args(t_instr *instruction,
                                    t_token_list **list_pointer,
                                    const t_token *prev)
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
            {
              free_args(instruction, i);
              return (syntax_error_new(&prev->position, "Expected comma"));
            }
        }
      error = parse_arg(instruction->arguments + i, list_pointer, prev);
      if (error)
        {
          free_args(instruction, i);
          return (error);
        }
    }
  return (NULL);
}

static t_syntax_error   *parse_instr_2(const t_instr_info *infos,
                                       t_instr *instruction,
                                       t_token_list **list_pointer)
{
  t_token               *instr_token;
  const t_instr_info    *info;
  t_syntax_error        *error;

  instr_token = try_to_read_token(list_pointer, TOKEN_TYPE_INSTRUCTION);
  if (!instr_token)
    return (NULL);
  instruction->position = instr_token->position;
  info = instr_info_get_from_name(infos, instr_token->string_value);
  if (!info)
    return (syntax_error_new(&instr_token->position, "Unknown instruction"));
  instruction->info = info;
  error = parse_args(instruction, list_pointer, instr_token);
  if (error)
    return (error);
  return (NULL);
}

t_syntax_error          *parse_instr(t_program *program,
                                     t_token_list **list_pointer)
{
  t_syntax_error        *error;
  t_instr               instruction;

  instruction.info = NULL;
  error = parse_instr_2(program->instr_infos, &instruction, list_pointer);
  if (error || !instruction.info)
    return (error);
  program_add_instr(program, &instruction);
  return (NULL);
}
