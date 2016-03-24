/*
** vm.h for vm in /home/antoine/corewar/src/vm
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Tue Mar  8 23:44:36 2016 Valentin Pichard
** Last update jeu. mars 24 12:52:15 2016 Antoine Baudrand
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
}			t_program;

typedef struct  s_vm
{
  int		cycle;
  int		number_of_programs;
  t_program	**programs;
  t_process     *processes;
  char          *memory;
}              t_vm;

/*
** Initialize the VM
**
** Returns a t_vm* on success, NULL on error.
*/
t_vm	*vm_new(int number_of_programs);

/*
** Free all the vm including memory, programs, and processes
*/
void	vm_free(t_vm *);

/*
** Load a program and create process from its header
** and a file descriptor on the first byte of the program
*/
void	vm_load_program(t_vm *, t_cor_file_header *, int fd);

void	vm_cycle(t_vm *);

#endif /* VM_H */
