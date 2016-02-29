##
## Makefile<src> for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Mon Feb 29 11:11:48 2016 antoine
## Last update Mon Feb 29 11:11:48 2016 antoine
##

CFLAGS		+=

LDFLAGS		= -L../libcw -lcw

OBJECTS		= $(SOURCES:.c=.o)


all: build_asm build_vm

build_asm: build_libcw
	@$(MAKE) -C asm/ all && \
		$(ECHO) $(GREEN) "asm [OK]" $(END) || \
		$(ECHO) $(RED) "asm [ERROR]" $(END)

build_libcw:
	@$(MAKE) -C libcw/ all && \
		$(ECHO) $(GREEN) "libcw [OK]" $(END) || \
		$(ECHO) $(RED) "libcw [ERROR]" $(END)

build_test:
	@$(MAKE) -C test/ all && \
		$(ECHO) $(GREEN) "test [OK]" $(END) || \
		$(ECHO) $(RED) "test [ERROR]" $(END)

build_vm:

clean:
	@$(MAKE) -C libcw/ $@
	@$(MAKE) -C asm/ $@
	@$(MAKE) -C test/ $@

fclean:
	@$(MAKE) -C libcw/ $@
	@$(MAKE) -C asm/ $@
	@$(MAKE) -C test/ $@

re: fclean all

.PHONY: all clean fclean re
