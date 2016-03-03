##
## Makefile for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Mon Feb 22 23:56:42 2016 antoine
## Last update Mon Feb 22 23:56:42 2016 antoine
##

include libcw.mk

include asm.mk
include vm.mk
include test.mk

DELIVERY	= false

CC		= cc

RM		= rm -f

CFLAGS		= -W -Wall -Wextra -std=c89

ifeq ($(DELIVERY),true)
	CFLAGS	+= -D NDEBUG
else
	CFLAGS	+= -g
endif

LDFLAGS		=

LIBCW_NAME	= libcw.a
LIBCW		= src/libcw/$(LIBCW_NAME)

LIBASM_NAME	= libasm.a
LIBASM		= src/asm/$(LIBASM_NAME)

LIBVM_NAME	= libvm.a
LIBVM		= src/vm/$(LIBVM_NAME)

ECHO		= /bin/echo -e

RED		= "\033[0;91m"
GREEN		= "\033[0;92m"
END		= "\033[0m"

echo_error	= $(ECHO) $(RED) $(1) "[ERROR]" $(END)


all: test asm vm

asm: src/asm/main.o $(LIBASM) $(LIBCW)
	$(CC) -o $@ $^ $(LDFLAGS)

vm: src/vm/main.o $(LIBVM) $(LIBCW)
	$(CC) -o $@ $^ $(LDFLAGS)

test: $(TEST_OBJECTS) $(LIBASM) $(LIBCW)
	$(CC) -o $@ $^ $(LDFLAGS)

$(LIBCW): $(LIBCW_OBJECTS)
	ar rc $@ $^
	ranlib $@

$(LIBASM): $(ASM_OBJECTS)
	ar rc $@ $^
	ranlib $@

$(LIBVM): $(VM_OBJECTS)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS) && \
		$(ECHO) CC $< || \
		$(call echo_error,$<)

clean:
	$(RM) $(LIBCW_OBJECTS) src/libcw/libcw.a
	$(RM) $(ASM_OBJECTS) src/asm/libasm.a src/asm/main.o
	$(RM) $(VM_OBJECTS) src/vm/libvm.a src/vm/main.o
	$(RM) $(TEST_OBJECTS)
	$(RM) $(LIBASM) $(LIBCW) $(LIBVM)

fclean: clean
	$(RM) test
	$(RM) asm
	$(RM) vm
	$(RM) corewar

re: fclean all

.PHONY: all clean fclean re
