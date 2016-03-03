##
## libcw.mk for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Wed Mar  2 21:35:00 2016 antoine
## Last update Wed Mar  2 21:35:00 2016 antoine
##

LIBCW_SOURCES_NAMES = 	char_type.c \
			char_type_convert.c \
			memory.c \
			parse_int.c \
			parse_and_read_int.c \
			parse_and_read_int_base.c \
			print_string.c \
			print_int.c \
			print_char.c \
			source_file.c \
			string.c \
			string_concat.c \
			string_copy.c \
			string_equals.c \
			string_find_char.c \
			string_find.c \
			string_starts_with.c

LIBCW_SOURCES		= $(foreach file,$(LIBCW_SOURCES_NAMES), \
			src/libcw/$(file))

LIBCW_OBJECTS		= $(LIBCW_SOURCES:.c=.o)
