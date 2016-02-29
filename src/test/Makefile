##
## Makefile<test> for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Tue Feb 23 00:03:21 2016 antoine
## Last update Tue Feb 23 00:03:21 2016 antoine
##

NAME		= ../../test

CFLAGS		+=

LDFLAGS		= -L../libcw -lcw \
		  -L../asm -lasm

SOURCES		= test.c \
		test_memory.c \
		test_parse_int.c \
		test_string_find.c \
		test_string_find_char.c \
		test_token_list.c

OBJECTS		= $(SOURCES:.c=.o)


all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(LDFLAGS)

$(OBJECTS): $(SOURCES)
	$(CC) -c $(SOURCES) $(CFLAGS)

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
