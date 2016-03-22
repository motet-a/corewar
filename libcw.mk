##
## libcw.mk for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Wed Mar  2 21:35:00 2016 antoine
## Last update Wed Mar  9 02:10:28 2016 Valentin Pichard
##

LIBCW_SOURCES_NAMES = 	char_type.c \
			char_type_convert.c \
			cor_file.c \
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
			string_type_convert.c

LIBCW_SOURCES		= $(foreach file,$(LIBCW_SOURCES_NAMES), \
			src/libcw/$(file))

LIBCW_OBJECTS		= $(LIBCW_SOURCES:.c=.o)
