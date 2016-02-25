##
## Makefile<libcw> for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Tue Feb 23 06:33:08 2016 antoine
## Last update Tue Feb 23 06:33:08 2016 antoine
##

NAME		= $(LIBCW_NAME)

CFLAGS		+= -I..

LDFLAGS		= -L.. -lcw

SOURCES		= argparser.c print_string.c parse_int.c

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
