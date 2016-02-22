##
## Makefile for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Mon Feb 22 23:56:42 2016 antoine
## Last update Mon Feb 22 23:56:42 2016 antoine
##

export CC		= cc

export RM		= rm -f

export CFLAGS		= -W -Wall -Wextra -std=c89

export LIBCW_NAME	= libcw.a

LDFLAGS			=

NAME			= $(LIBCW_NAME)

SOURCES			= argparser.c

OBJECTS			= $(SOURCES:.c=.o)


all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTS): $(SOURCES)
	$(CC) -c $(SOURCES) $(CFLAGS)

test: all
	$(MAKE) -C test/ all

clean:
	$(RM) $(OBJECTS)
	$(MAKE) -C test/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C test/ fclean

re: fclean all

.PHONY: all clean fclean re
