##
## asm.mk for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Thu Mar  3 09:59:21 2016 antoine
## Last update Thu Mar  3 09:59:21 2016 antoine
##

ASM_SOURCES_NAMES	= token.c \
			token_has_value.c \
			token_list.c \
			token_to_string.c \
			token_type.c

ASM_SOURCES		= $(foreach file,$(ASM_SOURCES_NAMES), \
			src/asm/$(file))

ASM_OBJECTS		= $(ASM_SOURCES:.c=.o)
