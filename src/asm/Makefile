##
## Makefile for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Tue Feb 23 00:03:21 2016 antoine
## Last update Tue Feb 23 00:03:21 2016 antoine
##

NAME		= ../../asm

CFLAGS		+=

LDFLAGS		= -L../libcw -lcw

SOURCES		= main.c

OBJECTS		= $(SOURCES:.c=.o)


all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(LDFLAGS)

$(OBJECTS): $(SOURCES)
	$(CC) -c $(SOURCES) $(CFLAGS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
