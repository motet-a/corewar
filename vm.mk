##
## vm.mk for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Thu Mar  3 10:29:22 2016 antoine
## Last update Fri Mar 25 01:53:32 2016 Valentin Pichard
##

VM_SOURCES_NAMES	= \
			usage.c \
			option_extend.c \
			option.c \
			vm_initialize.c \
			vm_free.c \
			vm_create_process.c \
			vm_kill_process.c \
			vm_load_program.c \
			vm_instr_find_type_value.c \
			vm_instr_ld.c \
			vm_instr_add_sub.c \
			vm_instr_and_or.c \
			vm_instr_aff.c \

VM_SOURCES		= $(foreach file,$(VM_SOURCES_NAMES), \
			corewar/$(file))

VM_OBJECTS		= $(VM_SOURCES:.c=.o)
