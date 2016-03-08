##
## vm.mk for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Thu Mar  3 10:29:22 2016 antoine
## Last update Tue Mar  8 23:58:44 2016 Valentin Pichard
##

VM_SOURCES_NAMES	= main.c \
										usage.c

VM_SOURCES		= $(foreach file,$(VM_SOURCES_NAMES), \
			src/vm/$(file))

VM_OBJECTS		= $(VM_SOURCES:.c=.o)
