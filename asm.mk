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
			argument.c \
			compile.c \
			instr.c \
			instr_list.c \
			instr_size.c \
			instr_write.c \
			label.c \
			label_list.c \
			lexer.c \
			parse_arg.c \
			parse_instr.c \
			parse_line.c \
			path.c \
			program.c \
			program_instr.c \
			program_link.c \
			program_write.c \
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
