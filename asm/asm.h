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

typedef struct          s_argument
{
  t_argument_type       type;
  char                  *label;
  long                  value;
}                       t_argument;

void                    argument_free(t_argument *arg);
void                    argument_print(const t_argument *arg);
int                     argument_get_size(const t_argument *arg);
char                    argument_get_descr(const t_argument *arg);
int                     argument_write(const t_argument *arg,
                                       int output_file);

typedef struct          s_instr
{
  const t_instr_info    *info;
  t_argument            arguments[VM_MAX_ARGUMENT_COUNT];
}                       t_instr;

void                    instr_free(t_instr *arg);
void                    instr_print(const t_instr *instr);
int                     instr_get_size(const t_instr *instr);
unsigned char           instr_get_arg_descr(const t_instr *instr);
int                     instr_write(const t_instr *instr, int output_file);

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
t_instr_list            *instr_list_get_last(t_instr_list *list);

void                    instr_list_print(const t_instr_list *list);

/*
** If instr is NULL, the label points to the end of the program
*/
typedef struct          s_label
{
  char                  *name;
  const t_instr         *instr;
  t_position            position;
}                       t_label;

void                    label_init(t_label *label, t_token *label_token);
void                    label_free(t_label *label);
void                    label_print(const t_label *label);

typedef struct          s_label_list
{
  t_label               label;
  struct s_label_list   *next;
}                       t_label_list;

t_label_list            *label_list_new(const t_label *label);
void                    label_list_delete(t_label_list *list);
void                    label_list_add(t_label_list **list,
                                       t_token *label_token);
t_label_list            *label_list_get_last(t_label_list *labels);

void                    label_list_print(const t_label_list *labels);

typedef struct  s_program
{
  char          *name;
  char          *comment;
  t_label_list  *labels;
  t_instr_list  *instructions;
  t_instr_info  instr_infos[32];
}               t_program;

t_syntax_error  *parse_line(t_program *program, t_token_list **list_pointer);

t_syntax_error  *program_parse(t_program *program, t_token_list *tokens);
void            program_add_instr(t_program *program, const t_instr *instr);
void            program_free(t_program *program);
void            program_print(const t_program *program);
int             program_write(const t_program *program, int output_file);

#endif /* ASM_H */
