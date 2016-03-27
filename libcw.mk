##
## libcw.mk for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Wed Mar  2 21:35:00 2016 antoine
## Last update Thu Mar 24 17:46:00 2016 Valentin Pichard
##

LIBCW_SOURCES_NAMES = 	char_type.c \
			char_type_convert.c \
			cor_file.c \
			cor_file_read.c \
			cor_file_write.c \
			instr.c \
			instr_0.c \
			instr_1.c \
			instr_2.c \
			instr_3.c \
			int_to_malloced_string.c \
			int_to_string.c \
			int_to_string_get_length.c \
			memory.c \
			parse_int.c \
			parse_and_read_int.c \
			parse_and_read_int_base.c \
			position.c \
			print_string.c \
			print_int.c \
			print_char.c \
			position.c \
			source_file.c \
			string.c \
			string_concat.c \
			string_copy.c \
			string_equals.c \
			string_find_char.c \
			string_find.c \
			string_reader.c \
			string_starts_with.c \
			string_type.c \
			string_type_convert.c \
			cor_file_read_int.c \

LIBCW_SOURCES		= $(foreach file,$(LIBCW_SOURCES_NAMES), \
			libcw/$(file))

LIBCW_OBJECTS		= $(LIBCW_SOURCES:.c=.o)
