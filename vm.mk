##
## vm.mk for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Thu Mar  3 10:29:22 2016 antoine
## Last update Tue Mar 22 00:14:43 2016 Valentin Pichard
##

VM_SOURCES_NAMES	= \
			usage.c \
			option_extend.c \
			option.c \
			vm_init_options.c \
			vm_new.c \
			vm_memory.c

VM_SOURCES		= $(foreach file,$(VM_SOURCES_NAMES), \
			corewar/$(file))

VM_OBJECTS		= $(VM_SOURCES:.c=.o)
