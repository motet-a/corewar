/*
** instr.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Feb 23 10:25:13 2016 antoine
** Last update Thu Mar 24 23:30:33 2016 Valentin Pichard
*/

#ifndef INSTR_H
# define INSTR_H

/*
** r1 <--> r16
*/
# define VM_REGISTER_COUNT      16

/*
** All the following sizes are in bytes.
*/
# define VM_REGISTER_SIZE               4
# define VM_ADDRESS_SIZE                2

# define VM_REGISTER_ARGUMENT_SIZE      1
# define VM_DIRECT_ARGUMENT_SIZE        VM_REGISTER_SIZE
# define VM_INDIRECT_ARGUMENT_SIZE      VM_ADDRESS_SIZE

/*
** Do not change.
*/
# define VM_MAX_ARGUMENT_COUNT          4

typedef int                             t_argument_type;

# define ARGUMENT_TYPE_REGISTER         ((t_argument_type)(1 << 0))
# define ARGUMENT_TYPE_DIRECT           ((t_argument_type)(1 << 1))
# define ARGUMENT_TYPE_INDIRECT         ((t_argument_type)(1 << 2))

/*
** has_argument_descriptor: true if the instruction has an
** argument descriptor byte.
*/
typedef struct          s_instr_info
{
  const char            *name;
  char                  code;
  int                   has_argument_descriptor;
  int                   argument_count;
  int                   cycle_count;
  t_argument_type       argument_types[VM_MAX_ARGUMENT_COUNT];
  const char            *comment;
}                       t_instr_info;

/*
** Returns an instruction or NULL
*/
const t_instr_info      *instr_info_get_from_name(const t_instr_info *list,
                                                  const char *name);

/*
** Returns an instruction or NULL
*/
const t_instr_info      *instr_info_get_from_code(const t_instr_info *list,
                                                  char code);

int                     instr_info_get_count(const t_instr_info *list);

void                    instr_info_print(const t_instr_info *self);

void                    instr_info_print_list(const t_instr_info *list);

void            instr_info_get_list(t_instr_info *list);

/*
** Used by instr_info_get_list()
*/
t_instr_info    *instr_info_get_list_0(t_instr_info *list);
t_instr_info    *instr_info_get_list_1(t_instr_info *list);
t_instr_info    *instr_info_get_list_2(t_instr_info *list);
t_instr_info    *instr_info_get_list_3(t_instr_info *list);

#endif /* INSTR_H */
