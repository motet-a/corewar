##
## vm.mk for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Thu Mar  3 10:29:22 2016 antoine
## Last update Sun Mar 27 22:28:13 2016 Valentin Pichard
##

VM_SOURCES_NAMES	= \
			usage.c \
			vm_init.c \
			vm_free.c \
			vm_create_process.c \
			vm_kill_process.c \
			vm_load_program.c \
			vm_cycle.c \
			vm_run.c \
			options.c \
			instructions/read_int.c \
			instructions/write_int.c \
			instructions/ld.c \
			instructions/st.c \
			instructions/add.c \
			instructions/sub.c \
			instructions/and.c \
			instructions/or.c \
			instructions/xor.c \
			instructions/zjmp.c \
			instructions/aff.c \

VM_SOURCES		= $(foreach file,$(VM_SOURCES_NAMES), \
			corewar/$(file))

VM_OBJECTS		= $(VM_SOURCES:.c=.o)
