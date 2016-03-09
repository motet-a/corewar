##
## test.mk for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Thu Mar  3 10:39:22 2016 antoine
## Last update Wed Mar  9 19:06:35 2016 Valentin Pichard
##

TEST_SOURCES_NAMES	= test.c \
			test_int_to_string.c \
			test_memory.c \
			test_parse_int.c \
			test_string_concat.c \
			test_string_find.c \
			test_string_find_char.c \
			test_string_type.c \
			test_string_type_convert.c \
			test_token_list.c \
			test_string_type_extend.c


TEST_SOURCES		= $(foreach file,$(TEST_SOURCES_NAMES), \
			src/test/$(file))

TEST_OBJECTS		= $(TEST_SOURCES:.c=.o)
