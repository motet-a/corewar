/*
** vm.h for corewar in /home/antoine/corewar/corewar
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Tue Mar  8 23:44:36 2016 Valentin Pichard
** Last update Thu Mar 24 23:07:50 2016 Jamy Bailly
*/

#ifndef VM_H
# define VM_H

# include <stddef.h>
# include "../libcw/instr.h"
# include "../libcw/cor_file.h"

# define CYCLE_TO_DIE           1536
# define CYCLE_DELTA            4
# define LIVE_CALL_COUNT        2048
# define MEMORY_SIZE            (6 * 1024)
# define IDX_MOD                512
# define NBR_LIVE		2048

void		print_usage(const char *filename);

/*
** instruction: The current instruction.
** remaining_cycles: The remaining cycle count of the execution
** of the current instruction.
*/
typedef struct  	s_process
{
  int           	pc;
  int           	carry;
  int           	*registers[VM_REGISTER_COUNT];
  char          	instruction;
  int           	remaining_cycles;
  struct s_process	*next;
}               	t_process;

typedef	struct		s_program
{
  char			*name;
  char			*comment;
  int			live_id;
  int			last_live_cycle;
  int			alive;
}			t_program;

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
** Returns a t_vm* on success, NULL on error.
*/
t_vm	*vm_new(int program_count);

/*
** Allocates and initializes the memory of the VM
** Returns 0 on success, -1 on error.
*/
int    vm_init_memory(char *memory);

/*
** Frees all the VM including memory, programs, and processes
** TODO
*/
void	vm_free(t_vm *);

/*
** Loads a program and creates a process from its header
** and a file descriptor on the first byte of the program
** TODO
*/
void	vm_load_program(t_vm *, const t_cor_file_header *, int fd);

/*
** Run the vm, run cycles
** TODO
*/
void	vm_run(t_vm *);

/*
** Run a machine cycle
** TODO
*/
void	vm_cycle(t_vm *);

/*
** Check alive programs
** TODO
*/
int	vm_check_alive(t_vm *);

#endif /* VM_H */
