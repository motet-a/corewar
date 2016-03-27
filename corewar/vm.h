/*
** vm.h for corewar in /home/antoine/corewar/corewar
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Tue Mar  8 23:44:36 2016 Valentin Pichard
** Last update dim. mars 27 14:35:19 2016 Antoine Baudrand
*/

#ifndef VM_H
# define VM_H

# include <stddef.h>
# include "../libcw/instr.h"
# include "../libcw/cor_file.h"
#include "options.h"

# define CYCLE_TO_DIE           1536
# define CYCLE_DELTA            4
# define MEMORY_SIZE            (6 * 1024)
# define IDX_MOD                512
# define NBR_LIVE		2048

void		print_usage(const char *filename);

typedef struct          s_parser_state
{
  char                  **argv;
  int                   argc;
  int                   index;
  const t_option        *options;
}                       t_parser_state;

typedef struct          s_program_opt
{
  const char            *name;
  int                   number;
  int                   address;
}                       t_program_opt;

void                    program_opt_init(t_program_opt *program);

typedef	struct		s_program
{
  char			*name;
  char			*comment;
  char                  *code;
  int			live_id;
  int			last_live_cycle;
  int			alive;
  int                   size;
}			t_program;

/*
** instruction: The current instruction.
** remaining_cycles: The remaining cycle count of the execution
** of the current instruction.
*/
typedef struct  	s_process
{
  int           	pc;
  int           	carry;
  int           	registers[VM_REGISTER_COUNT];
  char          	instruction;
  int           	remaining_cycles;
  t_program		*program;
  struct s_process	*next;
}               	t_process;

typedef struct  s_vm
{
  int		cycle;
  int		cycle_to_die;
  int		live_count;
  int		program_count;
  t_program	*programs;
  t_process     *processes;
  char          *memory;
}		t_vm;

/*
** Initializes the VM
**
** Returns 0 on success, -1 on error.
*/
int     vm_init(t_vm *vm);

/*
** Frees all the VM including memory, programs, and processes
*/
void	vm_free(t_vm *vm);

/*
** Return 0 on success, -1 on error.
*/
int	vm_load_program(t_vm *vm, const char *file_path);

void	vm_create_process(t_vm *vm, int pc, t_program *);

/*
** Return 0 on success, -1 on error.
*/
int	vm_kill_process(t_vm *vm, t_process *process);

/*
** Run the vm, run cycles
** TODO
*/
void	vm_run(t_vm *);

/*
** Run a machine cycle
** Return 0 if there is no processes
*/
int	vm_cycle(t_vm *);

/*
** Check alive programs
*/
void	vm_check_alive(t_vm *);

#endif /* VM_H */
