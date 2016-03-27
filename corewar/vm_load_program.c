/*
** vm_load_program.c for corewar in /home/antoine/corewar/corewar
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  ven. mars 25 18:45:49 2016 Antoine Baudrand
** Last update Sun Mar 27 23:50:15 2016 Jamy Bailly
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "vm.h"
#include "../libcw/cor_file.h"
#include "../libcw/print.h"

static int      read_program_code(t_program *program, int fd)
{
  program->code = malloc(program->size);
  if (!program->code)
    return (-1);
  if (read(fd, program->code, program->size) != program->size)
    {
      print_string_err("Error .cor file corrupted\n");
      free(program->code);
      return (-1);
    }
  return (0);
}

static int      create_program(t_vm *vm,
                               const t_cor_file_header *header,
                               int fd)
{
  t_program     *p;

  vm->programs = realloc(vm->programs, vm->program_count + 1);
  if (!vm->programs)
    return (-1);
  p = vm->programs + vm->program_count;
  p->name = header->name;
  p->comment = header->comment;
  p->last_live_cycle = 0;
  p->alive = 1;
  p->size = header->program_size;
  if (read_program_code(p, fd))
    return (-1);
  vm->program_count++;
  return (0);
}

static int              read_program(t_vm *vm, int fd)
{
  t_cor_file_header     header;

  if (cor_file_header_read(&header, fd))
    return (-1);
  if (header.program_size > (MEMORY_SIZE / vm->program_count))
    {
      cor_file_header_free(&header);
      return (-1);
    }
  if (create_program(vm, &header, fd))
    {
      cor_file_header_free(&header);
      return (-1);
    }
  cor_file_header_free(&header);
  return (0);
}

int     vm_load_program(t_vm *vm, const char *file)
{
  int   fd;
  int   r;

  if ((fd = open(file, O_RDONLY)) < 0)
    return (-1);
  r = read_program(vm, fd);
  close(fd);
  return (r);
}
