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

LIBASM		= libasm.a

CFLAGS		+=

LDFLAGS		= -L../libcw -lcw -L. -lasm

SOURCES		= token.c token_list.c token_type.c

OBJECTS		= $(SOURCES:.c=.o)


all: $(NAME)

$(NAME): $(LIBASM) main.o
	$(CC) -o $(NAME) main.o $(LDFLAGS)

$(LIBASM): $(OBJECTS)
	@echo "ar"
	@ar rc $(LIBASM) $(OBJECTS)
	@echo "ranlib"
	@ranlib $(LIBASM)

$(OBJECTS): $(SOURCES)
	$(CC) -c $(SOURCES) $(CFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

clean:
	@$(RM) $(OBJECTS) main.o
	@$(RM) $(LIBASM)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
