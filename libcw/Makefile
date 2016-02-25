##
## Makefile<libcw> for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Tue Feb 23 06:33:08 2016 antoine
## Last update Thu Feb 25 17:12:45 2016 Jamy Bailly
##

NAME		= $(LIBCW_NAME)

CFLAGS		+= -I..

LDFLAGS		= -L.. -lcw

SOURCES		= argparser.c \
		char_type.c \
		char_type_convert.c \
		parse_int.c \
		parse_and_read_int.c \
		parse_and_read_int_base.c \
		print_string.c \
		print_int.c \
		string_find_char.c \
		string_find.c

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
