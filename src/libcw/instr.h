/*
** instr.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Feb 23 10:25:13 2016 antoine
** Last update Tue Feb 23 10:25:13 2016 antoine
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
# define VM_DIRECT_ARGUMENT_SIZE        4
# define VM_INDIRECT_ARGUMENT_SIZE      VM_ADRESS_SIZE

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
}                       t_instr_info;

/*
** Returns an instruction or NULL
*/
const t_instr_info      *instr_info_get_from_name(const char *name);

/*
** Returns an instruction or NULL
*/
const t_instr_info      *instr_info_get_from_code(char code);

void                    instr_info_print(const t_instr_info *self);

int             instr_info_get_arguments_size(const t_instr_info *self);

#endif /* INSTR_H */