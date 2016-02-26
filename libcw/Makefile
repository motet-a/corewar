##
## Makefile<libcw> for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Tue Feb 23 06:33:08 2016 antoine
## Last update Fri Feb 26 16:33:29 2016 Jamy Bailly
##

NAME		= $(LIBCW_NAME)

CFLAGS		+= -I..

LDFLAGS		= -L.. -lcw

SOURCES		= char_type.c \
		char_type_convert.c \
		memory.c \
		parse_int.c \
		parse_and_read_int.c \
		parse_and_read_int_base.c \
		print_string.c \
		print_int.c \
		print_char.c \
		source_file.c \
		str.c \
		string_concat.c \
		string_equals.c \
		string_find_char.c \
		string_find.c \
		string_starts_with.c

OBJECTS		= $(SOURCES:.c=.o)


all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTS): $(SOURCES)
	$(CC) -c $(SOURCES) $(CFLAGS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
