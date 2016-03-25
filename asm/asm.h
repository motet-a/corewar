/*
** asm.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 18:05:05 2016 antoine
** Last update Mon Feb 29 13:05:23 2016 Antoine Baudrand
*/

#ifndef ASM_H
# define ASM_H

# include "../libcw/instr.h"
# include "lexer.h"

typedef struct          s_instr
{
  const t_instr_info    *info;
}                       t_instr;

typedef struct          s_instr_list
{
  t_instr               instr;
  struct s_instr_list   *next;
}                       t_instr_list;

t_instr_list            *instr_list_new(const t_instr *instr,
                                        t_instr_list *next);
void                    instr_list_add(t_instr_list **list_pointer,
                                       const t_instr *instr);
void                    instr_list_delete(t_instr_list *list);

/*
** If instr is NULL, the label points to the end of the program
*/
typedef struct          s_label
{
  char                  *name;
  const t_instr         *instr;
}                       t_label;

typedef struct          s_label_list
{
  t_label               label;
  struct s_label_list   *next;
}                       t_label_list;

typedef struct  s_program
{
  t_label_list  *labels;
  t_instr_list  *intructions;
}               t_program;

t_syntax_error  program_parse(t_program *program,
                              const t_token_list *tokens);
void            program_free(t_program *program);
void            program_print(const t_program *program);
void            program_write(const t_program *program, int output_file);

#endif /* ASM_H */
