##
## vm.mk for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Thu Mar  3 10:29:22 2016 antoine
## Last update Thu Mar  3 10:29:22 2016 antoine
##

VM_SOURCES_NAMES	=

VM_SOURCES		= $(foreach file,$(VM_SOURCES_NAMES), \
			src/vm/$(file))

VM_OBJECTS		= $(VM_SOURCES:.c=.o)
