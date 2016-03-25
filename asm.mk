##
## asm.mk for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Thu Mar  3 09:59:21 2016 antoine
## Last update Thu Mar  3 09:59:21 2016 antoine
##

ASM_SOURCES_NAMES	= \
			instr.c \
			instr_list.c \
			label.c \
			label_list.c \
			lexer.c \
			syntax_error.c \
			token.c \
			token_has_value.c \
			token_list.c \
			token_list_to_string.c \
			token_to_string.c \
			token_type.c

ASM_SOURCES		= $(foreach file,$(ASM_SOURCES_NAMES), \
			asm/$(file))

ASM_OBJECTS		= $(ASM_SOURCES:.c=.o)
