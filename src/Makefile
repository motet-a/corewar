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

echo_ok		= $(ECHO) $(GREEN) $(1) "[OK]" $(END) "\n"
echo_error	= $(ECHO) $(RED) $(1) "[ERROR]" $(END) "\n"


all: ../asm ../corewar

libcw/libcw.a:
	@$(MAKE) -C libcw/ all && \
		$(call echo_ok,"libcw.a") || \
		$(call echo_error,"libcw.a")

../asm: libcw/libcw.a
	@$(MAKE) -C asm/ all && \
		$(call echo_ok,"asm") || \
		$(call echo_error,"asm")

../corewar: libcw/libcw.a
	@$(MAKE) -C vm/ all && \
		$(call echo_ok,"vm") || \
		$(call echo_error,"vm")

test: ../asm ../corewar libcw/libcw.a
	@$(MAKE) -C test/ all && \
		$(call echo_ok,"test") || \
		$(call echo_error,"test")

clean:
	@$(MAKE) -C libcw/ $@
	@$(MAKE) -C asm/ $@
	@$(MAKE) -C vm/ $@
	@$(MAKE) -C test/ $@

fclean:
	@$(MAKE) -C libcw/ $@
	@$(MAKE) -C asm/ $@
	@$(MAKE) -C vm/ $@
	@$(MAKE) -C test/ $@

re: fclean all

.PHONY: all clean fclean re
