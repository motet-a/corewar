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

export CFLAGS		= -W -Wall -Wextra -std=c89 -g # -D NDEBUG

export LIBCW_NAME	= libcw.a

export ECHO		= /bin/echo -e

#export MAKE		+= --no-print-directory

export RED		= "\033[0;31m"
export GREEN		= "\033[0;32m"
export END		= "\033[0m"

all:
	@$(MAKE) -C src/ $@

test: all
	@$(MAKE) -C src/ build_test

clean:
	@$(MAKE) -C src/ $@

fclean:
	@$(MAKE) -C src/ $@

re: fclean all

.PHONY: all clean fclean re
