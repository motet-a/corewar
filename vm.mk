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
			vm_ld.c \
			vm_aff.c \

VM_SOURCES		= $(foreach file,$(VM_SOURCES_NAMES), \
			corewar/$(file))

VM_OBJECTS		= $(VM_SOURCES:.c=.o)
