/*
** vm_load_program.c for corewar in /home/antoine/corewar/corewar
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  ven. mars 25 18:45:49 2016 Antoine Baudrand
** Last update dim. mars 27 13:18:16 2016 Antoine Baudrand
*/

#include "vm.h"
#include <sys/stat.h>
#include <fcntl.h>
#include "vm.h"
#include "../libcw/cor_file.h"
#include <stdlib.h>
#include "unistd.h"
#include "../libcw/print.h"

static void	create_program(t_vm *vm, const t_cor_file_header *header,
			       int index)
{
  vm->programs[index].name = header->name;
  vm->programs[index].comment = header->comment;
  vm->programs[index].last_live_cycle = 0;
  vm->programs[index].alive = 1;
}

static void	load_in_memory(int fd, int program_size, int pc, char *memory)
{
  if (read(fd, &memory[pc], program_size) != program_size)
    {
      print_string_err("Error .cor file corrupted\n");
      exit(-1);
    }
}

int				vm_load_program(t_vm *vm, const char *file, int index)
{
  int				fd;
  t_cor_file_header		header;
  int				pc;

  if ((fd = open(file, O_RDONLY)) >= 0)
    {
      if (cor_file_header_read(&header, fd))
	return (-1);
      pc = (MEMORY_SIZE / vm->program_count) * index;
      create_program(vm, &header, index);
      if (header.program_size > (MEMORY_SIZE / vm->program_count))
	return (-1);
      else
	{
	  load_in_memory(fd, header.program_size, pc, vm->memory);
	  vm_create_process(vm, pc, &vm->programs[index]);
	}
      return (0);
    }
  else
    return (-1);
}
