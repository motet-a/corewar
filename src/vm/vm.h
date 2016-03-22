/*
** vm.h for  in /Users/westery/Documents/tek1/CPE/corewar/src/vm/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Tue Mar  8 23:44:36 2016 Valentin Pichard
** Last update Tue Mar 22 12:17:54 2016 Jamy Bailly
*/

#ifndef VM_H
# define VM_H

# include <stddef.h>
# include "../libcw/instr.h"

# define CYCLE_TO_DIE           1536
# define CYCLE_DELTA            4
# define LIVE_CALL_COUNT        2048
# define MEMORY_SIZE            (6*1024)

void		print_usage(const char *filename);

/*
** instruction: The current instruction.
** remaining_cycles: The remaining cycle count of the execution
** of the current instruction.
*/
typedef struct  s_process
{
  int           pc;
  int           carry;
  int           *registers[VM_REGISTER_COUNT];
  char          instruction;
  int           remaining_cycles;
}               t_process;

typedef struct  s_vm
{
  size_t        process_count;
  t_process     *processes;
  char          *memory;
}               t_vm;

#endif /* VM_H */
