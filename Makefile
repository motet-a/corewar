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

ECHO			=	/bin/echo -e

RED			= "\033[0;31m"
GREEN		= "\033[0;32m"
END			= "\033[0m"

LIBCW_PATH		= libcw/$(LIBCW_NAME)


all: $(LIBCW_PATH)

$(LIBCW_PATH):
	@$(MAKE) -C libcw/ all && \
	 $(ECHO) $(GREEN) "libcw [OK]" $(END) || \
	 $(ECHO) $(RED) "libcw [ERROR]" $(END)

test: all
	$(MAKE) -C test/ all && \
	 $(ECHO) $(GREEN) "unit tests [OK]" $(END) || \
	 $(ECHO) $(RED) "unit tests [ERROR]" $(END)

clean:
	$(MAKE) -C test/ clean
	$(MAKE) -C libcw/ clean

fclean: clean
	$(MAKE) -C test/ fclean
	$(MAKE) -C libcw/ fclean

re: fclean all

.PHONY: all clean fclean re
